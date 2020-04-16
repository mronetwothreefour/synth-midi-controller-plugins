#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() : 
    AudioProcessor(BusesProperties()),
    outputIsAllowed{ true }
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
    if (outputIsAllowed)
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

void PluginProcessor::applyPgmDumpDataToPlugin(const uint8* dumpData)
{
    // prevent NRPN messages from being sent back to
    // the Mopho while the parameters are being updated
    outputIsAllowed = false;

    // To allow for parameters with value ranges beyond MIDI's 7-bit limit (127),
    // the program data dump is organized into 36 8-byte packets:
    // Bytes 2 through 7 in each packet hold the LSB values for 7 parameters,
    // The first byte in the packet holds the MS bits for those 7 parameters
    for (int paramNum = 0; paramNum != 200; ++paramNum)
    {
        if (paramNum < 109 || paramNum > 119) // skip unassigned parameter numbers
        {
            // Index of the data byte that holds the MS bit for the parameter
            auto msbByte{ (paramNum / 7) * 8 };

            auto offset{ paramNum % 7 + 1 };

            // associated LSB value byte (increases by one with each 8-byte packet)
            auto lsbByte{ msbByte + offset };
            
            int bitMask{ (int)pow(2, offset - 1) };

            // Extract the MS bit value for the parameter (0 or 1)
            auto msbitValue{ *(dumpData + msbByte) & bitMask };

            auto newParamValue{ *(dumpData + lsbByte) + (msbitValue > 0 ? 128 : 0) };
            auto param{ getParameters()[paramNum] };
            param->setValueNotifyingHost((1.0f / (param->getNumSteps() - 1)) * newParamValue);
        }
    }

    // resume sending NRPN messages to the Mopho when parameters change
    outputIsAllowed = true;
}

void PluginProcessor::createPgmDataDump()
{
}

void PluginProcessor::sendDumpToEditBuffer(const uint8* dumpData)
{
}

void PluginProcessor::sendDumpToStorageSlot(int bank, int pgmSlot, const uint8* dumpData)
{
}

//==============================================================================
// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
