#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() : 
    AudioProcessor(BusesProperties()),
    nrpnOutputIsAllowed{ true }
{
    publicParams.reset(new PublicParameters());

    apvts.reset(new AudioProcessorValueTreeState(*this, nullptr, ID::publicParams, publicParams->createLayout()));

    for (auto* param : getParameters()) param->addListener(this);

    privateParams.reset(new PrivateParameters());
}

PluginProcessor::~PluginProcessor()
{
    privateParams = nullptr;
    apvts = nullptr;
    publicParams = nullptr;
}

//==============================================================================
void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();
    // handle incoming MIDI messages
    if (!midiMessages.isEmpty())
    {
        int time;
        MidiMessage m;

        for (MidiBuffer::Iterator i(midiMessages); i.getNextEvent(m, time);)
        {
            if (m.isSysEx())
            {
                auto sysExData{ m.getSysExData() };

                // The first two bytes of SysEx messages from the Mopho
                // are the DSI ID# (1) and the Mopho device ID# (37)
                if (*(sysExData + 1) == 1 && *(sysExData + 2) == 37)
                {
                    // handle incoming program edit buffer data dumps
                    if (*(sysExData + 3) == 3)
                    {
                        applyPgmDumpDataToPlugin(sysExData + 4);
                    }
                }
            }
        }
    }

    // add internally generated MIDI messages to midiMessages
    if (!internalMidiBuf.isEmpty())
    {
        int time;
        MidiMessage m;

        for (MidiBuffer::Iterator i(internalMidiBuf); i.getNextEvent(m, time);)
        {
            midiMessages.addEvent(m, time);
        }

        internalMidiBuf.clear();
    }
}

//==============================================================================
AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor(*this, apvts.get(), privateParams.get());
}

//==============================================================================
void PluginProcessor::getStateInformation(MemoryBlock& destData)
{
    ignoreUnused(destData);
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    ignoreUnused(data, sizeInBytes);
}

//==============================================================================
void PluginProcessor::parameterValueChanged(int parameterIndex, float newValue)
{
    if (nrpnOutputIsAllowed)
    {
        auto numSteps{ getParameters()[parameterIndex]->getNumSteps() };
        auto nrpnIndex{ publicParams->getNRPN(parameterIndex) };
        if (nrpnIndex > -1)
        {
            auto outputValue{ roundToInt(newValue * (numSteps - 1)) };

            if (parameterIndex > 104 && parameterIndex < 109) // knob assignment
                if (outputValue > 104) outputValue += 15; // offset to account for unassignable Mopho parameters 105..119

            if (parameterIndex == 95) outputValue += 30; // clock tempo parameter range is offset by 30

            internalMidiBuf = MidiRPNGenerator::generate(1, nrpnIndex, outputValue, true, true);
        }

        // The arpeggiator (#98) and the sequencer (#100) cannot both be on
        if (parameterIndex == 98 && newValue == 1.0f)
            getParameters()[100]->setValueNotifyingHost(0.0f);
        if (parameterIndex == 100 && newValue == 1.0f)
            getParameters()[98]->setValueNotifyingHost(0.0f);
    }
}

//==============================================================================
void PluginProcessor::sendPgmEditBufferDumpRequest()
{
    const char sysExData[]{ 1, 37, 6 };
    internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
}

void PluginProcessor::sendDumpToEditBuffer()
{
    uint8 sysExData[296]{};

    *(sysExData)       = 1;    // DSI manufacturer ID
    *(sysExData + 1)   = 37;   // Mopho device ID
    *(sysExData + 2)   = 3;    // dump type ID (to edit buffer)

    addParamDataToDumpBuffer(sysExData, 3);

    internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
}

void PluginProcessor::sendDumpToStorageSlot(int bank, int pgmSlot)
{
}

