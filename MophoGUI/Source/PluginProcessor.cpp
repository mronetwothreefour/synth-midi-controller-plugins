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
        auto numSteps{ getParameters()[parameterIndex]->getNumSteps() };
        auto nrpnIndex{ getNRPN(parameterIndex) };
        if (nrpnIndex > -1)
        {
            auto outputValue{ roundToInt(newValue * (numSteps - 1)) };

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

int PluginProcessor::getNRPN(int parameterIndex)
{
		switch (parameterIndex)
		{
		case MophoParameterIndex::osc1Pitch			: return MophoParameterNRPN::osc1Pitch			;	
		case MophoParameterIndex::osc1Fine			: return MophoParameterNRPN::osc1Fine			;	
		case MophoParameterIndex::osc1Shape			: return MophoParameterNRPN::osc1Shape			;	
		case MophoParameterIndex::osc1Glide			: return MophoParameterNRPN::osc1Glide			;
		case MophoParameterIndex::osc1KeyTrack		: return MophoParameterNRPN::osc1KeyTrack		;	
		case MophoParameterIndex::osc1SubLevel		: return MophoParameterNRPN::osc1SubLevel		;	
		case MophoParameterIndex::osc2Pitch			: return MophoParameterNRPN::osc2Pitch			;	
		case MophoParameterIndex::osc2Fine			: return MophoParameterNRPN::osc2Fine			;	
		case MophoParameterIndex::osc2Shape			: return MophoParameterNRPN::osc2Shape			;	
		case MophoParameterIndex::osc2Glide			: return MophoParameterNRPN::osc2Glide			;	
		case MophoParameterIndex::osc2KeyTrack		: return MophoParameterNRPN::osc2KeyTrack		;	
		case MophoParameterIndex::osc2SubLevel		: return MophoParameterNRPN::osc2SubLevel		;	
		case MophoParameterIndex::oscSync			: return MophoParameterNRPN::oscSync			;	
		case MophoParameterIndex::glideMode			: return MophoParameterNRPN::glideMode			;	
		case MophoParameterIndex::oscSlop			: return MophoParameterNRPN::oscSlop			;	
		case MophoParameterIndex::bendRange			: return MophoParameterNRPN::bendRange			;	
		case MophoParameterIndex::notePriority		: return MophoParameterNRPN::notePriority		;	
		case MophoParameterIndex::oscMix			: return MophoParameterNRPN::oscMix				;
		case MophoParameterIndex::noiseLevel		: return MophoParameterNRPN::noiseLevel			;
		case MophoParameterIndex::extInLevel		: return MophoParameterNRPN::extInLevel			;
		case MophoParameterIndex::lpfFreq			: return MophoParameterNRPN::lpfFreq			;	
		case MophoParameterIndex::lpfReso			: return MophoParameterNRPN::lpfReso			;	
		case MophoParameterIndex::lpfKeyAmount		: return MophoParameterNRPN::lpfKeyAmount		;	
		case MophoParameterIndex::lpfFMamount		: return MophoParameterNRPN::lpfFMamount		;	
		case MophoParameterIndex::lpfType			: return MophoParameterNRPN::lpfType			;	
		case MophoParameterIndex::lpfEnvAmount		: return MophoParameterNRPN::lpfEnvAmount		;	
		case MophoParameterIndex::lpfVelAmount		: return MophoParameterNRPN::lpfVelAmount		;	
		case MophoParameterIndex::lpfDelay			: return MophoParameterNRPN::lpfDelay			;	
		case MophoParameterIndex::lpfAttack			: return MophoParameterNRPN::lpfAttack			;	
		case MophoParameterIndex::lpfDecay			: return MophoParameterNRPN::lpfDecay			;	
		case MophoParameterIndex::lpfSustain		: return MophoParameterNRPN::lpfSustain			;
		case MophoParameterIndex::lpfRelease		: return MophoParameterNRPN::lpfRelease			;
		case MophoParameterIndex::vcaLevel			: return MophoParameterNRPN::vcaLevel			;	
		case MophoParameterIndex::vcaEnvAmount		: return MophoParameterNRPN::vcaEnvAmount		;	
		case MophoParameterIndex::vcaVelAmount		: return MophoParameterNRPN::vcaVelAmount		;	
		case MophoParameterIndex::vcaDelay			: return MophoParameterNRPN::vcaDelay			;	
		case MophoParameterIndex::vcaAttack			: return MophoParameterNRPN::vcaAttack			;	
		case MophoParameterIndex::vcaDecay			: return MophoParameterNRPN::vcaDecay			;	
		case MophoParameterIndex::vcaSustain		: return MophoParameterNRPN::vcaSustain			;
		case MophoParameterIndex::vcaRelease		: return MophoParameterNRPN::vcaRelease			;
		case MophoParameterIndex::pgmVolume			: return MophoParameterNRPN::pgmVolume			;	
		case MophoParameterIndex::lfo1Freq			: return MophoParameterNRPN::lfo1Freq			;	
		case MophoParameterIndex::lfo1Shape			: return MophoParameterNRPN::lfo1Shape			;	
		case MophoParameterIndex::lfo1Amount		: return MophoParameterNRPN::lfo1Amount			;
		case MophoParameterIndex::lfo1Destination	: return MophoParameterNRPN::lfo1Destination	;	
		case MophoParameterIndex::lfo1KeySync		: return MophoParameterNRPN::lfo1KeySync		;	
		case MophoParameterIndex::lfo2Freq			: return MophoParameterNRPN::lfo2Freq			;	
		case MophoParameterIndex::lfo2Shape			: return MophoParameterNRPN::lfo2Shape			;	
		case MophoParameterIndex::lfo2Amount		: return MophoParameterNRPN::lfo2Amount			;
		case MophoParameterIndex::lfo2Destination	: return MophoParameterNRPN::lfo2Destination	;	
		case MophoParameterIndex::lfo2KeySync		: return MophoParameterNRPN::lfo2KeySync		;	
		case MophoParameterIndex::lfo3Freq			: return MophoParameterNRPN::lfo3Freq			;	
		case MophoParameterIndex::lfo3Shape			: return MophoParameterNRPN::lfo3Shape			;	
		case MophoParameterIndex::lfo3Amount		: return MophoParameterNRPN::lfo3Amount			;
		case MophoParameterIndex::lfo3Destination	: return MophoParameterNRPN::lfo3Destination	;	
		case MophoParameterIndex::lfo3KeySync		: return MophoParameterNRPN::lfo3KeySync		;	
		case MophoParameterIndex::lfo4Freq			: return MophoParameterNRPN::lfo4Freq			;	
		case MophoParameterIndex::lfo4Shape			: return MophoParameterNRPN::lfo4Shape			;	
		case MophoParameterIndex::lfo4Amount		: return MophoParameterNRPN::lfo4Amount			;
		case MophoParameterIndex::lfo4Destination	: return MophoParameterNRPN::lfo4Destination	;	
		case MophoParameterIndex::lfo4KeySync		: return MophoParameterNRPN::lfo4KeySync		;	
		case MophoParameterIndex::env3Destination	: return MophoParameterNRPN::env3Destination	;	
		case MophoParameterIndex::env3Amount		: return MophoParameterNRPN::env3Amount			;
		case MophoParameterIndex::env3VelAmount		: return MophoParameterNRPN::env3VelAmount		;	
		case MophoParameterIndex::env3Delay			: return MophoParameterNRPN::env3Delay			;	
		case MophoParameterIndex::env3Attack		: return MophoParameterNRPN::env3Attack			;
		case MophoParameterIndex::env3Decay			: return MophoParameterNRPN::env3Decay			;	
		case MophoParameterIndex::env3Sustain		: return MophoParameterNRPN::env3Sustain		;	
		case MophoParameterIndex::env3Release		: return MophoParameterNRPN::env3Release		;	
		case MophoParameterIndex::env3Repeat		: return MophoParameterNRPN::env3Repeat			;
		case MophoParameterIndex::mod1Source		: return MophoParameterNRPN::mod1Source			;
		case MophoParameterIndex::mod1Amount		: return MophoParameterNRPN::mod1Amount			;
		case MophoParameterIndex::mod1Destination	: return MophoParameterNRPN::mod1Destination	;	
		case MophoParameterIndex::mod2Source		: return MophoParameterNRPN::mod2Source			;
		case MophoParameterIndex::mod2Amount		: return MophoParameterNRPN::mod2Amount			;
		case MophoParameterIndex::mod2Destination	: return MophoParameterNRPN::mod2Destination	;	
		case MophoParameterIndex::mod3Source		: return MophoParameterNRPN::mod3Source			;
		case MophoParameterIndex::mod3Amount		: return MophoParameterNRPN::mod3Amount			;
		case MophoParameterIndex::mod3Destination	: return MophoParameterNRPN::mod3Destination	;	
		case MophoParameterIndex::mod4Source		: return MophoParameterNRPN::mod4Source			;
		case MophoParameterIndex::mod4Amount		: return MophoParameterNRPN::mod4Amount			;
		case MophoParameterIndex::mod4Destination	: return MophoParameterNRPN::mod4Destination	;	
		case MophoParameterIndex::modWheelAmount	: return MophoParameterNRPN::modWheelAmount		;
		case MophoParameterIndex::modWheelDest		: return MophoParameterNRPN::modWheelDest		;	
		case MophoParameterIndex::aftertouchAmount	: return MophoParameterNRPN::aftertouchAmount	;	
		case MophoParameterIndex::aftertouchDest	: return MophoParameterNRPN::aftertouchDest		;
		case MophoParameterIndex::breathAmount		: return MophoParameterNRPN::breathAmount		;	
		case MophoParameterIndex::breathDest		: return MophoParameterNRPN::breathDest			;
		case MophoParameterIndex::velocityAmount	: return MophoParameterNRPN::velocityAmount		;
		case MophoParameterIndex::velocityDest		: return MophoParameterNRPN::velocityDest		;	
		case MophoParameterIndex::footPedalAmount	: return MophoParameterNRPN::footPedalAmount	;	
		case MophoParameterIndex::footPedalDest		: return MophoParameterNRPN::footPedalDest		;	
		case MophoParameterIndex::pushItPitch		: return MophoParameterNRPN::pushItPitch		;	
		case MophoParameterIndex::pushItVelocity	: return MophoParameterNRPN::pushItVelocity		;
		case MophoParameterIndex::pushItMode		: return MophoParameterNRPN::pushItMode			;
		case MophoParameterIndex::clockTempo		: return MophoParameterNRPN::clockTempo			;
		case MophoParameterIndex::clockDivide		: return MophoParameterNRPN::clockDivide		;	
		case MophoParameterIndex::arpegMode			: return MophoParameterNRPN::arpegMode			;	
		case MophoParameterIndex::arpegOnOff		: return MophoParameterNRPN::arpegOnOff			;
		case MophoParameterIndex::sequencerTrig		: return MophoParameterNRPN::sequencerTrig		;	
		case MophoParameterIndex::sequencerOnOff	: return MophoParameterNRPN::sequencerOnOff		;
		case MophoParameterIndex::track1Dest		: return MophoParameterNRPN::track1Dest			;
		case MophoParameterIndex::track2Dest		: return MophoParameterNRPN::track2Dest			;
		case MophoParameterIndex::track3Dest		: return MophoParameterNRPN::track3Dest			;
		case MophoParameterIndex::track4Dest		: return MophoParameterNRPN::track4Dest			;
		case MophoParameterIndex::assignKnob1		: return MophoParameterNRPN::assignKnob1		;	
		case MophoParameterIndex::assignKnob2		: return MophoParameterNRPN::assignKnob2		;	
		case MophoParameterIndex::assignKnob3		: return MophoParameterNRPN::assignKnob3		;	
		case MophoParameterIndex::assignKnob4		: return MophoParameterNRPN::assignKnob4		;	
		case MophoParameterIndex::track1Step1  		: return MophoParameterNRPN::track1Step1  		;	
		case MophoParameterIndex::track1Step2  		: return MophoParameterNRPN::track1Step2  		;	
		case MophoParameterIndex::track1Step3  		: return MophoParameterNRPN::track1Step3  		;	
		case MophoParameterIndex::track1Step4  		: return MophoParameterNRPN::track1Step4  		;	
		case MophoParameterIndex::track1Step5  		: return MophoParameterNRPN::track1Step5  		;	
		case MophoParameterIndex::track1Step6  		: return MophoParameterNRPN::track1Step6  		;	
		case MophoParameterIndex::track1Step7  		: return MophoParameterNRPN::track1Step7  		;	
		case MophoParameterIndex::track1Step8  		: return MophoParameterNRPN::track1Step8  		;	
		case MophoParameterIndex::track1Step9  		: return MophoParameterNRPN::track1Step9  		;	
		case MophoParameterIndex::track1Step10		: return MophoParameterNRPN::track1Step10		;	
		case MophoParameterIndex::track1Step11		: return MophoParameterNRPN::track1Step11		;	
		case MophoParameterIndex::track1Step12		: return MophoParameterNRPN::track1Step12		;	
		case MophoParameterIndex::track1Step13		: return MophoParameterNRPN::track1Step13		;	
		case MophoParameterIndex::track1Step14		: return MophoParameterNRPN::track1Step14		;	
		case MophoParameterIndex::track1Step15		: return MophoParameterNRPN::track1Step15		;	
		case MophoParameterIndex::track1Step16		: return MophoParameterNRPN::track1Step16		;	
		case MophoParameterIndex::track2Step1  		: return MophoParameterNRPN::track2Step1  		;	
		case MophoParameterIndex::track2Step2  		: return MophoParameterNRPN::track2Step2  		;	
		case MophoParameterIndex::track2Step3  		: return MophoParameterNRPN::track2Step3  		;	
		case MophoParameterIndex::track2Step4  		: return MophoParameterNRPN::track2Step4  		;	
		case MophoParameterIndex::track2Step5  		: return MophoParameterNRPN::track2Step5  		;	
		case MophoParameterIndex::track2Step6  		: return MophoParameterNRPN::track2Step6  		;	
		case MophoParameterIndex::track2Step7  		: return MophoParameterNRPN::track2Step7  		;	
		case MophoParameterIndex::track2Step8  		: return MophoParameterNRPN::track2Step8  		;	
		case MophoParameterIndex::track2Step9  		: return MophoParameterNRPN::track2Step9  		;	
		case MophoParameterIndex::track2Step10		: return MophoParameterNRPN::track2Step10		;	
		case MophoParameterIndex::track2Step11		: return MophoParameterNRPN::track2Step11		;	
		case MophoParameterIndex::track2Step12		: return MophoParameterNRPN::track2Step12		;	
		case MophoParameterIndex::track2Step13		: return MophoParameterNRPN::track2Step13		;	
		case MophoParameterIndex::track2Step14		: return MophoParameterNRPN::track2Step14		;	
		case MophoParameterIndex::track2Step15		: return MophoParameterNRPN::track2Step15		;	
		case MophoParameterIndex::track2Step16		: return MophoParameterNRPN::track2Step16		;	
		case MophoParameterIndex::track3Step1  		: return MophoParameterNRPN::track3Step1  		;	
		case MophoParameterIndex::track3Step2  		: return MophoParameterNRPN::track3Step2  		;	
		case MophoParameterIndex::track3Step3  		: return MophoParameterNRPN::track3Step3  		;	
		case MophoParameterIndex::track3Step4  		: return MophoParameterNRPN::track3Step4  		;	
		case MophoParameterIndex::track3Step5  		: return MophoParameterNRPN::track3Step5  		;	
		case MophoParameterIndex::track3Step6  		: return MophoParameterNRPN::track3Step6  		;	
		case MophoParameterIndex::track3Step7  		: return MophoParameterNRPN::track3Step7  		;	
		case MophoParameterIndex::track3Step8  		: return MophoParameterNRPN::track3Step8  		;	
		case MophoParameterIndex::track3Step9  		: return MophoParameterNRPN::track3Step9  		;	
		case MophoParameterIndex::track3Step10		: return MophoParameterNRPN::track3Step10		;	
		case MophoParameterIndex::track3Step11		: return MophoParameterNRPN::track3Step11		;	
		case MophoParameterIndex::track3Step12		: return MophoParameterNRPN::track3Step12		;	
		case MophoParameterIndex::track3Step13		: return MophoParameterNRPN::track3Step13		;	
		case MophoParameterIndex::track3Step14		: return MophoParameterNRPN::track3Step14		;	
		case MophoParameterIndex::track3Step15		: return MophoParameterNRPN::track3Step15		;	
		case MophoParameterIndex::track3Step16		: return MophoParameterNRPN::track3Step16		;	
		case MophoParameterIndex::track4Step1  		: return MophoParameterNRPN::track4Step1  		;	
		case MophoParameterIndex::track4Step2  		: return MophoParameterNRPN::track4Step2  		;	
		case MophoParameterIndex::track4Step3  		: return MophoParameterNRPN::track4Step3  		;	
		case MophoParameterIndex::track4Step4  		: return MophoParameterNRPN::track4Step4  		;	
		case MophoParameterIndex::track4Step5  		: return MophoParameterNRPN::track4Step5  		;	
		case MophoParameterIndex::track4Step6  		: return MophoParameterNRPN::track4Step6  		;	
		case MophoParameterIndex::track4Step7  		: return MophoParameterNRPN::track4Step7  		;	
		case MophoParameterIndex::track4Step8  		: return MophoParameterNRPN::track4Step8  		;	
		case MophoParameterIndex::track4Step9  		: return MophoParameterNRPN::track4Step9  		;	
		case MophoParameterIndex::track4Step10		: return MophoParameterNRPN::track4Step10		;	
		case MophoParameterIndex::track4Step11		: return MophoParameterNRPN::track4Step11		;	
		case MophoParameterIndex::track4Step12		: return MophoParameterNRPN::track4Step12		;	
		case MophoParameterIndex::track4Step13		: return MophoParameterNRPN::track4Step13		;	
		case MophoParameterIndex::track4Step14		: return MophoParameterNRPN::track4Step14		;	
		case MophoParameterIndex::track4Step15		: return MophoParameterNRPN::track4Step15		;	
		case MophoParameterIndex::track4Step16		: return MophoParameterNRPN::track4Step16		;	
		case MophoParameterIndex::nameChar1 		: return MophoParameterNRPN::nameChar1 			;
		case MophoParameterIndex::nameChar2 		: return MophoParameterNRPN::nameChar2 			;
		case MophoParameterIndex::nameChar3 		: return MophoParameterNRPN::nameChar3 			;
		case MophoParameterIndex::nameChar4 		: return MophoParameterNRPN::nameChar4 			;
		case MophoParameterIndex::nameChar5 		: return MophoParameterNRPN::nameChar5 			;
		case MophoParameterIndex::nameChar6 		: return MophoParameterNRPN::nameChar6 			;
		case MophoParameterIndex::nameChar7 		: return MophoParameterNRPN::nameChar7 			;
		case MophoParameterIndex::nameChar8 		: return MophoParameterNRPN::nameChar8 			;
		case MophoParameterIndex::nameChar9 		: return MophoParameterNRPN::nameChar9 			;
		case MophoParameterIndex::nameChar10		: return MophoParameterNRPN::nameChar10			;
		case MophoParameterIndex::nameChar11		: return MophoParameterNRPN::nameChar11			;
		case MophoParameterIndex::nameChar12		: return MophoParameterNRPN::nameChar12			;
		case MophoParameterIndex::nameChar13		: return MophoParameterNRPN::nameChar13			;
		case MophoParameterIndex::nameChar14		: return MophoParameterNRPN::nameChar14			;
		case MophoParameterIndex::nameChar15		: return MophoParameterNRPN::nameChar15			;
		case MophoParameterIndex::nameChar16		: return MophoParameterNRPN::nameChar16			;
		default: return -1;
		}
}

//==============================================================================

// This creates new instances of the plugin
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
