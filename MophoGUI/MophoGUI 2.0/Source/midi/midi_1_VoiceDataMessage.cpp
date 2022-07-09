#include "midi_1_VoiceDataMessage.h"

#include "midi_0_RawDataTools.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



void VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
    jassert(bank >= VoicesBank::custom_1);
    auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    requestVector.push_back((uint8)SysExMessageType::voiceDataRequest);
    requestVector.push_back((int)bank % 3);
    requestVector.push_back(slotNum);
    outgoingBuffers->addDataMessage(requestVector);
}

std::vector<uint8> VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(VoicesBank bank, uint8 slotNum, UnexposedParameters* unexposedParams) {
    auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    voiceDataMessageVector.push_back((uint8)SysExMessageType::voiceData);
    voiceDataMessageVector.push_back((int)bank % 3);
    voiceDataMessageVector.push_back(slotNum);
    auto voicesBanks{ unexposedParams->getVoicesBanks() };
    auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slotNum) };
    auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
    for (auto dataByte : voiceDataVector)
        voiceDataMessageVector.push_back(dataByte);
    for (auto emptyByte = voiceDataVector.size(); emptyByte != voiceDataMessageSize; ++emptyByte)
        voiceDataMessageVector.push_back((uint8)0);
    return voiceDataMessageVector;
}
