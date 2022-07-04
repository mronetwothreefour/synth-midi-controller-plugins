#pragma once

#include <JuceHeader.h>

#include "midi_0_NRPNbufferWithLeadingMSBs.h"
#include "midi_0_OutgoingMidiBuffers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



struct ParameterChangeMessage {
    static void sendNewValueForNRPNtypeToUnexposedParamsForHandling(uint8 newValue, uint16 nrpnType, UnexposedParameters* unexposedParams) {
        auto globalOptions{ unexposedParams->getGlobalOptions() };
        auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(globalOptions->transmitChannel(), nrpnType, newValue) };
        auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };
        outgoingBuffers->addMidiBuffer(nrpnBuffer);
    }
};