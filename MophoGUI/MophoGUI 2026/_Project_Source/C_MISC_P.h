#pragma once

#include "C_MISC_A.h"

namespace MISC
{

	static const double editor_aspect_ratio{ 2.03354 };

	static const float rotary_sli_begin_angle{ degreesToRadians(45.0f) };
	static const float rotary_sli_end_angle{ degreesToRadians(315.0f) };

	static const int choice_count_mod_dest{ 47 };
	static const int choice_count_mod_src{ 23 };
	static const int choice_count_seq_track_2_4_dest{ 48 };
	static const int lfo_1st_pitch_freq{ 90 };
	static const int lfo_1st_sync_freq{ 151 };

	static const String allowed_chars_lfo_freq{ "abcdefgABCDEFG0123456789#:." };
	static const String allowed_chars_osc_shape{ "afiopqrstwAFIOPQRSTW0123456789/" };
	static const String allowed_chars_osc_slop{ "012345" };
	static const String allowed_chars_seq_step{ "abcdefgABCDEFG0123456789#+<" };
	static const String allowed_chars_seq_step_trk_1{ "abcdefgABCDEFG0123456789#+<." };

}
