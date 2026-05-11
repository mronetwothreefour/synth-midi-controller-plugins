#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double gui_aspect_ratio{ 2.17778 };

	constexpr int ctrl_row_h{ 94 };
	constexpr int ctrl_row_1_y{ 103 };
	constexpr int ctrl_row_2_y{ ctrl_row_1_y + ctrl_row_h };
	constexpr int ctrl_row_3_y{ ctrl_row_2_y + ctrl_row_h };
	constexpr int gui_init_w{ 1176 }, gui_init_h{ 540 };
	constexpr int knob_diameter{ 34 };

}
