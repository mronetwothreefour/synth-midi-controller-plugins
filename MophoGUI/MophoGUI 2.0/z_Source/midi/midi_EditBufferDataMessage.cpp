#include "midi_EditBufferDataMessage.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_SysExHelpers.h"
#include "midi_RawDataTools.h"



void EditBufferDataMessage::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::editBufferDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers) {
    auto dumpDataVector{ createEditBufferDataMessage(exposedParams) };
    outgoingBuffers->addDataMessage(dumpDataVector);
}

std::vector<uint8> EditBufferDataMessage::createEditBufferDataMessage(AudioProcessorValueTreeState* exposedParams) {
    auto editBufferDataVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    editBufferDataVector.push_back((uint8)SysExMessageType::editBufferData);
    auto rawVoiceData{ RawDataTools::extractFromExposedParameters(exposedParams) };
    for (auto dataByte : rawVoiceData)
        editBufferDataVector.push_back(dataByte);
    return editBufferDataVector;
}