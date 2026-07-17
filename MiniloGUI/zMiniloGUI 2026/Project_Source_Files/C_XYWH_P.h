#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double gui_aspect_ratio{ 2.17778 };

	constexpr float rotary_slider_end_angle{ degreesToRadians(330.0f) };
	constexpr float rotary_slider_start_angle{ degreesToRadians(30.0f) };

	constexpr int ctrl_row_h{ 94 };
	constexpr int ctrl_row_1_y{ 103 };
	constexpr int ctrl_row_2_y{ ctrl_row_1_y + ctrl_row_h };
	constexpr int ctrl_row_3_y{ ctrl_row_2_y + ctrl_row_h };

	constexpr int env_knob_spacing{ 68 };
	constexpr int env_knob_a_x{ 559 };
	constexpr int env_knob_d_x{ env_knob_a_x + env_knob_spacing };
	constexpr int env_knob_s_x{ env_knob_d_x + env_knob_spacing };
	constexpr int env_knob_r_x{ env_knob_s_x + env_knob_spacing };

	constexpr int gui_init_w{ 1176 }, gui_init_h{ 540 };

	constexpr int knob_diameter{ 34 };
	constexpr int knob_diameter_lpf_freq{ 50 };
	
	constexpr int switch_h{ 52 };
	constexpr int switch_lpf_type_h{ 84 };
	constexpr int switch_w{ 34 };

}
