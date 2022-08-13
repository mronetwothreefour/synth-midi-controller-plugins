#pragma once

#include <JuceHeader.h>

#include "midi_0_NRPN_BufferWithLeading_MSBs.h"
#include "midi_0_Outgoing_MIDI_Buffers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

struct ParameterChangeMessage
{
    static void sendNewValueForNRPNtypeToUnexposedParamsForHandling(uint8 newValue, uint16 nrpnType, UnexposedParameters* unexposedParams) {
        auto globalOptions{ unexposedParams->getGlobalOptions() };
        auto nrpnBuffer{ NRPN_BufferWithLeading_MSBs::from_Channel_NRPNtype_NewValue(globalOptions->transmitChannel(), nrpnType, newValue) };
        auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };
        outgoingBuffers->addMidiBuffer(nrpnBuffer);
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterChangeMessage)
};