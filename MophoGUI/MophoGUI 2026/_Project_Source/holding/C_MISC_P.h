#pragma once

#include <JuceHeader.h>

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto allowed_chars_lfo_freq = "abcdefgABCDEFG0123456789#:.";
	constexpr auto allowed_chars_osc_shape = "afiopqrstwAFIOPQRSTW0123456789/";
	constexpr auto allowed_chars_osc_slop = "012345";
	constexpr auto allowed_chars_step = "abcdefgABCDEFG0123456789#+<";
	constexpr auto allowed_chars_step_t_1 = "abcdefgABCDEFG0123456789#+<.";

	constexpr auto editor_aspect_ratio = 2.03354;

	constexpr auto knb_angle_0 = degreesToRadians(45.0f);
	constexpr auto knb_angle_1 = degreesToRadians(315.0f);

	constexpr auto lfo_1st_pitch_freq = 90;
	constexpr auto lfo_1st_sync_freq = 151;

	constexpr auto mod_dst_count = 47;
	constexpr auto mod_src_count = 23;

	constexpr auto seq_2_4_dst_count = 48;

}
