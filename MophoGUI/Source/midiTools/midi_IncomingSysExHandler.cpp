#include "midi_IncomingSysExHandler.h"

#include "midi_SysExHelpers.h"
#include "../banksWindow/banks_RawProgramData.h"



IncomingSysExHandler::IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams) :
    exposedParams{ exposedParams }
{
}

IncomingSysExHandler::~IncomingSysExHandler() {
}

MidiBuffer IncomingSysExHandler::pullSysExWithMatchingIDOutOfBuffer(const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (!incomingSysExHasMatchingID(midiMessage))
            midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

bool IncomingSysExHandler::incomingSysExHasMatchingID(MidiMessage midiMessage) {
    if (SysExID::matchesHardwareSynthID(midiMessage)) {
        auto sysExData{ midiMessage.getSysExData() };
        if (sysExData[3] == (uint8)SysExMessageType::programEditBufferDump)
            RawProgramData::applyToExposedParameters(sysExData + 4, exposedParams);
        return true;
    }
    else return false;
}

