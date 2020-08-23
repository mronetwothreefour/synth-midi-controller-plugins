#include "midi_GlobalParametersDump.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"



void GlobalParametersDump::addRequestForDumpToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::globalParametersDumpRequest);
    MidiBuffer localMidiBuffer;
    localMidiBuffer.addEvent(MidiMessage::createSysExMessage(requestVector.data(), (int)requestVector.size()), 0);
    outgoingBuffers->aggregateOutgoingMidiBuffers(localMidiBuffer);
}
