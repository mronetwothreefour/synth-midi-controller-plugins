#include "D_MIDI_Exp_Transmitter_A.h"

using namespace MIDI;
using namespace TREE;

Exp_Transmitter_A::Exp_Transmitter_A(Exp_Param* exp_param_ptr, MidiBuffer& outgoing_midi,
									 App_Params& app_p) :
	param_ptr{ exp_param_ptr },
	outgoing_midi{ outgoing_midi },
	app_p{ app_p },
	norm_range{ param_ptr->getNormalisableRange() },
	val_buf{ 0.0f }
{
	if (param_ptr)
		param_ptr->addListener(this);
}

void Exp_Transmitter_A::parameterValueChanged(int /*param_index*/, float new_val) {
	auto v = norm_range.convertFrom0to1(new_val);
	if (new_val < 0.99f)
		v = std::floor(v);
	if (v != val_buf) {
 		val_buf = v;
		triggerAsyncUpdate();
	}
}

void Exp_Transmitter_A::handleAsyncUpdate() {
	if (app_p.exp_tx_allowed())
		transmit_change();
}

Exp_Transmitter_A::~Exp_Transmitter_A() {
	if (param_ptr)
		param_ptr->removeListener(this);
}
