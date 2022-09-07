#include "midi_1_SysExMessages.h"

#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "midi_0_RawDataTools.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../voices/voices_1_tree_VoicesBanks.h"

using namespace Matrix_6G_Constants;

void SysExMessages::addActivateQuickEditMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto activateQuickEditVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    activateQuickEditVector.push_back((uint8)(int)SysExMessageType::activateQuickEdit);
    outgoingBuffers->addDataMessage(activateQuickEditVector);
}

void SysExMessages::addParamValueChangeMessageToOutgoingBuffers(uint8 paramIndex, uint8 newValue, OutgoingBuffers* outgoingBuffers) {
    auto paramChangeVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    paramChangeVector.push_back((uint8)(int)SysExMessageType::parameterChange);
    paramChangeVector.push_back(paramIndex);
    paramChangeVector.push_back(newValue);
    outgoingBuffers->addDataMessage(paramChangeVector);
}

void SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto requestVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    requestVector.push_back((uint8)SysExMessageType::dataRequest);
    requestVector.push_back((uint8)SysExMessageType::voiceData);
    requestVector.push_back(slotNum);
    outgoingBuffers->addDataMessage(requestVector);
}

void SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(ExposedParameters* exposedParams, OutgoingBuffers* outgoingBuffers) {
    auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    voiceDataMessageVector.push_back((uint8)SysExMessageType::voiceData);
    auto currentVoiceNum{ exposedParams->currentVoiceOptions->currentVoiceNumber() };
    voiceDataMessageVector.push_back(currentVoiceNum);
    auto rawVoiceData{ RawDataTools::extractRawVoiceDataFrom_GUI(exposedParams) };
    for (auto dataByte : rawVoiceData)
        voiceDataMessageVector.push_back(dataByte);
    outgoingBuffers->addDataMessage(voiceDataMessageVector);
}

void SysExMessages::addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(
    VoicesBanks* voicesBanks, VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers)
{
    auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    voiceDataMessageVector.push_back((uint8)SysExMessageType::voiceData);
    voiceDataMessageVector.push_back(slotNum);
    auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slotNum) };
    auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
    for (auto dataByte : voiceDataVector)
        voiceDataMessageVector.push_back(dataByte);
    outgoingBuffers->addDataMessage(voiceDataMessageVector);
}

