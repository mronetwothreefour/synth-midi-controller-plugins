#include "midi_NRPNbufferWithLeadingMSBs.h"

#include "midi_Constants.h"

using namespace constants;



MidiBuffer NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(uint8 midiChannel, uint16 NRPNtype, uint8 newValue) {
    MidiBuffer nrpnBuffer;
    nrpnBuffer.addEvent(NRPNmessage1_Channel_TypeMSB(midiChannel, NRPNtype), 0);
    nrpnBuffer.addEvent(NRPNmessage2_Channel_TypeLSB(midiChannel, NRPNtype), 1);
    nrpnBuffer.addEvent(NRPNmessage3_Channel_ValueMSB(midiChannel, newValue), 2);
    nrpnBuffer.addEvent(NRPNmessage4_Channel_ValueLSB(midiChannel, newValue), 3);
    return nrpnBuffer;
}

MidiMessage NRPNbufferWithLeadingMSBs::NRPNmessage1_Channel_TypeMSB(uint8 midiChannel, uint16 NRPNtype) {
    return MidiMessage(MIDI::controllerFlag + midiChannel, MIDI::nrpnTypeMSB, NRPNtype / 128);
}

MidiMessage NRPNbufferWithLeadingMSBs::NRPNmessage2_Channel_TypeLSB(uint8 midiChannel, uint16 NRPNtype) {
    return MidiMessage(MIDI::controllerFlag + midiChannel, MIDI::nrpnTypeLSB, NRPNtype % 128);
}

MidiMessage NRPNbufferWithLeadingMSBs::NRPNmessage3_Channel_ValueMSB(uint8 midiChannel, uint8 newValue) {
    return MidiMessage(MIDI::controllerFlag + midiChannel, MIDI::nrpnValueMSB, newValue / 128);
}

MidiMessage NRPNbufferWithLeadingMSBs::NRPNmessage4_Channel_ValueLSB(uint8 midiChannel, uint8 newValue) {
    return MidiMessage(MIDI::controllerFlag + midiChannel, MIDI::nrpnValueLSB, newValue % 128);
}
