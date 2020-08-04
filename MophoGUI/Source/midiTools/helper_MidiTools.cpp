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
}
