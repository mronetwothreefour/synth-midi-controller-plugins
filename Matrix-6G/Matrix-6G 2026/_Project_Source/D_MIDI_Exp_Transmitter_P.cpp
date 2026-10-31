#include "D_MIDI_Exp_Transmitter_P.h"

#include "C_GET_P.h"
#include "D_MIDI_Msg_P.h"

using namespace MIDI;
using namespace TREE;

Exp_Transmitter::Exp_Transmitter(const std::string& param_id, Value param_value,
								 MidiBuffer& outgoing_midi, App_Params& app_p) :
	Exp_Transmitter_A{ param_value, outgoing_midi, app_p },
	quick_num{ (uint8)GET::quick_num_for(param_id) },
	range_is_s_6_bit{ GET::range_is_s_6_bit_for(param_id) },
	range_is_s_7_bit{ GET::range_is_s_7_bit_for(param_id) }
{}

void Exp_Transmitter::transmit_change() {
	auto v = (int)param_val.getValue();
	if (range_is_s_6_bit)
		v -= 31;
	if (range_is_s_7_bit)
		v -= 63;
	if (v > -1)
		outgoing_midi.addEvent(Msg::quick_edit_param(quick_num, (uint8)v), 0);
}
