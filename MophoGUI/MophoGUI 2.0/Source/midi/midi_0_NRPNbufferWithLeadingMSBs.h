#pragma once

#include <JuceHeader.h>

#include "../constants/constants_MIDI.h"

using namespace MophoConstants;

// In the MidiBuffer created by Juce's MidiRPNGenerator, the LSB
// messages come before the MSB messages. However, the Mopho sends
// out NRPN messages with the MSBs preceding the LSBs, and I think
// the NRPN messages sent to it should be ordered in the same way.
struct NRPNbufferWithLeadingMSBs
{
public:
    static MidiBuffer from_Channel_NRPNtype_NewValue(const uint8 midiChannel, const uint16 NRPNtype, const uint8 newValue) {
        MidiBuffer nrpnBuffer;
        nrpnBuffer.addEvent(NRPNmessage1_Channel_TypeMSB(midiChannel, NRPNtype), 0);
        nrpnBuffer.addEvent(NRPNmessage2_Channel_TypeLSB(midiChannel, NRPNtype), 1);
        nrpnBuffer.addEvent(NRPNmessage3_Channel_ValueMSB(midiChannel, newValue), 2);
        nrpnBuffer.addEvent(NRPNmessage4_Channel_ValueLSB(midiChannel, newValue), 3);
        return nrpnBuffer;
    }

private:
    static const int controllerFlag{ 0xB0 };
    static MidiMessage NRPNmessage1_Channel_TypeMSB(const uint8 midiChannel, const uint16 NRPNtype) {
        return MidiMessage(controllerFlag + midiChannel, MIDI::nrpnType_MSB, NRPNtype / 128);
    }

    static MidiMessage NRPNmessage2_Channel_TypeLSB(const uint8 midiChannel, const uint16 NRPNtype) {
        return MidiMessage(controllerFlag + midiChannel, MIDI::nrpnType_LSB, NRPNtype % 128);
    }

    static MidiMessage NRPNmessage3_Channel_ValueMSB(const uint8 midiChannel, const uint8 newValue) {
        return MidiMessage(controllerFlag + midiChannel, MIDI::nrpnValue_MSB, newValue / 128);
    }

    static MidiMessage NRPNmessage4_Channel_ValueLSB(const uint8 midiChannel, const uint8 newValue) {
        return MidiMessage(controllerFlag + midiChannel, MIDI::nrpnValue_LSB, newValue % 128);
    }
};
