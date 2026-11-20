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
	last_choice{ -1.0f },
	max_choice_threshold{ param_ptr->getNumSteps() > 15 ? 0.999f : 0.99f },
	min_choice_threshold{ param_ptr->getNumSteps() > 15 ? 0.0001f : 0.01f }
{
	if (param_ptr)
		param_ptr->addListener(this);
}

void Exp_Transmitter_A::parameterValueChanged(int /*param_index*/, float new_norm_val) {
	if (should_transmit(new_norm_val))
		triggerAsyncUpdate();
}

void Exp_Transmitter_A::handleAsyncUpdate() {
	if (app_p.exp_tx_allowed())
		transmit_change();
}

Exp_Transmitter_A::~Exp_Transmitter_A() {
	if (param_ptr)
		param_ptr->removeListener(this);
}
