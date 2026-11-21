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

bool Exp_Transmitter::should_transmit(const float /*new_norm_val*/) {
	return false;
}

void Exp_Transmitter::transmit_change() {
	auto v = (uint8)roundToInt(last_choice);
	outgoing_midi.addEvents(Msg::nrpn_param_change((uint8)0, nrpn, v), 0, -1, 0);
}
