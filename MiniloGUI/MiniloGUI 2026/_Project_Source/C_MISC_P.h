#pragma once

#include <JuceHeader.h>

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto allowed_chars_vmode_poly = "012345678";

	constexpr auto editor_aspect_ratio = 2.17778;

	constexpr auto knb_angle_0 = degreesToRadians(30.0f);
	constexpr auto knb_angle_1 = degreesToRadians(330.0f);

	static const tuple<string, int, string>
		txt_editor_traits_flex_sli_bend{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(12) },
		txt_editor_traits_osc_pitch_fine{ allowed_chars_s_int, 5, Tip_For::txt_editor_s_int(1200) },
		txt_editor_traits_u_10_bit{ allowed_chars_u_int, 4, Tip_For::txt_editor_u_int(1023) };

}
