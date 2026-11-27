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
	lower_threshold{ 0.95f },
	upper_threshold{ 0.05f }
{
	if (param_ptr)
		param_ptr->addListener(this);
}

bool MIDI::Exp_Transmitter_A::should_transmit(const float new_norm_val) {
	if (should_transmit_p(new_norm_val)) {
		auto unsnapped_val = norm_range.convertFrom0to1(new_norm_val);
		auto int_part = 0.0f;
		auto fract_part = std::modf(unsnapped_val, &int_part);
		if (fract_part > lower_threshold || fract_part < upper_threshold) {
			auto snapped_val = param_ptr->convertFrom0to1(new_norm_val);
			last_norm_val = new_norm_val;
			if (snapped_val != last_choice) {
				last_choice = snapped_val;
				return true;
			}
		}
	}
	return false;
}

bool MIDI::Exp_Transmitter_A::should_transmit_p(const float /*new_norm_val*/) {
	return true;
}

void Exp_Transmitter_A::parameterValueChanged(int /*param_index*/, float new_norm_val) {
	if (should_transmit(new_norm_val) && app_p.exp_tx_allowed())
		triggerAsyncUpdate();
}

void Exp_Transmitter_A::handleAsyncUpdate() {
	transmit_change();
}

Exp_Transmitter_A::~Exp_Transmitter_A() {
	if (param_ptr)
		param_ptr->removeListener(this);
}
