#pragma once

#include <JuceHeader.h>

#include "midi_OutgoingMidiBuffers.h"
#include "midi_NRPNbufferWithLeadingMSBs.h"
#include "../parameters/params_MidiOptions_Singleton.h"



struct ParameterChangeMessage {
	static void addNewValueForNRPNtypeToOutgoingMidiBuffers(uint8 newValue, uint16 nrpnType, OutgoingMidiBuffers* outgoingBuffers) {
        auto& midiParams{ MidiOptions::get() };
        auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(midiParams.channel(), nrpnType, newValue) };
        outgoingBuffers->aggregateOutgoingMidiBuffers(nrpnBuffer);
    }
};