#include "midi_1_VoiceDataMessage.h"

#include "midi_0_RawDataTools.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



void VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(VoicesBank bank, uint8 slot, OutgoingBuffers* outgoingBuffers) {
    jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
    auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    requestVector.push_back((uint8)SysExMessageType::voiceDataRequest);
    switch (bank)
    {
    case VoicesBank::custom_1:
        requestVector.push_back(0);
        break;
    case VoicesBank::custom_2:
        requestVector.push_back(1);
        break;
    case VoicesBank::custom_3:
        requestVector.push_back(2);
        break;
    default:
        requestVector.push_back(0);
        break;
    }
    requestVector.push_back(slot);
    outgoingBuffers->addDataMessage(requestVector);
}

//std::vector<uint8> VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams) {
    //auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
    //voiceDataMessageVector.push_back((uint8)SysExMessageType::voiceData);
    //switch (bank)
    //{
    //case VoicesBank::factory_1:
    //    voiceDataMessageVector.push_back(0);
    //    break;
    //case VoicesBank::factory_2:
    //    voiceDataMessageVector.push_back(1);
    //    break;
    //case VoicesBank::factory_3:
    //    voiceDataMessageVector.push_back(2);
    //    break;
    //case VoicesBank::custom_1:
    //    voiceDataMessageVector.push_back(0);
    //    break;
    //case VoicesBank::custom_2:
    //    voiceDataMessageVector.push_back(1);
    //    break;
    //case VoicesBank::custom_3:
    //    voiceDataMessageVector.push_back(2);
    //    break;
    //default:
    //    voiceDataMessageVector.push_back(0);
    //    break;
    //}
    //voiceDataMessageVector.push_back(slot);
    //auto voicesBanks{ unexposedParams->getVoicesBanks() };
    //auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slot) };
    //auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
    //for (auto dataByte : voiceDataVector)
    //    voiceDataMessageVector.push_back(dataByte);
    //for (auto emptyByte = voiceDataVector.size(); emptyByte != 298; ++emptyByte)
    //    voiceDataMessageVector.push_back((uint8)0);
    //return voiceDataMessageVector;
//}
