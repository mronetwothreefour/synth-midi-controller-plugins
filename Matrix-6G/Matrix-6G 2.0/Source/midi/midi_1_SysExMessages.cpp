#include "midi_1_SysExMessages.h"

#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "midi_0_RawDataTools.h"
#include "../constants/constants_Splits.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../splits/splits_0_tree_SplitsBank.h"
#include "../voices/voices_1_tree_VoicesBanks.h"

using namespace Matrix_6G_Constants;

void SysExMessages::addActivateQuickEditMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto activateQuickEditVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    activateQuickEditVector.push_back((uint8)SysExMessageType::activateQuickEdit);
    outgoingBuffers->addDataMessage(activateQuickEditVector);
}

void SysExMessages::addParamValueChangeMessageToOutgoingBuffers(uint8 paramNum, uint8 newValue, OutgoingBuffers* outgoingBuffers) {
    auto paramChangeVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    paramChangeVector.push_back((uint8)SysExMessageType::parameterChange);
    paramChangeVector.push_back(paramNum);
    paramChangeVector.push_back(newValue);
    outgoingBuffers->addDataMessage(paramChangeVector);
}

void SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto requestVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    requestVector.push_back((uint8)SysExMessageType::dataRequest);
    requestVector.push_back((uint8)SysExDataRequestType::voice);
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

void SysExMessages::addSwitchToSplitModeMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto splitModeVector{ RawDataTools::createRawDataVectorWithXpander_SysExID_ForSwitchingToSplitMode() };
    splitModeVector.push_back((uint8)SysExMessageType::switchMode);
    splitModeVector.push_back((uint8)SysExMessageType::splitData);
    outgoingBuffers->addDataMessage(splitModeVector);
}

void SysExMessages::addRequestForSplitDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
    jassert(slotNum < SPLT::numberOfSlotsInSplitsBank);
    auto requestVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    requestVector.push_back((uint8)SysExMessageType::dataRequest);
    requestVector.push_back((uint8)SysExDataRequestType::split);
    requestVector.push_back(slotNum);
    outgoingBuffers->addDataMessage(requestVector);
}

void SysExMessages::addDataMessageForSplitStoredInSlotToOutgoingBuffers(SplitsBank* splitsBank, uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
    jassert(slotNum < SPLT::numberOfSlotsInSplitsBank);
    auto splitDataMessageVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    splitDataMessageVector.push_back((uint8)SysExMessageType::splitData);
    splitDataMessageVector.push_back(slotNum);
    auto splitDataHexString{ splitsBank->getSplitDataHexStringFromSlot(slotNum) };
    auto splitDataVector{ RawDataTools::convertHexStringToDataVector(splitDataHexString) };
    for (auto dataByte : splitDataVector)
        splitDataMessageVector.push_back(dataByte);
    outgoingBuffers->addDataMessage(splitDataMessageVector);
}

void SysExMessages::addRequestForGlobalDataToOutgoingBuffers(OutgoingBuffers* outgoingBuffers) {
    auto requestVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    requestVector.push_back((uint8)SysExMessageType::dataRequest);
    requestVector.push_back((uint8)SysExDataRequestType::global);
    requestVector.push_back(0);
    outgoingBuffers->addDataMessage(requestVector);
}

void SysExMessages::addGlobalDataMessageToOutgoingBuffers(GlobalOptions* globalOptions, OutgoingBuffers* outgoingBuffers) {
    auto globalDataMessageVector{ RawDataTools::createRawDataVectorWithMatrix_6_SysExID() };
    globalDataMessageVector.push_back((uint8)SysExMessageType::globalData);
    globalDataMessageVector.push_back(2);
    globalDataMessageVector.push_back(0);
    globalDataMessageVector.push_back(0);
    auto globalDataVector{ RawDataTools::extractRawGlobalDataFrom_GUI(globalOptions) };
    for (auto dataByte : globalDataVector)
        globalDataMessageVector.push_back(dataByte);
    outgoingBuffers->addDataMessage(globalDataMessageVector);
}

