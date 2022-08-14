#pragma once

#include <JuceHeader.h>

#include "midi_0_OutgoingMidiBuffers.h"

using OutgoingBuffers = OutgoingMidiBuffers;

struct SysExMessages
{
    static void addActivateQuickEditMessageToOutgoingBuffers(OutgoingBuffers* outgoingBuffers);
    static void addParamValueChangeMessageToOutgoingBuffers(uint8 paramIndex, uint8 newValue, OutgoingBuffers* outgoingBuffers);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SysExMessages)
};
