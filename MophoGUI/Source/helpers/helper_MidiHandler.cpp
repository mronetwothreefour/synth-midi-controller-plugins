#include "helper_MidiHandler.h"

MidiHandler::MidiHandler(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers) :
	exposedParams{ exposedParams },
    internalMidiBuffers{ internalMidiBuffers },
    paramChangeEchoIsBlocked{ false },
    nameCharCounter{ 0 },
    track1StepCounter{ 0 },
    track2StepCounter{ 0 },
    track3StepCounter{ 0 },
    track4StepCounter{ 0 },
    millisecondsBtwnParamChanges{ 10 },
    programName{ "Basic Patch     " }
{
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->addParameterListener(info.IDfor(param), this);
}

MidiHandler::~MidiHandler() {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
        exposedParams->removeParameterListener(info.IDfor(param), this);
}

void MidiHandler::updateProgramNameOnHardware(String newName) {
    programName = newName;
    nameCharCounter = 0;
    MultiTimer::startTimer(pgmNameTimer, millisecondsBtwnParamChanges);
}

void MidiHandler::clearSequencerTrack(int trackNum) {
    jassert(trackNum > 0 && trackNum < 5);
    switch (trackNum) {
    case 1: 
        track1StepCounter = 0; 
        startTimer(clearSeqTrack1Timer, millisecondsBtwnParamChanges); 
        break;
    case 2: 
        track2StepCounter = 0; 
        startTimer(clearSeqTrack2Timer, millisecondsBtwnParamChanges); 
        break;
    case 3: 
        track3StepCounter = 0; 
        startTimer(clearSeqTrack3Timer, millisecondsBtwnParamChanges); 
        break;
    case 4: 
        track4StepCounter = 0; 
        startTimer(clearSeqTrack4Timer, millisecondsBtwnParamChanges); 
        break;
    default: 
        break;
    }
}

void MidiHandler::sendProgramEditBufferDumpRequest() {
    const char sysExData[]{ 1, 37, 6 };
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
    combineMidiBuffers(localMidiBuffer);
}

void MidiHandler::sendProgramEditBufferDump() {
    MidiBuffer localMidiBuffer{ createPgmEditBufferDump() };
    combineMidiBuffers(localMidiBuffer);
}

void MidiHandler::parameterChanged(const String& parameterID, float newValue) {
    if (!paramChangeEchoIsBlocked) {
        auto& info{ InfoForExposedParameters::get() };
        auto param{ info.indexFor(parameterID) };
        auto nrpn{ info.NRPNfor(param) };
        auto outputValue{ (uint8)roundToInt(newValue) };
        outputValue = addAnyParamSpecificOffsetsToOutputValue(param, outputValue);
        addParamChangedMessageToMidiBuffer(nrpn, outputValue);
        if ((param == 98 || param == 100) && outputValue == 1)
            arpeggiatorAndSequencerCannotBothBeOn(param);
    }
    else return;
}

uint8 MidiHandler::addAnyParamSpecificOffsetsToOutputValue(uint8 param, uint8 outputValue) {
    if (param == 95)
        outputValue += 30; // clock tempo parameter range is offset by 30
    if (param > 104 && param < 109 && outputValue > 104) // knob assignment parameters
        outputValue += 15; // offset to account for unassignable Mopho parameters 105..119
    return outputValue;
}

void MidiHandler::addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue) {
    // Send MIDI channel change messages out on all channels
    if (paramNRPN == 386) {
        for (uint8 midiChannel = 0; midiChannel != 16; ++midiChannel) {
            auto nrpnBuffer{ NRPNbufferWithLeadingMSBsGenerator::generateFrom_NRPNindex_NewValue_andChannel(paramNRPN, newValue, midiChannel) };
            combineMidiBuffers(nrpnBuffer);
        }
    }
    else {
        // TODO: get current MIDI channel from global options
        auto midiChannel{ (uint8)0 };
        auto nrpnBuffer{ NRPNbufferWithLeadingMSBsGenerator::generateFrom_NRPNindex_NewValue_andChannel(paramNRPN, newValue, midiChannel) };
        combineMidiBuffers(nrpnBuffer);
    }
}

void MidiHandler::arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
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

