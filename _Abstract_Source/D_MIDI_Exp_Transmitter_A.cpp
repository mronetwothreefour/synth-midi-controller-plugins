#include "D_MIDI_Exp_Transmitter_A.h"

using namespace TREE;

MIDI::Exp_Transmitter_A::Exp_Transmitter_A(Value param_value, MidiBuffer& outgoing_midi, 
										   App_Params& app_p) :
	param_val{ param_value },
	outgoing_midi{ outgoing_midi },
	app_p{ app_p }
{
	param_val.addListener(this);
}

void MIDI::Exp_Transmitter_A::valueChanged(Value& /*value*/) {
	if (app_p.exp_tx_allowed())
		transmit_change();
}

MIDI::Exp_Transmitter_A::~Exp_Transmitter_A() {
	param_val.removeListener(this);
}
