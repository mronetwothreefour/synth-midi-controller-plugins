#pragma once

#include <JuceHeader.h>

#include "midi_InternalMidiBuffers_Singleton.h"
#include "midi_NRPNbufferWithLeadingMSBs.h"
#include "../parameters/params_MidiOptions_Singleton.h"



struct ParameterChangeMessage {
	static void sendNewValueForNRPNtype(uint8 newValue, uint16 nrpnType) {
        auto& midiParams{ MidiOptions::get() };
        auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(midiParams.channel(), nrpnType, newValue) };
        InternalMidiBuffers::get().aggregateMidiBuffers(nrpnBuffer);
    }
};