#pragma once

#include "C_MISC_A.h"

namespace MISC
{

	static const String allowed_chars_lfo_freq{ "abcdefgABCDEFG0123456789#:." };
	static const String allowed_chars_osc_shape{ "afiopqrstwAFIOPQRSTW0123456789/" };
	static const String allowed_chars_osc_slop{ "012345" };
	static const String allowed_chars_step{ "abcdefgABCDEFG0123456789#+<" };
	static const String allowed_chars_step_t_1{ "abcdefgABCDEFG0123456789#+<." };

	static const double editor_aspect_ratio{ 2.03354 };

	static const float knb_angle_0{ degreesToRadians(45.0f) };
	static const float knb_angle_1{ degreesToRadians(315.0f) };

	static const int lfo_1st_pitch_freq{ 90 };
	static const int lfo_1st_sync_freq{ 151 };

	static const int mod_dst_count{ 47 };
	static const int mod_src_count{ 23 };

	static const int seq_2_4_dst_count{ 48 };

}
