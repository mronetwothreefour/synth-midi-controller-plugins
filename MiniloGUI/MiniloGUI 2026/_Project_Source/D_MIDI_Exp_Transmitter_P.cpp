#include "D_MIDI_Exp_Transmitter_P.h"

using namespace TREE;

MIDI::Exp_Transmitter::Exp_Transmitter(const std::string& /*param_id*/, Value param_value,
									   MidiBuffer& outgoing_midi, App_Params& app_p) :
	Exp_Transmitter_A{ param_value, outgoing_midi, app_p }
{
}

void MIDI::Exp_Transmitter::transmit_change() {
}
