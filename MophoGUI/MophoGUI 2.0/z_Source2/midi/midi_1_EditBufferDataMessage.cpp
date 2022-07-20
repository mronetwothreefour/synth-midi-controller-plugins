#include "midi_1_EditBufferDataMessage.h"

#include "midi_0_RawDataTools.h"
#include "../constants/constants_Enum.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



void EditBufferDataMessage::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
    auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    requestVector.push_back((uint8)SysExMessageType::editBufferDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(
    ExposedParameters* exposedParams, UnexposedParameters* unexposedParams)
{
    auto dumpDataVector{ createEditBufferDataMessage(exposedParams) };
    auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };
    outgoingBuffers->addDataMessage(dumpDataVector);
}

std::vector<uint8> EditBufferDataMessage::createEditBufferDataMessage(ExposedParameters* exposedParams) {
    const int editBufferDataVectorSize{ 293 };
    auto editBufferDataVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    editBufferDataVector.push_back((uint8)SysExMessageType::editBufferData);
    auto rawVoiceData{ RawDataTools::extractRawDataFromExposedParameters(exposedParams) };
    for (auto dataByte : rawVoiceData)
        editBufferDataVector.push_back(dataByte);
    for (auto emptyByte = rawVoiceData.size(); emptyByte != editBufferDataVectorSize; ++emptyByte)
        editBufferDataVector.push_back((uint8)0);
    return editBufferDataVector;
}
