#pragma once

#include <JuceHeader.h>



// In the MidiBuffer created by Juce's MidiRPNGenerator, the LSB
// messages come before the MSB messages. However, the Mopho sends
// out NRPN messages with the MSBs before the LSBs, and I think the
// NRPN messages sent to it should be ordered in the same way.
struct NRPNbufferWithLeadingMSBs
{
    static MidiBuffer from_Channel_NRPNtype_NewValue(uint8 midiChannel, uint16 NRPNtype, uint8 newValue) {
        MidiBuffer nrpnBuffer;
        nrpnBuffer.addEvent(NRPNmessage1_Channel_TypeMSB(midiChannel, NRPNtype), 0);
        nrpnBuffer.addEvent(NRPNmessage2_Channel_TypeLSB(midiChannel, NRPNtype), 1);
        nrpnBuffer.addEvent(NRPNmessage3_Channel_ValueMSB(midiChannel, newValue), 2);
        nrpnBuffer.addEvent(NRPNmessage4_Channel_ValueLSB(midiChannel, newValue), 3);
        return nrpnBuffer;
    }

private:
    static const int firstByte{ 176 };

    static MidiMessage NRPNmessage1_Channel_TypeMSB(uint8 midiChannel, uint16 NRPNtype) {
        return MidiMessage(firstByte + midiChannel, 99, NRPNtype / 128);
    }

    static MidiMessage NRPNmessage2_Channel_TypeLSB(uint8 midiChannel, uint16 NRPNtype) {
        return MidiMessage(firstByte + midiChannel, 98, NRPNtype % 128);
    }

    static MidiMessage NRPNmessage3_Channel_ValueMSB(uint8 midiChannel, uint8 newValue) {
        return MidiMessage(firstByte + midiChannel, 6, newValue / 128);
    }

    static MidiMessage NRPNmessage4_Channel_ValueLSB(uint8 midiChannel, uint8 newValue) {
        return MidiMessage(firstByte + midiChannel, 38, newValue % 128);
    }
};
