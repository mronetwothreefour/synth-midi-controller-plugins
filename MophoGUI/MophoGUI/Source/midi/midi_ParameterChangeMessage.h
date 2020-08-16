#pragma once

#include <JuceHeader.h>

#include "midi_NRPNbufferWithLeadingMSBs.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../params/params_UnexposedParameters_Facade.h"



struct ParameterChangeMessage {
    static void sendNewValueForNRPNtypeToUnexposedParamsForHandling(uint8 newValue, uint16 nrpnType, UnexposedParameters* unexposedParams) {
        auto midiOptions{ unexposedParams->midiOptions_get() };
        auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(midiOptions->channel(), nrpnType, newValue) };
        auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
        outgoingBuffers->aggregateOutgoingMidiBuffers(nrpnBuffer);
    }
};