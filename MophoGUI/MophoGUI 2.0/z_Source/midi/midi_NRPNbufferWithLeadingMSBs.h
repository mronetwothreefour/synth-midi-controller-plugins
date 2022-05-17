#pragma once

#include <JuceHeader.h>



// In the MidiBuffer created by Juce's MidiRPNGenerator, the LSB
// messages come before the MSB messages. However, the Mopho sends
// out NRPN messages with the MSBs before the LSBs, and I think the
// NRPN messages sent to it should be ordered in the same way.
struct NRPNbufferWithLeadingMSBs
{
public:
    static MidiBuffer from_Channel_NRPNtype_NewValue(uint8 midiChannel, uint16 NRPNtype, uint8 newValue);

private:
    static MidiMessage NRPNmessage1_Channel_TypeMSB(uint8 midiChannel, uint16 NRPNtype);
    static MidiMessage NRPNmessage2_Channel_TypeLSB(uint8 midiChannel, uint16 NRPNtype);
    static MidiMessage NRPNmessage3_Channel_ValueMSB(uint8 midiChannel, uint8 newValue);
    static MidiMessage NRPNmessage4_Channel_ValueLSB(uint8 midiChannel, uint8 newValue);
};