void PluginProcessor::applyPgmDumpDataToPlugin(const uint8* dumpData)
{
    // prevent NRPN messages from being sent back to
    // the Mopho while the parameters are being updated
    nrpnOutputIsAllowed = false;

    // To allow for parameters with value ranges beyond MIDI's 7-bit limit (127),
    // the program data dump is organized into 36 8-byte packets:
    // Bytes 2 through 7 in each packet hold the LSB values for 7 parameters,
    // The first byte in the packet holds the MS bits for those 7 parameters
    for (int paramIndex = 0; paramIndex != 200; ++paramIndex)
    {
        if (paramIndex < 109 || paramIndex > 119) // skip unassigned parameter numbers
        {
            // Index of the data byte that holds the MS bit for the parameter's value
            auto msbIndex{ (paramIndex / 7) * 8 };

            auto offset{ paramIndex % 7 + 1 };

            // Extract the MS bit value for the parameter (0 or 1)
            int bitMask{ roundToInt(pow(2, offset - 1)) };
            auto msbitValue{ *(dumpData + msbIndex) & bitMask };

            // Index of the data byte that contains the parameter's LSB value
            auto lsbIndex{ msbIndex + offset };
            
            auto newParamValue{ *(dumpData + lsbIndex) + (msbitValue > 0 ? 128 : 0) };
            auto param{ getParameters()[paramIndex] };
            param->setValueNotifyingHost((1.0f / (param->getNumSteps() - 1)) * newParamValue);
        }
    }

    // resume sending NRPN messages to the Mopho when parameters change
    nrpnOutputIsAllowed = true;
}

void PluginProcessor::addParamDataToDumpBuffer(uint8* buffer, int offset)
{
    nrpnOutputIsAllowed = false;

    for (int paramIndex = 0; paramIndex != 200; ++paramIndex)
    {
        if (paramIndex < 109 || paramIndex > 119) // skip unassigned parameter numbers
        {
            auto param{ getParameters()[paramIndex] };
            auto paramValue{ roundToInt(param->getValue() * (param->getNumSteps() - 1)) };
            if (paramIndex == 95) paramValue += 30; // clock tempo parameter range is offset by 30

            // Index of the data byte that will hold the MS bit for the parameter's value
            auto msbIndex{ (paramIndex / 7) * 8 + offset };

            auto paramOffset{ paramIndex % 7 + 1 };

            // Index of the data byte that contains the parameter's LSB value
            auto lsbIndex{ msbIndex + paramOffset };

            // If a parameter has a value above 127, store its 8th bit 
            // in the MSB data byte for the packet the parameter is in
            if (paramValue > 127)
            {
                *(buffer + msbIndex) += (uint8)roundToInt(pow(2, paramOffset - 1));
            }

            // Store the LSB value of the parameter in the appropriate data byte
            *(buffer + lsbIndex) = paramValue % 128;
        }
    }

    nrpnOutputIsAllowed = true;
}

//==============================================================================
void PluginProcessor::updateProgramName(String newName)
{
    programName = newName;
    for (auto i = 0; i != 16; ++i)
    {
        auto parameterIndex{ 184 + i }; // program name character parameters start at index 184
        auto normalizedValue{ 0.007874f * (char)programName[i] }; // convert 0..127 to normalized value
        nrpnOutputIsAllowed = false;
        auto param{ getParameters()[parameterIndex] }; // program name character parameters start at index 184
        param->setValueNotifyingHost(normalizedValue);
        nrpnOutputIsAllowed = true;
        nameCharCounter = 0;
        startTimer(timerInterval);
    }
}

void PluginProcessor::timerCallback()
{
		stopTimer();
		switch (nameCharCounter)
		{
		case 0 : parameterValueChanged(184, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 1 : parameterValueChanged(185, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 2 : parameterValueChanged(186, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 3 : parameterValueChanged(187, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 4 : parameterValueChanged(188, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 5 : parameterValueChanged(189, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 6 : parameterValueChanged(190, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 7 : parameterValueChanged(191, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 8 : parameterValueChanged(192, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 9 : parameterValueChanged(193, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 10: parameterValueChanged(194, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 11: parameterValueChanged(195, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 12: parameterValueChanged(196, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 13: parameterValueChanged(197, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 14: parameterValueChanged(198, 0.007874f * (char)programName[nameCharCounter]); ++nameCharCounter; startTimer(timerInterval); break;
		case 15: parameterValueChanged(199, 0.007874f * (char)programName[nameCharCounter]); break;
		default:
			break;
		}
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
