#include "midi_VoiceDataMessage.h"

#include "midi_OutgoingMidiBuffers.h"
#include "midi_RawDataTools.h"
#include "midi_SysExHelpers.h"
#include "../params/params_UnexposedParameters_Facade.h"



void VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingMidiBuffers(VoicesBank bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers) {
    jassert(bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3);
    auto requestVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    requestVector.push_back((uint8)SysExMessageType::voiceDataRequest);
    switch (bank)
    {
    case VoicesBank::custom1:
        requestVector.push_back(0);
        break;
    case VoicesBank::custom2:
        requestVector.push_back(1);
        break;
    case VoicesBank::custom3:
        requestVector.push_back(2);
        break;
    default:
        requestVector.push_back(0);
        break;
    }
    requestVector.push_back(slot);
    outgoingBuffers->addDataMessage(requestVector);
}

std::vector<uint8> VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    auto voiceDataMessageVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
    voiceDataMessageVector.push_back((uint8)SysExMessageType::voiceData);
    switch (bank)
    {
    case VoicesBank::factory1:
        voiceDataMessageVector.push_back(0);
        break;
    case VoicesBank::factory2:
        voiceDataMessageVector.push_back(1);
        break;
    case VoicesBank::factory3:
        voiceDataMessageVector.push_back(2);
        break;
    case VoicesBank::custom1:
        voiceDataMessageVector.push_back(0);
        break;
    case VoicesBank::custom2:
        voiceDataMessageVector.push_back(1);
        break;
    case VoicesBank::custom3:
        voiceDataMessageVector.push_back(2);
        break;
    default:
        voiceDataMessageVector.push_back(0);
        break;
    }
    voiceDataMessageVector.push_back(slot);
    auto voicesBanks{ unexposedParams->voicesBanks_get() };
    auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slot) };
    auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
    for (auto dataByte : voiceDataVector)
        voiceDataMessageVector.push_back(dataByte);
    for (auto emptyByte = voiceDataVector.size(); emptyByte != 298; ++emptyByte)
        voiceDataMessageVector.push_back((uint8)0);
    return voiceDataMessageVector;
}