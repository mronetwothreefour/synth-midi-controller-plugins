#include "D_MIDI_Exp_Transmitter_P.h"

#include "C_GET_P.h"
#include "D_MIDI_Msg_P.h"

using namespace MIDI;
using namespace TREE;

Exp_Transmitter::Exp_Transmitter(const std::string& param_id, Exp_Param* exp_param_ptr,
								 MidiBuffer& outgoing_midi, App_Params& app_p) :
	Exp_Transmitter_A{ exp_param_ptr, outgoing_midi, app_p },
	quick_num{ (uint8)GET::quick_num_for(param_id) },
	range_is_s_6_bit{ GET::range_is_s_6_bit_for(param_id) },
	range_is_s_7_bit{ GET::range_is_s_7_bit_for(param_id) },
	range_is_signed{ range_is_s_6_bit || range_is_s_7_bit }
{}

bool Exp_Transmitter::should_transmit_p(const float new_norm_val) {
	if (range_is_signed && new_norm_val < 0.5f) {
		last_norm_val = new_norm_val;
		return false;
	}
	return true;
}

void Exp_Transmitter::transmit_change() {
	auto v = (uint8)roundToInt(last_choice);
	if (range_is_s_6_bit)
		v -= 31;
	if (range_is_s_7_bit)
		v -= 63;
	if (v > -1)
		outgoing_midi.addEvent(Msg::quick_edit_param(quick_num, v), 0);
}
