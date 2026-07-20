#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double editor_aspect_ratio{ 3.42347 };

	constexpr float rotary_slider_begin_angle{ degreesToRadians(30.0f) };
	constexpr float rotary_slider_end_angle{ degreesToRadians(330.0f) };

	constexpr int editor_init_w{ 1342 }, editor_init_h{ 392 };

	const auto filter_amp_col_spacing{ 75 };
	const auto filter_amp_col_1_x{ 1057 };
	const auto filter_amp_col_2_x{ filter_amp_col_1_x + filter_amp_col_spacing };
	const auto filter_amp_col_3_x{ filter_amp_col_2_x + filter_amp_col_spacing };
	const auto filter_amp_col_4_x{ filter_amp_col_3_x + filter_amp_col_spacing };

	constexpr int knob_diam{ 34 };
	constexpr int knob_row_1_y{ 67 };
	constexpr int knob_row_2_y{ 170 };
	constexpr int knob_row_3_y{ 308 };

	constexpr int mixer_glide_col_x{ 939 };

	constexpr int osc_col_1_x{ 493 };
	constexpr int osc_col_2_x{ 569 };
	constexpr int osc_col_3_x{ 628 };
	constexpr int osc_col_4_x{ 688 };
	constexpr int osc_col_5_x{ 748 };
	constexpr int osc_col_6_x{ 817 };

	constexpr int switch_2_pole_h{ 32 };
	constexpr int switch_2_pole_w{ 20 };
	constexpr int switch_3_pole_h{ 48 };
	constexpr int switch_3_pole_w{ 46 };
	constexpr int switch_row_1_y{ 177 };
	constexpr int switch_row_2_y{ 315 };

}