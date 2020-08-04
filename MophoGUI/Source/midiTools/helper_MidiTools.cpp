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


