#include "D_MIDI_Exp_Transmitter_A.h"

MIDI::Exp_Transmitter_A::Exp_Transmitter_A(Value param_value, MidiBuffer& outgoing_midi) :
	param_val{ param_value },
	outgoing_midi{ outgoing_midi }
{
	param_val.addListener(this);
}

void MIDI::Exp_Transmitter_A::valueChanged(Value& /*value*/) {
	transmit_change();
}

MIDI::Exp_Transmitter_A::~Exp_Transmitter_A() {
	param_val.removeListener(this);
}
