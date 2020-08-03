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


OutgoingMidiGenerator::OutgoingMidiGenerator(AudioProcessorValueTreeState* exposedParams) :
	exposedParams{ exposedParams },
    nameCharCounter{ 0 },
    track1StepCounter{ 0 },
    track2StepCounter{ 0 },
    track3StepCounter{ 0 },
    track4StepCounter{ 0 },
    millisecondsBtwnParamChanges{ 10 }
{
}

OutgoingMidiGenerator::~OutgoingMidiGenerator() {
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


