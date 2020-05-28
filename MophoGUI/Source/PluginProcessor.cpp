#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() : 
    AudioProcessor(BusesProperties()),
    nrpnOutputIsAllowed{ true }
{
    publicParams.reset(new PublicParameters(valueConverters.get()));

    apvts.reset(new AudioProcessorValueTreeState(*this, nullptr, ID::publicParams, publicParams->createLayout()));

    for (auto* param : getParameters()) param->addListener(this);

    privateParams.reset(new PrivateParameters());

    valueConverters.reset(new ValueConverters());

    sendGlobalParametersDumpRequest();
}

PluginProcessor::~PluginProcessor()
{
    valueConverters = nullptr;
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
                if (sysExData[1] == 1 && sysExData[2] == 37)
                {
                    // save incoming program data dumps to the plugin
                    // storage bank and slot specified in the dump
                    if (sysExData[3] == 2)
                    {
                        auto bank = sysExData[4];
                        auto pgmSlot = sysExData[5];
                        uint8 programData[293]{};
                        for (auto j = 0; j != 293; ++j)
                            programData[j] = sysExData[j + 6];
                        privateParams->setProgramDataString(programData, bank, pgmSlot);
                    }

                    // apply incoming program edit buffer
                    // data dumps to the plugin's GUI
                    if (sysExData[3] == 3)
                    {
                        applyProgramDataToPlugin(sysExData + 4);
                    }

                    // apply incoming global parameter
                    // data dumps to the plugin's globalOptionsTree
                    if (sysExData[3] == 15)
                    {
                        applyGlobalParameterDataToPlugin(sysExData + 4);
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
    return new PluginEditor(*this, apvts.get(), privateParams.get(), valueConverters.get());
}

//==============================================================================
void PluginProcessor::getStateInformation(MemoryBlock& /*destData*/)
{
}

void PluginProcessor::setStateInformation(const void* /*data*/, int /*sizeInBytes*/)
{
}

//==============================================================================
void PluginProcessor::parameterValueChanged(int parameterIndex, float newValue)
{
    if (nrpnOutputIsAllowed)
    {
        auto nrpnIndex{ hardwareParameters[parameterIndex].nrpn };
        if (nrpnIndex > -1)
        {
            auto outputValue{ roundToInt(newValue * (hardwareParameters[parameterIndex].numberOfSteps - 1)) };

            if (parameterIndex > 104 && parameterIndex < 109) // knob assignment
                if (outputValue > 104) outputValue += 15; // offset to account for unassignable Mopho parameters 105..119

            if (parameterIndex == 95) outputValue += 30; // clock tempo parameter range is offset by 30

            addNRPNmessagesToBuffer(nrpnIndex, outputValue);
        }

        // The arpeggiator (#98) and the sequencer (#100) cannot both be on
        if (parameterIndex == 98 && newValue == 1.0f && getParameters()[100]->getValue() != 0.0f)
            getParameters()[100]->setValueNotifyingHost(0.0f);
        if (parameterIndex == 100 && newValue == 1.0f && getParameters()[98]->getValue() != 0.0f)
            getParameters()[98]->setValueNotifyingHost(0.0f);
    }
    else return;
}

//==============================================================================

void PluginProcessor::addNRPNmessagesToBuffer(int paramIndex, int newValue)
{
    if (paramIndex == 386) // Send MIDI channel change messages out on all channels
    {
        for (auto i = 0; i != 16; ++i)
        {
            auto firstByte{ 176 + i };
            MidiMessage nrpnIndexMSB{ firstByte, 99, paramIndex / 128 };
            internalMidiBuf.addEvent(nrpnIndexMSB, 0);
            MidiMessage nrpnIndexLSB{ firstByte, 98, paramIndex % 128 };
            internalMidiBuf.addEvent(nrpnIndexLSB, 0);
            MidiMessage nrpnValueMSB{ firstByte, 6, newValue / 128 };
            internalMidiBuf.addEvent(nrpnValueMSB, 0);
            MidiMessage nrpnValueLSB{ firstByte, 38, newValue % 128 };
            internalMidiBuf.addEvent(nrpnValueLSB, 0);
        }
    }
    else
    {
        auto midiChannel{ (int)privateParams->getGlobalOptionsProperty(ID::midiChannel) };
        if (midiChannel > 0) midiChannel -= 1;
        auto firstByte{ 176 + midiChannel };
        MidiMessage nrpnIndexMSB{ firstByte, 99, paramIndex / 128 };
        internalMidiBuf.addEvent(nrpnIndexMSB, 0);
        MidiMessage nrpnIndexLSB{ firstByte, 98, paramIndex % 128 };
        internalMidiBuf.addEvent(nrpnIndexLSB, 0);
        MidiMessage nrpnValueMSB{ firstByte, 6, newValue / 128 };
        internalMidiBuf.addEvent(nrpnValueMSB, 0);
        MidiMessage nrpnValueLSB{ firstByte, 38, newValue % 128 };
        internalMidiBuf.addEvent(nrpnValueLSB, 0);
    }
}

void PluginProcessor::sendPgmEditBufferDumpRequest()
{
    const char sysExData[]{ 1, 37, 6 };
    internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
}

void PluginProcessor::sendPgmEditBufferDump()
{
    uint8 sysExData[296]{};

    sysExData[0] = 1;    // DSI manufacturer ID
    sysExData[1] = 37;   // Mopho device ID
    sysExData[2] = 3;    // dump type ID (to edit buffer)

    addParamDataToBuffer(sysExData, 3);

    internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
}

void PluginProcessor::sendProgramDumpRequest(int bank, int pgmSlot)
{
    if (bank > -1 && bank < 3 && pgmSlot > -1 && pgmSlot < 128)
    {
        const char sysExData[]{ 1, 37, 5, (char)bank, (char)pgmSlot };
        internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
    }
}

void PluginProcessor::sendProgramDump(int bank, int pgmSlot)
{
    uint8 sysExData[298]{};

    sysExData[0] = 1;               // DSI manufacturer ID
    sysExData[1] = 37;              // Mopho device ID
    sysExData[2] = 2;               // dump type ID (to storage slot)
    sysExData[3] = (char)bank;      // bank number (0..2)
    sysExData[4] = (char)pgmSlot;   // bank number (0..127)

    auto programData{ privateParams->getProgramDataFromStorageString(bank, pgmSlot) };
    for (auto i = 0; i != 293; ++i)
        sysExData[i + 5] = programData[i];

    internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
}

void PluginProcessor::loadProgramFromStorage(int bank, int pgmSlot)
{
    auto programData{ privateParams->getProgramDataFromStorageString(bank, pgmSlot) };
    if (programData != nullptr)
    {
        applyProgramDataToPlugin(programData);
        callAfterDelay(100, [this] { sendPgmEditBufferDump(); });
    }
}

void PluginProcessor::saveProgramToStorage(int bank, int pgmSlot)
{
    uint8 programData[293]{};

    addParamDataToBuffer(programData, 0);

    privateParams->setProgramDataString(programData, bank, pgmSlot);
}

void PluginProcessor::pushProgramToHardwareStorage(int bank, int pgmSlot)
{
    if (bank > -1 && bank < 3 && pgmSlot > -1 && pgmSlot < 128)
        sendProgramDump(bank, pgmSlot);
}

void PluginProcessor::pullProgramFromHardwareStorage(int bank, int pgmSlot)
{
    if (bank > -1 && bank < 3 && pgmSlot > -1 && pgmSlot < 128)
        sendProgramDumpRequest(bank, pgmSlot);
}

//==============================================================================
void PluginProcessor::sendGlobalParametersDumpRequest()
{
    const char sysExData[]{ 1, 37, 14 };
    internalMidiBuf.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
}

//==============================================================================
void PluginProcessor::updateProgramName(String newName)
{
    programName = newName;
    nameCharCounter = 0;
    MultiTimer::startTimer(programNameTimer, pgmNameTimerInterval);
}

void PluginProcessor::clearSequencerTrack(int trackNum)
{
    if (trackNum > 0 && trackNum < 5)
    {
        switch (trackNum)
        {
        case 1: track1StepCounter = 0; MultiTimer::startTimer(sequencerTrack1StepTimer, sequencerStepTimerInterval); break;
        case 2: track2StepCounter = 0; MultiTimer::startTimer(sequencerTrack2StepTimer, sequencerStepTimerInterval); break;
        case 3: track3StepCounter = 0; MultiTimer::startTimer(sequencerTrack3StepTimer, sequencerStepTimerInterval); break;
        case 4: track4StepCounter = 0; MultiTimer::startTimer(sequencerTrack4StepTimer, sequencerStepTimerInterval); break;
        default: break;
        }
    }
}

void PluginProcessor::timerCallback(int timerID)
{
    MultiTimer::stopTimer(timerID);

    if (timerID == programNameTimer)
    {
        if (nameCharCounter > -1 && nameCharCounter < 16)
        {
            auto normalizedValue{ 0.007874f * (char)programName[nameCharCounter] }; // convert 0..127 to normalized value
            auto param{ getParameters()[184 + nameCharCounter] }; // program name character parameters start at index 184
            param->setValueNotifyingHost(normalizedValue);
            if (nameCharCounter < 16) { ++nameCharCounter; MultiTimer::startTimer(programNameTimer, pgmNameTimerInterval); }
            else nameCharCounter = 0;
        }
    }

    if (timerID == sequencerTrack1StepTimer)
    {
        if (track1StepCounter > -1 && track1StepCounter < 16)
        {
            auto param{ getParameters()[120 + track1StepCounter] }; // sequencer track 1 parameters start at index 120
            param->setValueNotifyingHost(1.0f); // set all steps to 'rest'
            if (track1StepCounter < 16) { ++track1StepCounter; MultiTimer::startTimer(sequencerTrack1StepTimer, sequencerStepTimerInterval); }
            else track1StepCounter = 0;
        }
    }

    if (timerID == sequencerTrack2StepTimer)
    {
        if (track2StepCounter > -1 && track2StepCounter < 16)
        {
            auto param{ getParameters()[136 + track2StepCounter] }; // sequencer track 2 parameters start at index 136
            param->setValueNotifyingHost(0.0f); // set all steps to 0
            if (track2StepCounter < 16) { ++track2StepCounter; MultiTimer::startTimer(sequencerTrack2StepTimer, sequencerStepTimerInterval); }
            else track2StepCounter = 0;
        }
    }

    if (timerID == sequencerTrack3StepTimer)
    {
        if (track3StepCounter > -1 && track3StepCounter < 16)
        {
            auto param{ getParameters()[152 + track3StepCounter] }; // sequencer track 3 parameters start at index 152
            param->setValueNotifyingHost(0.0f); // set all steps to 0
            if (track3StepCounter < 16) { ++track3StepCounter; MultiTimer::startTimer(sequencerTrack3StepTimer, sequencerStepTimerInterval); }
            else track3StepCounter = 0;
        }
    }

    if (timerID == sequencerTrack4StepTimer)
    {
        if (track4StepCounter > -1 && track4StepCounter < 16)
        {
            auto param{ getParameters()[168 + track4StepCounter] }; // sequencer track 4 parameters start at index 168
            param->setValueNotifyingHost(0.0f); // set all steps to 0
            if (track4StepCounter < 16) { ++track4StepCounter; MultiTimer::startTimer(sequencerTrack4StepTimer, sequencerStepTimerInterval); }
            else track4StepCounter = 0;
        }
    }
}

//==============================================================================

void PluginProcessor::applyProgramDataToPlugin(const uint8* dumpData)
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
    callAfterDelay(100, [this] { nrpnOutputIsAllowed = true; });
}

void PluginProcessor::addParamDataToBuffer(uint8* buffer, int offset)
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

void PluginProcessor::applyGlobalParameterDataToPlugin(const uint8* dumpData)
{
    // prevent NRPN messages from being sent back to
    // the Mopho while the parameters are being updated
    nrpnOutputIsAllowed = false;

    auto masterTranspose{ (int)dumpData[0] + (dumpData[1] * 16) };
    privateParams->setGlobalOptionsProperty(ID::masterTranspose, masterTranspose);

    auto masterFineTune{ (int)dumpData[2] + (dumpData[3] * 16) };
    privateParams->setGlobalOptionsProperty(ID::masterFineTune, masterFineTune);

    auto midiChannel{ (int)dumpData[4] + (dumpData[5] * 16) };
    privateParams->setGlobalOptionsProperty(ID::midiChannel, midiChannel);

    auto midiClock{ (int)dumpData[6] };
    privateParams->setGlobalOptionsProperty(ID::midiClock, midiClock);

    auto parameterSend{ (int)dumpData[8] };
    privateParams->setGlobalOptionsProperty(ID::parameterSend, parameterSend);

    auto parameterReceive{ (int)dumpData[10] };
    privateParams->setGlobalOptionsProperty(ID::parameterReceive, parameterReceive);

    auto midiControllers{ (bool)dumpData[12] };
    privateParams->setGlobalOptionsProperty(ID::midiControllers, midiControllers);

    // Since this plugin depends on SysEx to communicate with the hardware,
    // the option for turning SysEx send/receive off is not included

    auto stereoAudioOut{ (bool)dumpData[16] };
    privateParams->setGlobalOptionsProperty(ID::stereoAudioOut, stereoAudioOut);

    auto midiThru{ (bool)dumpData[18] };
    privateParams->setGlobalOptionsProperty(ID::midiThru, midiThru);

    // resume sending NRPN messages to the Mopho when parameters change
    callAfterDelay(100, [this] { nrpnOutputIsAllowed = true; });
}

//==============================================================================

// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
