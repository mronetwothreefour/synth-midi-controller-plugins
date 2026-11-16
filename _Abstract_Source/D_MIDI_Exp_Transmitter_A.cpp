#include "D_MIDI_Exp_Transmitter_A.h"

using namespace TREE;

MIDI::Exp_Transmitter_A::Exp_Transmitter_A(const String& param_id, AudioProcessorValueTreeState* exp_state, MidiBuffer& outgoing_midi,
	App_Params& app_p) :
	param_id{ param_id },
	state{ exp_state },
	outgoing_midi{ outgoing_midi },
	app_p{ app_p }
{
	auto param_ptr = state->getParameter(param_id);
	if (param_ptr)
		param_ptr->addListener(this);
}

void MIDI::Exp_Transmitter_A::parameterValueChanged(int /*param_index*/, float new_val) {
	if (app_p.exp_tx_allowed()) {
		auto v = state->getParameter(param_id)->convertFrom0to1(new_val);
		transmit_change((uint8)roundToInt(v));
	}
}

MIDI::Exp_Transmitter_A::~Exp_Transmitter_A() {
	auto param_ptr = state->getParameter(param_id);
	if (param_ptr)
		param_ptr->removeListener(this);
}
