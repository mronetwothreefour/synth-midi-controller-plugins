#pragma once

#include <JuceHeader.h>

#include "midi_0_Outgoing_MIDI_Buffers.h"

using OutgoingBuffers = Outgoing_MIDI_Buffers;

struct SysExMessages
{
    static void addActivateQuickEditMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);
    static void addParamValueChangeMessageToOutgoingBuffers(uint8 paramIndex, uint8 newValue, OutgoingBuffers* outgoingBuffers);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SysExMessages)
};
