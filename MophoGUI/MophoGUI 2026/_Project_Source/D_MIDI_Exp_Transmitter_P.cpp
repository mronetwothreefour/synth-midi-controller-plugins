#include "D_MIDI_Exp_Transmitter_P.h"

#include "C_GET_P.h"
#include "D_MIDI_Msg_P.h"

using namespace MIDI;
using namespace TREE;

Exp_Transmitter::Exp_Transmitter(const std::string& param_id, Exp_Param* exp_param_ptr,
								 MidiBuffer& outgoing_midi, App_Params& app_p) :
	Exp_Transmitter_A{ exp_param_ptr, outgoing_midi, app_p },
	nrpn{ GET::nrpn_for(param_id) }
{}

bool Exp_Transmitter::should_transmit(const float new_norm_val) {
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
		return true;
	}
	return false;
}

void Exp_Transmitter::transmit_change() {
	auto v = (uint8)roundToInt(last_choice);
	// TO DO: get current MIDI channel (0..15)
	outgoing_midi.addEvents(Msg::nrpn_param_change((uint8)0, nrpn, v), 0, -1, 0);
}