MidiBuffer MidiHandler::createPgmEditBufferDump() {
    uint8 sysExData[296]{};

    sysExData[0] = 1;    // DSI manufacturer ID
    sysExData[1] = 37;   // Mopho device ID
    sysExData[2] = 3;    // dump type ID (to edit buffer)
    addParamValueBytesToBufferStartingAtOffset(sysExData, 3);
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(sysExData, numElementsInArray(sysExData)), 0);
    return localMidiBuffer;
}

void MidiHandler::addParamValueBytesToBufferStartingAtOffset(uint8* buffer, int dataOffset) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex)
    {
        auto paramID{ info.IDfor(paramIndex) };
        auto param{ exposedParams->getParameter(paramID) };
        auto paramValue{ roundToInt(param->getValue() * info.maxValueFor(paramIndex)) };
        if (paramIndex == 95) // clock tempo parameter range is offset by 30
            paramValue += 30;
        auto msbIndex{ info.msBitPackedByteLocationFor(paramIndex) + dataOffset };
        auto lsbIndex{ info.lsByteLocationFor(paramIndex) + dataOffset };
        if (paramValue > 127) {
            *(buffer + msbIndex) += info.msBitMaskFor(paramIndex);
        }
        *(buffer + lsbIndex) = paramValue % 128;
    }
}

void MidiHandler::combineMidiBuffers(MidiBuffer& midiBuffer) {
    internalMidiBuffer.addEvents(midiBuffer, 0, -1, 0);
    if (!isTimerRunning(midiBufferTimer)) {
        internalMidiBuffers->add(internalMidiBuffer);
        internalMidiBuffer.clear();
        startTimer(midiBufferTimer, 10);
    }
}

void MidiHandler::timerCallback(int timerID) {
    stopTimer(timerID);

    if (timerID == pgmNameTimer) {
        // convert nameChar's ASCII value (0..127) to a normalized value (0.0f..1.0f)
        auto normalizedValue{ (char)programName[nameCharCounter] / 127.0f };
        auto param{ exposedParams->getParameter("nameChar" + (String)(nameCharCounter + 1)) };
        if (param != nullptr)
            param->setValueNotifyingHost(normalizedValue);
        if (nameCharCounter < 16) {
            ++nameCharCounter;
            startTimer(pgmNameTimer, millisecondsBtwnParamChanges);
        }
        else
            nameCharCounter = 0;
    }

    if (timerID == clearSeqTrack1Timer)
    {
        if (track1StepCounter > -1 && track1StepCounter < 16)
        {
            clearSequencerStepOnTrack(track1StepCounter + 1, 1);
            if (track1StepCounter < 16) { 
                ++track1StepCounter; 
                MultiTimer::startTimer(clearSeqTrack1Timer, millisecondsBtwnParamChanges); }
            else track1StepCounter = 0;
        }
    }

    if (timerID == clearSeqTrack2Timer)
    {
        if (track2StepCounter > -1 && track2StepCounter < 16)
        {
            clearSequencerStepOnTrack(track2StepCounter + 1, 2);
            if (track2StepCounter < 16) {
                ++track2StepCounter;
                MultiTimer::startTimer(clearSeqTrack2Timer, millisecondsBtwnParamChanges); }
            else track2StepCounter = 0;
        }
    }

    if (timerID == clearSeqTrack3Timer)
    {
        if (track3StepCounter > -1 && track3StepCounter < 16)
        {
            clearSequencerStepOnTrack(track3StepCounter + 1, 3);
            if (track3StepCounter < 16) {
                ++track3StepCounter;
                MultiTimer::startTimer(clearSeqTrack3Timer, millisecondsBtwnParamChanges); }
            else track3StepCounter = 0;
        }
    }

    if (timerID == clearSeqTrack4Timer)
    {
        if (track4StepCounter > -1 && track4StepCounter < 16)
        {
            clearSequencerStepOnTrack(track4StepCounter + 1, 4);
            if (track4StepCounter < 16) {
                ++track4StepCounter;
                MultiTimer::startTimer(clearSeqTrack4Timer, millisecondsBtwnParamChanges); }
            else track4StepCounter = 0;
        }
    }
}

void MidiHandler::clearSequencerStepOnTrack(int stepNum, int trackNum) {
    auto param{ exposedParams->getParameter("track" + (String) trackNum + "Step" + (String)stepNum) };
    param->setValueNotifyingHost(trackNum == 1 ? 1.0f : 0.0f); // set track 1 steps to 127 ('rest'), steps on other tracks to 0
}
