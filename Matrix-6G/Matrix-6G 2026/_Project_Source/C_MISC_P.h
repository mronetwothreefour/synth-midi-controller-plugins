#pragma once

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto editor_aspect_ratio = 2.10067;
	constexpr auto knb_angle_0 = degreesToRadians(225.0f);
	constexpr auto knb_angle_1 = degreesToRadians(495.0f);
	constexpr auto mod_dst_count = 33;
	constexpr auto mod_src_count = 21;

	static const tuple<string, int, string>
		txt_editor_traits_osc_pitch{ allowed_chars_pitch, 3, Tip_For::txt_editor_pitch(25, 0, 63) },
		txt_editor_traits_s_6_bit{ allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) },
		txt_editor_traits_u_6_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) };

}
