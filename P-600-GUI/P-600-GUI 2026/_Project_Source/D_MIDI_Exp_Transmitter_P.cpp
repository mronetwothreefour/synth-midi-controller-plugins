#include "D_MIDI_Exp_Transmitter_P.h"

MIDI::Exp_Transmitter::Exp_Transmitter(const std::string& /*param_id*/, Value param_value,
									   MidiBuffer& outgoing_midi) :
	Exp_Transmitter_A{ param_value, outgoing_midi } 
{
}

void MIDI::Exp_Transmitter::transmit_change() {
}
