#pragma once

#include "C_ID_G.h"

namespace ID
{

	static const String allowed_char_lfo_freq{ "abcdefgABCDEFG0123456789#:." };
	static const String allowed_char_osc_shape{ "afiopqrstwAFIOPQRSTW0123456789/" };
	static const String allowed_char_osc_slop{ "012345" };
	static const String allowed_char_seq_step{ "abcdefgABCDEFG0123456789#+<" };
	static const String allowed_char_seq_step_trk_1{ "abcdefgABCDEFG0123456789#+<." };

	// exposed parameter properties
	static const String exp_p_byte_index{ "exp_p_byte_index" };
	static const String exp_p_nrpn{ "exp_p_nrpn" };
	static const String exp_p_packed_bits_byte_index{ "exp_p_packed_bits_byte_index" };
	static const String exp_p_packed_bits_mask{ "exp_p_packed_bits_mask" };
	static const String exp_p_red_toggle_cntr_x{ "exp_p_red_toggle_center_x" };
	static const String exp_p_red_toggle_cntr_y{ "exp_p_red_toggle_center_y" };

	static const String knob_osc_shape{ "knob_osc_shape" };
	static const String knob_seq_step{ "knob_seq_step" };
	static const String knob_seq_step_trk_1{ "knob_seq_step_trk_1" };

	static const String label_osc_shape{ "label_osc_shape" };
	static const String label_seq_step{ "label_seq_step" };
	static const String label_voice_name_char{ "label_voice_name_char" };

	static const String toggle_red{ "toggle_red" };

}