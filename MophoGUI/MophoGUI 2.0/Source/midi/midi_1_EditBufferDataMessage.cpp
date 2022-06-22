#include "midi_1_EditBufferDataMessage.h"

#include "midi_0_OutgoingMidiBuffers.h"
#include "midi_0_RawDataTools.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;



void EditBufferDataMessage::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    requestVector.push_back((uint8)SysExMessageType::editBufferDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(
    ExposedParameters* exposedParams, OutgoingMidiBuffers* outgoingBuffers)
{
    auto dumpDataVector{ createEditBufferDataMessage(exposedParams) };
    outgoingBuffers->addDataMessage(dumpDataVector);
}

std::vector<uint8> EditBufferDataMessage::createEditBufferDataMessage(ExposedParameters* exposedParams) {
    auto editBufferDataVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    editBufferDataVector.push_back((uint8)SysExMessageType::editBufferData);
    auto rawVoiceData{ RawDataTools::extractRawDataFromExposedParameters(exposedParams) };
    for (auto dataByte : rawVoiceData)
        editBufferDataVector.push_back(dataByte);
    return editBufferDataVector;
}
