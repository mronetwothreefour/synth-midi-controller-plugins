#include "midi_IncomingMidi.h"

#include "midi_SysExHelpers.h"
#include "../banksWindow/banks_RawProgramData.h"



MidiBuffer IncomingMidi::pullMessagesThatAffectExposedParamsFromBuffer(AudioProcessorValueTreeState* exposedParams, const MidiBuffer& midiMessages) {
    MidiBuffer midiMessagesToPassThrough;
    for (auto event : midiMessages) {
        auto midiMessage{ event.getMessage() };
        if (SysExID::matchesTargetDevice(midiMessage))
            handleIncomingSysEx(exposedParams, midiMessage.getSysExData());
        else midiMessagesToPassThrough.addEvent(midiMessage, (int)midiMessage.getTimeStamp());
    }
    return midiMessagesToPassThrough;
}

void IncomingMidi::handleIncomingSysEx(AudioProcessorValueTreeState* exposedParams, const uint8* sysExData) {
    if (sysExData[3] == (uint8)SysExMessageType::programEditBufferDump)
        RawProgramData::applyToExposedParameters(sysExData + 4, exposedParams);
}
