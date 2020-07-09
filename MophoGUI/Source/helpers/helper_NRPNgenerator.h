#pragma once

#include <JuceHeader.h>



// In the MidiBuffer created by Juce's MidiRPNGenerator, the LSB
// messages come before the MSB messages. However, the Mopho sends
// out NRPN messages with the MSBs before the LSBs, and I think the
// NRPN messages sent to it should be ordered in the same way.
struct NRPNbufferWithLeadingMSBsGenerator
{
    static MidiBuffer generateFrom_NRPNindex_NewValue_andChannel(uint16 paramNRPN, uint8 newValue, uint8 midiChannel) {
        MidiBuffer nrpnBuffer;
        nrpnBuffer.addEvent(createNRPNindexMSBmessageForMidiChannel(paramNRPN, midiChannel), 0);
        nrpnBuffer.addEvent(createNRPNindexLSBmessageForMidiChannel(paramNRPN, midiChannel), 1);
        nrpnBuffer.addEvent(createNRPNvalueMSBmessageForMidiChannel(newValue, midiChannel), 2);
        nrpnBuffer.addEvent(createNRPNvalueLSBmessageForMidiChannel(newValue, midiChannel), 3);
        return nrpnBuffer;
    }

private:
    static MidiMessage createNRPNindexMSBmessageForMidiChannel(uint16 paramNRPN, uint8 midiChannel) {
        auto firstByte{ 176 + midiChannel };
        return MidiMessage(firstByte, 99, paramNRPN / 128);
    }

    static MidiMessage createNRPNindexLSBmessageForMidiChannel(uint16 paramNRPN, uint8 midiChannel) {
        auto firstByte{ 176 + midiChannel };
        return MidiMessage(firstByte, 98, paramNRPN % 128);
    }

    static MidiMessage createNRPNvalueMSBmessageForMidiChannel(uint8 newValue, uint8 midiChannel) {
        auto firstByte{ 176 + midiChannel };
        return MidiMessage(firstByte, 6, newValue / 128);
    }

    static MidiMessage createNRPNvalueLSBmessageForMidiChannel(uint8 newValue, uint8 midiChannel) {
        auto firstByte{ 176 + midiChannel };
        return MidiMessage(firstByte, 38, newValue % 128);
    }
};