#pragma once

#include <JuceHeader.h>

#include "midi_0_OutgoingMidiBuffers.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using OutgoingBuffers = OutgoingMidiBuffers;



class UnexposedParameters;

struct VoiceDataMessage {
    static void addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers);
    static std::vector<uint8> createDataMessageForVoiceStoredInBankAndSlot(VoicesBank bank, uint8 slotNum, UnexposedParameters* unexposedParams);
};