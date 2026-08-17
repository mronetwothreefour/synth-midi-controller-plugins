#pragma once

#include "C_NAME_A.h"

namespace NAME
{

	static const String allowed_char_pitch{ "abcdefgABCDEFG0123456789#" };
	static const String allowed_char_lfo_freq{ "abcdefgABCDEFG0123456789#:." };
	static const String allowed_char_osc_shape{ "afiopqrstwAFIOPQRSTW0123456789/" };
	static const String allowed_char_osc_slop{ "012345" };
	static const String allowed_char_seq_step{ "abcdefgABCDEFG0123456789#+<" };
	static const String allowed_char_seq_step_trk_1{ "abcdefgABCDEFG0123456789#+<." };

	static const String lbl_bend_range{ "lbl_bend_range" };
	static const String lbl_clock_tempo{ "lbl_clock_tempo" };
	static const String lbl_lfo_freq{ "lbl_lfo_freq" };
	static const String lbl_lpf_freq{ "lbl_lpf_freq" };
	static const String lbl_osc_fine{ "lbl_osc_fine" };
	static const String lbl_osc_shape{ "lbl_osc_shape" };
	static const String lbl_osc_slop{ "lbl_osc_slop" };
	static const String lbl_seq_step{ "lbl_seq_step" };
	static const String lbl_seq_step_trk_1{ "lbl_seq_step_trk_1" };
	static const String lbl_s_8_bit_int{ "lbl_s_8_bit_int" };
	static const String lbl_u_7_bit_int{ "lbl_u_7_bit_int" };
	static const String lbl_voice_name_char{ "lbl_voice_name_char" };
	static const String knob_osc_shape{ "knob_osc_shape" };
	static const String seq_step{ "seq_step" };
	static const String seq_step_trk_1{ "seq_step_trk_1" };
	static const String voice_name_char{ "voice_name_char" };

}
