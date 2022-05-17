#pragma once

#include <JuceHeader.h>

#include "../voices/voices_VoicesBanks.h"



class OutgoingMidiBuffers;
class UnexposedParameters;

struct VoiceDataMessage {
    static void addRequestForVoiceDataStoredInBankAndSlotToOutgoingMidiBuffers(VoicesBank bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers);
    static std::vector<uint8> createDataMessageForVoiceStoredInBankAndSlot(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams);
};