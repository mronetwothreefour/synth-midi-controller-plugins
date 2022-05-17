#include "midi_GlobalParametersDataMessage.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"



void GlobalParametersDataMessage::addRequestForDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::globalParametersDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}
