#include "helper_MidiTools.h"



IncomingMidiHandler::IncomingMidiHandler(AudioProcessorValueTreeState* exposedParams) :
	exposedParams{ exposedParams }
{
}

IncomingMidiHandler::~IncomingMidiHandler() {
}

MidiBuffer IncomingMidiHandler::handle(const MidiBuffer& midiMessages) {
    MidiBuffer handledMidiMessages;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (SysExID::matchesTargetDevice(midiMessage))
            handleIncomingSysEx(midiMessage.getSysExData());
        else handledMidiMessages.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return handledMidiMessages;
}

void IncomingMidiHandler::handleIncomingSysEx(const uint8* sysExData) {
    if (sysExData[3] == (uint8)SysExMessageType::programEditBufferDump)
        RawProgramData::applyToExposedParameters(sysExData + 4, exposedParams);
}


//================================================================================


OutgoingMidiGenerator::OutgoingMidiGenerator(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers) :
	exposedParams{ exposedParams },
    internalMidiBuffers{ internalMidiBuffers },
    nameCharCounter{ 0 },
    track1StepCounter{ 0 },
    track2StepCounter{ 0 },
    track3StepCounter{ 0 },
    track4StepCounter{ 0 },
    millisecondsBtwnParamChanges{ 10 }
{
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->addParameterListener(info.IDfor(param), this);
}

OutgoingMidiGenerator::~OutgoingMidiGenerator() {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->removeParameterListener(info.IDfor(param), this);
}

void OutgoingMidiGenerator::sendProgramEditBufferDumpRequest() {
    const char sysExData[]{ (char)SysExID::TargetDevice::Manufacturer, (char)SysExID::TargetDevice::Device, (char)SysExMessageType::programEditBufferDumpRequest };
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
    combineMidiBuffers(localMidiBuffer);
}

void OutgoingMidiGenerator::sendProgramEditBufferDump() {
    MidiBuffer localMidiBuffer{ createPgmEditBufferDump() };
    combineMidiBuffers(localMidiBuffer);
}

MidiBuffer OutgoingMidiGenerator::createPgmEditBufferDump() {
    std::vector<uint8> sysExHeader;
    sysExHeader.push_back((uint8)SysExID::TargetDevice::Manufacturer);
    sysExHeader.push_back((uint8)SysExID::TargetDevice::Device);
    sysExHeader.push_back((uint8)SysExMessageType::programEditBufferDump);
    auto rawProgramData{ RawProgramData::extractFromExposedParameters(exposedParams) };
    for (auto dataByte : rawProgramData)
        sysExHeader.push_back(dataByte);
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(sysExHeader.data(), (int)sysExHeader.size()), 0);
    return localMidiBuffer;
}

void OutgoingMidiGenerator::parameterChanged(const String& parameterID, float newValue) {
    auto& midiParams{ MidiParameters_Singleton::get() };
    if (midiParams.paramChangeEchosAreNotBlocked()) {
        auto& info{ InfoForExposedParameters::get() };
        auto param{ info.indexFor(parameterID) };
        auto nrpn{ info.NRPNfor(param) };
        auto outputValue{ (uint8)roundToInt(newValue) };
        outputValue = SpecialValueOffsets::addWhenWritingToData(param, outputValue);
        addParamChangedMessageToMidiBuffer(nrpn, outputValue);
        if ((param == 98 || param == 100) && outputValue == 1)
            arpeggiatorAndSequencerCannotBothBeOn(param);
    }
    else return;
}

void OutgoingMidiGenerator::arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
    auto& info{ InfoForExposedParameters::get() };
    auto arpegParam{ exposedParams->getParameter(info.IDfor(98)) };
    auto sequencerParam{ exposedParams->getParameter(info.IDfor(100)) };
    if (paramTurnedOn == 98 && sequencerParam != nullptr)
        if (sequencerParam->getValue() != 0.0f)
            sequencerParam->setValueNotifyingHost(0.0f);
    if (paramTurnedOn == 100 && arpegParam != nullptr)
        if (arpegParam->getValue() != 0.0f)
            arpegParam->setValueNotifyingHost(0.0f);
}

void OutgoingMidiGenerator::addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue) {
    auto& midiParams{ MidiParameters_Singleton::get() };
    MidiBuffer nrpnBuffer;
    nrpnBuffer = NRPNbufferWithLeadingMSBsGenerator::generateFrom_NRPNindex_NewValue_andChannel(paramNRPN, newValue, midiParams.channel());
    combineMidiBuffers(nrpnBuffer);
}

void OutgoingMidiGenerator::combineMidiBuffers(MidiBuffer& midiBuffer) {
    internalMidiBuffer.addEvents(midiBuffer, 0, -1, 0);
    if (!isTimerRunning(timerID::midiBuffer)) {
        internalMidiBuffers->add(internalMidiBuffer);
        internalMidiBuffer.clear();
        startTimer(timerID::midiBuffer, 10);
    }
}

void OutgoingMidiGenerator::updateProgramNameOnHardware(String newName) {
    programName = newName;
    nameCharCounter = 0;
    MultiTimer::startTimer(timerID::pgmName, millisecondsBtwnParamChanges);
}

