#include "D_MIDI_Exp_Transmitter_A.h"

using namespace MIDI;
using namespace TREE;

Exp_Transmitter_A::Exp_Transmitter_A(Exp_Param* exp_param_ptr, MidiBuffer& outgoing_midi,
									 App_Params& app_p) :
	param_ptr{ exp_param_ptr },
	outgoing_midi{ outgoing_midi },
	app_p{ app_p },
	norm_range{ param_ptr->getNormalisableRange() },
	last_norm_val{ 0.5f },
	last_choice{ 0.0f },
	max_choice_threshold{ param_ptr->getNumSteps() > 15 ? 0.999f : 0.99f },
	min_choice_threshold{ param_ptr->getNumSteps() > 15 ? 0.001f : 0.01f }
{
	if (param_ptr)
		param_ptr->addListener(this);
}

void Exp_Transmitter_A::parameterValueChanged(int /*param_index*/, float new_norm_val) {
	auto v = norm_range.convertFrom0to1(new_norm_val);
	if (new_norm_val > last_norm_val) {
		if (new_norm_val < max_choice_threshold)
			v = std::floor(v);
		else
			v = std::ceil(v);
	}
	if (new_norm_val < last_norm_val) {
		if (new_norm_val > min_choice_threshold)
			v = std::ceil(v);
		else
			v = std::floor(v);
	}
	last_norm_val = new_norm_val;
	if (v != last_choice) {
 		last_choice = v;
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
