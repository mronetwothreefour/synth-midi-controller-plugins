#pragma once

#include <JuceHeader.h>

#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "midi_0_RawDataTools.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../voices/voices_1_tree_VoicesBank.h"
#include "../unexposedParameters/up_0_tree_VoiceTransmissionOptions.h"

using namespace P_600_G_Constants;
using OutgoingBuffers = Outgoing_MIDI_Buffers;

struct SysExMessages
{
    static void addRequestForVoiceDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
        jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
        auto requestVector{ RawDataTools::createRawDataVectorWithSequentialCircuitsSysExID() };
        requestVector.push_back(RawDataTools::messageType_VoiceDataRequest);
        requestVector.push_back(slotNum);;
        outgoingBuffers->addDataMessage(requestVector);
    }

    static void addDataMessageForCurrentVoiceToOutgoingBuffers(
        ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions, OutgoingBuffers* outgoingBuffers)
    {
        auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithSequentialCircuitsSysExID() };
        voiceDataMessageVector.push_back(RawDataTools::messageType_VoiceData);
        auto currentVoiceNum{ transmitOptions->currentVoiceNumber() };
        voiceDataMessageVector.push_back(currentVoiceNum);
        auto rawVoiceData{ RawDataTools::extractRawVoiceDataFromExposedParameters(exposedParams) };
        for (auto dataByte : rawVoiceData)
            voiceDataMessageVector.push_back(dataByte);
        outgoingBuffers->addDataMessage(voiceDataMessageVector);
    }

    static void addDataMessageForVoiceStoredInSlotToOutgoingBuffers(VoicesBank* voicesBank, uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
        jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
        auto voiceDataMessageVector{ RawDataTools::createRawDataVectorWithSequentialCircuitsSysExID() };
        voiceDataMessageVector.push_back(RawDataTools::messageType_VoiceData);
        voiceDataMessageVector.push_back(slotNum);
        auto voiceDataHexString{ voicesBank->getVoiceDataHexStringWithoutNameFromSlot(slotNum) };
        auto rawVoiceData{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
        for (auto dataByte : rawVoiceData)
            voiceDataMessageVector.push_back(dataByte);
        outgoingBuffers->addDataMessage(voiceDataMessageVector);
    }
};