void OutgoingMidiGenerator::clearSequencerTrack(int trackNum) {
    jassert(trackNum > 0 && trackNum < 5);
    switch (trackNum) {
    case 1:
        track1StepCounter = 0;
        startTimer(timerID::clearSeqTrack1, millisecondsBtwnParamChanges);
        break;
    case 2:
        track2StepCounter = 0;
        startTimer(timerID::clearSeqTrack2, millisecondsBtwnParamChanges);
        break;
    case 3:
        track3StepCounter = 0;
        startTimer(timerID::clearSeqTrack3, millisecondsBtwnParamChanges);
        break;
    case 4:
        track4StepCounter = 0;
        startTimer(timerID::clearSeqTrack4, millisecondsBtwnParamChanges);
        break;
    default:
        break;
    }
}

void OutgoingMidiGenerator::saveProgramToStorageBankSlot(uint8 bank, uint8 slot) {
    auto programData{ RawProgramData::extractFromExposedParameters(exposedParams) };
    auto& pgmBanks{ PluginProgramBanks::get() };
    pgmBanks.storeProgramDataInBankSlot(programData.data(), bank, slot);
}

void OutgoingMidiGenerator::timerCallback(int timerID) {
    stopTimer(timerID);
    if (timerID == timerID::pgmName) {
        auto normalizedValue{ (char)programName[nameCharCounter] / 127.0f };
        auto param{ exposedParams->getParameter("nameChar" + (String)(nameCharCounter + 1)) };
        if (param != nullptr)
            param->setValueNotifyingHost(normalizedValue);
        if (nameCharCounter < 16) {
            ++nameCharCounter;
            startTimer(timerID::pgmName, millisecondsBtwnParamChanges);
        }
        else
            nameCharCounter = 0;
    }
    if (timerID == timerID::clearSeqTrack1) {
        if (track1StepCounter > -1 && track1StepCounter < 16) {
            clearSequencerStepOnTrack(track1StepCounter + 1, 1);
            if (track1StepCounter < 16) {
                ++track1StepCounter;
                MultiTimer::startTimer(timerID::clearSeqTrack1, millisecondsBtwnParamChanges);
            }
            else track1StepCounter = 0;
        }
    }
    if (timerID == timerID::clearSeqTrack2) {
        if (track2StepCounter > -1 && track2StepCounter < 16) {
            clearSequencerStepOnTrack(track2StepCounter + 1, 2);
            if (track2StepCounter < 16) {
                ++track2StepCounter;
                MultiTimer::startTimer(timerID::clearSeqTrack2, millisecondsBtwnParamChanges);
            }
            else track2StepCounter = 0;
        }
    }
    if (timerID == timerID::clearSeqTrack3) {
        if (track3StepCounter > -1 && track3StepCounter < 16) {
            clearSequencerStepOnTrack(track3StepCounter + 1, 3);
            if (track3StepCounter < 16) {
                ++track3StepCounter;
                MultiTimer::startTimer(timerID::clearSeqTrack3, millisecondsBtwnParamChanges);
            }
            else track3StepCounter = 0;
        }
    }
    if (timerID == timerID::clearSeqTrack4) {
        if (track4StepCounter > -1 && track4StepCounter < 16) {
            clearSequencerStepOnTrack(track4StepCounter + 1, 4);
            if (track4StepCounter < 16) {
                ++track4StepCounter;
                MultiTimer::startTimer(timerID::clearSeqTrack4, millisecondsBtwnParamChanges);
            }
            else track4StepCounter = 0;
        }
    }
}

void OutgoingMidiGenerator::clearSequencerStepOnTrack(int stepNum, int trackNum) {
    auto param{ exposedParams->getParameter("track" + (String)trackNum + "Step" + (String)stepNum) };
    param->setValueNotifyingHost(trackNum == 1 ? 1.0f : 0.0f); // set track 1 steps to 127 ('rest'), steps on other tracks to 0
}


//================================================================================


MidiBuffer NRPNbufferWithLeadingMSBsGenerator::generateFrom_NRPNindex_NewValue_andChannel(uint16 paramNRPN, uint8 newValue, uint8 midiChannel) {
    MidiBuffer nrpnBuffer;
    nrpnBuffer.addEvent(createNRPNindexMSBmessageForMidiChannel(paramNRPN, midiChannel), 0);
    nrpnBuffer.addEvent(createNRPNindexLSBmessageForMidiChannel(paramNRPN, midiChannel), 1);
    nrpnBuffer.addEvent(createNRPNvalueMSBmessageForMidiChannel(newValue, midiChannel), 2);
    nrpnBuffer.addEvent(createNRPNvalueLSBmessageForMidiChannel(newValue, midiChannel), 3);
    return nrpnBuffer;
}

MidiMessage NRPNbufferWithLeadingMSBsGenerator::createNRPNindexMSBmessageForMidiChannel(uint16 paramNRPN, uint8 midiChannel) {
    auto firstByte{ 176 + midiChannel };
    return MidiMessage(firstByte, 99, paramNRPN / 128);
}

MidiMessage NRPNbufferWithLeadingMSBsGenerator::createNRPNindexLSBmessageForMidiChannel(uint16 paramNRPN, uint8 midiChannel) {
    auto firstByte{ 176 + midiChannel };
    return MidiMessage(firstByte, 98, paramNRPN % 128);
}

MidiMessage NRPNbufferWithLeadingMSBsGenerator::createNRPNvalueMSBmessageForMidiChannel(uint8 newValue, uint8 midiChannel) {
    auto firstByte{ 176 + midiChannel };
    return MidiMessage(firstByte, 6, newValue / 128);
}

MidiMessage NRPNbufferWithLeadingMSBsGenerator::createNRPNvalueLSBmessageForMidiChannel(uint8 newValue, uint8 midiChannel) {
    auto firstByte{ 176 + midiChannel };
    return MidiMessage(firstByte, 38, newValue % 128);
}
