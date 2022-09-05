#pragma once

#include <JuceHeader.h>

#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "midi_0_RawDataTools.h"
#include "../constants/constants_Voices.h"

using namespace P_600_G_Constants;
using OutgoingBuffers = Outgoing_MIDI_Buffers;

struct SysExMessages
{
    static const uint8 messageType_VoiceData{ 2 };
    static const uint8 messageType_VoiceDataRequest{ 0 };

    static void addRequestForVoiceDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers) {
        jassert(slotNum < VCS::numberOfVoiceSlots);
        auto requestVector{ RawDataTools::createRawDataVectorWithSequentialCircuitsSysExID() };
        requestVector.push_back(messageType_VoiceDataRequest);
        requestVector.push_back(slotNum);;
        outgoingBuffers->addDataMessage(requestVector);
    }
};