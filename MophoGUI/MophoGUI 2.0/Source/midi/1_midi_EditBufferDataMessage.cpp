#include "1_midi_EditBufferDataMessage.h"

#include "0_midi_OutgoingMidiBuffers.h"
#include "0_midi_RawDataTools.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;



void EditBufferDataMessage::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    requestVector.push_back((uint8)SysExMessageType::editBufferDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(
    AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers)
{
    auto dumpDataVector{ createEditBufferDataMessage(exposedParams) };
    outgoingBuffers->addDataMessage(dumpDataVector);
}

std::vector<uint8> EditBufferDataMessage::createEditBufferDataMessage(AudioProcessorValueTreeState* exposedParams) {
    auto editBufferDataVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    editBufferDataVector.push_back((uint8)SysExMessageType::editBufferData);
    auto rawVoiceData{ RawDataTools::extractRawDataFromExposedParameters(exposedParams) };
    for (auto dataByte : rawVoiceData)
        editBufferDataVector.push_back(dataByte);
    return editBufferDataVector;
}
