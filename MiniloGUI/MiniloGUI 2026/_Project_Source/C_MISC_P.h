#pragma once

#include <JuceHeader.h>

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto allowed_chars_vmode_poly = "012345678";

	constexpr auto editor_aspect_ratio = 2.17778;

	constexpr auto knb_angle_0 = degreesToRadians(30.0f);
	constexpr auto knb_angle_1 = degreesToRadians(330.0f);

	static const tuple<bool, int, int, bool, int>
		init_sli_traits_flex_sli_bend{ false, 1, 1, false, 1 },
		init_sli_traits_osc_pitch_fine{ true, 25, 100, true, 0 },
		init_sli_traits_u_7_bit{ false, 5, 10, false, 0 },
		init_sli_traits_u_10_bit{ false, 25, 100, false, 0 };

	static const tuple<string, int, string>
		txt_editor_traits_flex_sli_bend_neg{ allowed_chars_u_int, 2, Tip_For::avp_flex_sli_bend() },
		txt_editor_traits_flex_sli_bend_pos{ allowed_chars_u_int, 2, Tip_For::avp_flex_sli_bend(true) },
		txt_editor_traits_osc_pitch_fine{ allowed_chars_s_int, 5, Tip_For::txt_editor_s_int(1200) },
		txt_editor_traits_u_10_bit{ allowed_chars_u_int, 4, Tip_For::txt_editor_u_int(1023) };

}
