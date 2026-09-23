#pragma once

#include <JuceHeader.h>

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto editor_aspect_ratio = 3.42347;

	constexpr auto knb_angle_0 = degreesToRadians(30.0f);
	constexpr auto knb_angle_1 = degreesToRadians(330.0f);

	static const tuple<string, int, string>
		txt_editor_traits_osc_pitch{ allowed_chars_pitch, 3, Tip_For::txt_editor_pitch(37, 0, 48) },
		txt_editor_traits_u_4_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(15) },
		txt_editor_traits_u_5_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(31) },
		txt_editor_traits_u_6_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) };

}
