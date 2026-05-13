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

	constexpr int osc_cbox_w{ 124 };
	constexpr int osc_row_h{ 60 };
	constexpr int osc_row_1_center_y{ 50 };
	constexpr int osc_row_2_center_y{ osc_row_1_center_y + osc_row_h };
	constexpr int osc_row_1_knob_top_y{ osc_row_1_center_y - knob_diameter / 2 };
	constexpr int osc_row_2_knob_top_y{ osc_row_1_knob_top_y + osc_row_h };

}
