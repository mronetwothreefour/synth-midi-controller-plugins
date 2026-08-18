#pragma once

#include "C_MISC_A.h"

namespace MISC
{

	constexpr double editor_aspect_ratio{ 2.03354 };

	constexpr float rotary_sli_begin_angle{ degreesToRadians(45.0f) };
	constexpr float rotary_sli_end_angle{ degreesToRadians(315.0f) };

	constexpr int lfo_1st_pitch_freq{ 90 };
	constexpr int lfo_1st_sync_freq{ 151 };

	static const String allowed_chars_lfo_freq{ "abcdefgABCDEFG0123456789#:." };
	static const String allowed_chars_osc_shape{ "afiopqrstwAFIOPQRSTW0123456789/" };
	static const String allowed_chars_osc_slop{ "012345" };
	static const String allowed_chars_seq_step{ "abcdefgABCDEFG0123456789#+<" };
	static const String allowed_chars_seq_step_trk_1{ "abcdefgABCDEFG0123456789#+<." };

}
