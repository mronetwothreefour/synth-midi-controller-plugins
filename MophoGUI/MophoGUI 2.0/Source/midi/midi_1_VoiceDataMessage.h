#pragma once

#include <JuceHeader.h>

#include "midi_0_OutgoingMidiBuffers.h"
#include "midi_0_RawDataTools.h"
#include "../constants/constants_Enum.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;
using OutgoingBuffers = OutgoingMidiBuffers;

struct VoiceDataMessage {
    static const int voiceDataMessageSize{ 298 };

    static void addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
        jassert(bank >= VoicesBank::custom_1);
        auto requestVector{ RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() };
        requestVector.push_back((uint8)SysExMessageType::voiceDataRequest);
        requestVector.push_back((int)bank % 3);
        requestVector.push_back(slotNum);
        outgoingBuffers->addDataMessage(requestVector);
    }

    static std::vector<uint8> createDataMessageForVoiceStoredInBankAndSlot(VoicesBank bank, uint8 slotNum, UnexposedParameters* unexposedParams) {
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
};