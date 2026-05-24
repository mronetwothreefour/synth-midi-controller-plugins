#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double gui_aspect_ratio{ 2.03354 };

	constexpr int gui_init_w{ 1273 }, gui_init_h{ 626 };

	constexpr int cbox_h{ 16 };
	constexpr int knob_diameter{ 40 };
	constexpr int toggle_center_offset{ 1 };
	constexpr int toggle_diameter{ 14 };

	constexpr int ctrl_col_w{ knob_diameter + 5 };
	constexpr int ctrl_col_1_x{ 48 };
	constexpr int ctrl_col_2_x{ ctrl_col_1_x + ctrl_col_w };
	constexpr int ctrl_col_3_x{ ctrl_col_2_x + ctrl_col_w };
	constexpr int ctrl_col_4_x{ ctrl_col_3_x + ctrl_col_w };
	constexpr int ctrl_col_5_x{ ctrl_col_4_x + ctrl_col_w };
	constexpr int ctrl_col_6_x{ ctrl_col_5_x + ctrl_col_w };
	constexpr int ctrl_col_7_x{ ctrl_col_6_x + ctrl_col_w };
	constexpr int ctrl_col_8_x{ ctrl_col_7_x + ctrl_col_w };
	constexpr int ctrl_col_9_x{ ctrl_col_8_x + ctrl_col_w };
	constexpr int ctrl_col_10_x{ 500 };

	const int env_3_row_1_y{ 531 };
	const int env_3_row_2_y{ 583 };

	const int lfo_1_cbox_x{ 463 };
	const int lfo_cbox_w{ 134 };
	const int lfo_row_1_y{ 515 };
	const int lfo_row_2_y{ 560 };
	const int lfo_row_3_y{ 594 };
	const int lfo_block_spacing{ 155 };

	constexpr int lpf_row_1_y{ 167 };
	constexpr int lpf_row_2_y{ 215 };
	constexpr int lpf_row_3_y{ 267 };

	constexpr int osc_cbox_w{ 124 };
	constexpr int osc_row_h{ 60 };
	constexpr int osc_row_1_y{ 50 };
	constexpr int osc_row_2_y{ osc_row_1_y + osc_row_h };

	constexpr int vca_row_1_y{ 373 };
	constexpr int vca_row_2_y{ 425 };
}
