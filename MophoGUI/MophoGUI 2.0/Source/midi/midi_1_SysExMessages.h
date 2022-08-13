#pragma once

#include <JuceHeader.h>

#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using OutgoingBuffers = Outgoing_MIDI_Buffers;

class ExposedParameters;
class VoicesBanks;

struct SysExMessages
{
    static const int voiceDataMessageSize{ 298 };

    static void addRequestForEditBufferDataToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);
    static void addEditBufferDataMessageToOutgoingBuffers(ExposedParameters* exposedParams, OutgoingBuffers* outgoingBuffers);

    static void addRequestForGlobalParamsDataToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);

    static void addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers);
    static void addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(
        VoicesBanks* voicesBanks, VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SysExMessages)
};
