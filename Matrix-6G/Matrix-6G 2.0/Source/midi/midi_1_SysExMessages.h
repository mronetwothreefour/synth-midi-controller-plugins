#pragma once

#include <JuceHeader.h>

#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;
using OutgoingBuffers = Outgoing_MIDI_Buffers;

class ExposedParameters;
class GlobalOptions;
class SplitsBank;
class VoicesBanks;

struct SysExMessages
{
    static void addActivateQuickEditMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);
    static void addParamValueChangeMessageToOutgoingBuffers(uint8 paramNum, uint8 newValue, OutgoingBuffers* outgoingBuffers);

    static void addRequestForVoiceDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers);
    static void addDataMessageForCurrentVoiceToOutgoingBuffers(ExposedParameters* exposedParams, OutgoingBuffers* outgoingBuffers);
    static void addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(
        VoicesBanks* voicesBanks, VoicesBank bank, uint8 slotNum, OutgoingBuffers* outgoingBuffers);

    static void addSwitchToSplitModeMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);
    static void addRequestForSplitDataStoredInSlotToOutgoingBuffers(uint8 slotNum, OutgoingBuffers* outgoingBuffers);
    static void addDataMessageForSplitStoredInSlotToOutgoingBuffers(SplitsBank* splitsBank, uint8 slotNum, OutgoingBuffers* outgoingBuffers);

    static void addRequestForGlobalDataToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);
    static void addGlobalDataMessageToOutgoingBuffers(GlobalOptions* globalOptions, OutgoingBuffers* outgoingBuffers);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SysExMessages)
};
