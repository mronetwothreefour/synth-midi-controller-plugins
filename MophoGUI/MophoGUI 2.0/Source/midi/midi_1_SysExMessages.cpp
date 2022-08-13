#include "midi_1_SysExMessages.h"

#include "midi_0_RawDataTools.h"
#include "../voices/voices_1_tree_VoicesBanks.h"

void SysExMessages::addRequestForEditBufferDataToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto requestVector{ RawDataTools::createRawDataVectorWithMophoSysExID() };
    requestVector.push_back((uint8)SysExMessageType::editBufferDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void SysExMessages::addEditBufferDataMessageToOutgoingBuffers(ExposedParameters* exposedParams, OutgoingBuffers* outgoingBuffers) {
    const int editBufferDataVectorSize{ 293 };
    auto editBufferDataVector{ RawDataTools::createRawDataVectorWithMophoSysExID() };
    editBufferDataVector.push_back((uint8)SysExMessageType::editBufferData);
    auto rawVoiceData{ RawDataTools::extractRawVoiceDataFromExposedParameters(exposedParams) };
    for (auto dataByte : rawVoiceData)
        editBufferDataVector.push_back(dataByte);
    for (auto emptyByte = rawVoiceData.size(); emptyByte != editBufferDataVectorSize; ++emptyByte)
        editBufferDataVector.push_back((uint8)0);
    outgoingBuffers->addDataMessage(editBufferDataVector);
}

void SysExMessages::addRequestForGlobalParamsDataToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto requestVector{ RawDataTools::createRawDataVectorWithMophoSysExID() };
    requestVector.push_back((uint8)SysExMessageType::globalParametersDataRequest);
    outgoingBuffers->addDataMessage(requestVector);
}

void SysExMessages::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
    jassert(bank >= VoicesBank::custom_1);
    auto requestVector{ RawDataTools::createRawDataVectorWithMophoSysExID() };
    requestVector.push_back((uint8)SysExMessageType::voiceDataRequest);
    requestVector.push_back((int)bank % 3);
    requestVector.push_back(slotNum);
    outgoingBuffers->addDataMessage(requestVector);
}

void SysExMessages::addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(
    VoicesBanks* voicesBanks, VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers)
{
    auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithMophoSysExID() };
    voiceDataMessageVector.push_back((uint8)SysExMessageType::voiceData);
    voiceDataMessageVector.push_back((int)bank % 3);
    voiceDataMessageVector.push_back(slotNum);
    auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slotNum) };
    auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
    for (auto dataByte : voiceDataVector)
        voiceDataMessageVector.push_back(dataByte);
    for (auto emptyByte = voiceDataVector.size(); emptyByte != voiceDataMessageSize; ++emptyByte)
        voiceDataMessageVector.push_back((uint8)0);
    outgoingBuffers->addDataMessage(voiceDataMessageVector);
}


