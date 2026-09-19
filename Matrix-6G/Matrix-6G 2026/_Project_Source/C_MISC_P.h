#pragma once

#include "C_MISC_A.h"

namespace MISC
{

	constexpr auto editor_aspect_ratio = 2.10067;
	constexpr auto knb_angle_0 = degreesToRadians(225.0f);
	constexpr auto knb_angle_1 = degreesToRadians(495.0f);
	constexpr auto mod_dst_count = 33;
	constexpr auto mod_src_count = 21;

	static const tuple<bool, int, int> menu_traits_false_1_2{ false, 1, 2 };
	static const tuple<bool, int, int> menu_traits_false_1_3{ false, 1, 3 };
	static const tuple<bool, int, int> menu_traits_false_1_4{ false, 1, 4 };
	static const tuple<bool, int, int> menu_traits_false_1_7{ false, 1, 7 };
	static const tuple<bool, int, int> menu_traits_false_3_7{ false, 3, 7 };
	static const tuple<bool, int, int> menu_traits_false_3_11{ false, 3, 11 };
	static const tuple<bool, int, int> menu_traits_true_1_3{ true, 1, 3 };
	static const tuple<bool, int, int> menu_traits_true_1_4{ true, 1, 4 };
	static const tuple<bool, int, int> menu_traits_true_1_8{ true, 1, 8 };

	static const tuple<string, int, string>
		txt_editor_traits_osc_pitch{ allowed_chars_pitch, 3, Tip_For::txt_editor_pitch(25, 0, 63) },
		txt_editor_traits_s_6_bit{ allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(63) },
		txt_editor_traits_u_6_bit{ allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(63) };

}
