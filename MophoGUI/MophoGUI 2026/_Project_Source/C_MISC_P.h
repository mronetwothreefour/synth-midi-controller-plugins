#pragma once

#include <JuceHeader.h>

#include "C_MISC_A.h"
#include "C_SL_Tip_Widget_P.h"

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

	static const tuple<bool, int, int, bool> menu_above_1x5{ true, 1, 5, false };
	static const tuple<bool, int, int, bool> menu_above_3x16{ true, 3, 16, false };
	static const tuple<bool, int, int, bool> menu_above_3x16_to_left{ true, 3, 16, true };
	static const tuple<bool, int, int, bool> menu_above_5x34_to_left{ true, 5, 34, true };
	static const tuple<bool, int, int, bool> menu_above_6x29{ true, 6, 29, false };
	static const tuple<bool, int, int, bool> menu_below_2x12{ false, 2, 12, false };
	static const tuple<bool, int, int, bool> menu_below_3x16{ false, 3, 16, false };
	static const tuple<bool, int, int, bool> menu_below_3x16_to_left{ false, 3, 16, true };
	static const tuple<string, int, string>
		txt_editor_traits_lfo_freq{ allowed_chars_lfo_freq, 5, Tip_For::from_SL(SL::edit_lfo_freq_tip) },
		txt_editor_traits_osc_fine_tune{ allowed_chars_s_int, 3, Tip_For::txt_editor_s_int(50) },
		txt_editor_traits_osc_pitch{ allowed_chars_pitch, 4, Tip_For::txt_editor_pitch(61, 0, 120) },
		txt_editor_traits_osc_shape{ allowed_chars_osc_shape, 4, Tip_For::from_SL(SL::edit_osc_shape_tip) },
		txt_editor_traits_s_8_bit{ allowed_chars_s_int, 4, Tip_For::txt_editor_s_int(127) },
		txt_editor_traits_step{ allowed_chars_step, 4, Tip_For::from_SL(SL::edit_seq_step_tip) },
		txt_editor_traits_step_t_1{ allowed_chars_step_t_1, 4, Tip_For::from_SL(SL::edit_seq_step_track_1_tip) };
}
