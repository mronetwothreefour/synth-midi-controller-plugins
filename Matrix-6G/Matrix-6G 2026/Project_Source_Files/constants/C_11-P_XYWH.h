#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double gui_aspect_ratio{ 2.10067  };

	constexpr int choice_menu_col_count_6_bit{ 8 };
	constexpr int choice_menu_col_count_7_bit{ 16 };
	constexpr int choice_menu_col_w_6_bit{ 16 };
	constexpr int choice_menu_col_w_7_bit{ 22 };
	constexpr int choice_menu_col_w_signed{ 26 };
	constexpr int choice_menu_row_count_numeric{ 8 };

	constexpr int ctrl_h{ 20 };
	constexpr int ctrl_row_h{ 28 };
	constexpr int ctrl_row_01_y{ 69 };
	constexpr int ctrl_row_02_y{ ctrl_row_01_y + ctrl_row_h };
	constexpr int ctrl_row_03_y{ ctrl_row_02_y + ctrl_row_h };
	constexpr int ctrl_row_04_y{ ctrl_row_03_y + ctrl_row_h };
	constexpr int ctrl_row_05_y{ ctrl_row_04_y + ctrl_row_h };
	constexpr int ctrl_row_06_y{ ctrl_row_05_y + ctrl_row_h };
	constexpr int ctrl_row_07_y{ ctrl_row_06_y + ctrl_row_h };
	constexpr int ctrl_row_08_y{ ctrl_row_07_y + ctrl_row_h };
	constexpr int ctrl_row_09_y{ ctrl_row_08_y + ctrl_row_h };
	constexpr int ctrl_row_10_y{ ctrl_row_09_y + ctrl_row_h };
	constexpr int ctrl_row_11_y{ ctrl_row_10_y + ctrl_row_h };
	constexpr int ctrl_row_12_y{ ctrl_row_11_y + ctrl_row_h };
	constexpr int gui_init_w{ 1252 }, gui_init_h{ 596 };

	constexpr int osc_col_1_x{ 130 };
	constexpr int osc_col_2_x{ 196 };
	constexpr int osc_ctrl_w{ 60 };
	constexpr int osc_col_1_choice_menu_x{ 166 };
	constexpr int osc_col_2_choice_menu_x{ 232 };

}