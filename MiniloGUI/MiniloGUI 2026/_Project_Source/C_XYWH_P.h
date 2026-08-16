#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double editor_aspect_ratio{ 2.17778 };

	constexpr float env_init_begin_x{ 839.0f };
	constexpr float env_init_end_x{ 931.0f };
	constexpr float env_init_max_y{ 174.0f };
	constexpr float env_init_min_y{ 218.0f };
	constexpr float env_stage_init_max_w{ 24.0f };
	constexpr float env_sustain_init_w{ 20.0f };

	constexpr float rotary_sli_begin_angle{ degreesToRadians(30.0f) };
	constexpr float rotary_sli_end_angle{ degreesToRadians(330.0f) };

	constexpr int ctrl_row_h{ 94 };
	constexpr int ctrl_row_1_y{ 103 };
	constexpr int ctrl_row_2_y{ ctrl_row_1_y + ctrl_row_h };
	constexpr int ctrl_row_3_y{ ctrl_row_2_y + ctrl_row_h };

	constexpr int editor_init_w{ 1176 }, editor_init_h{ 540 };

	constexpr int env_knob_spacing{ 68 };
	constexpr int env_knob_a_x{ 559 };
	constexpr int env_knob_d_x{ env_knob_a_x + env_knob_spacing };
	constexpr int env_knob_s_x{ env_knob_d_x + env_knob_spacing };
	constexpr int env_knob_r_x{ env_knob_s_x + env_knob_spacing };

	constexpr int knob_diam{ 34 };
	constexpr int knob_diam_lpf_freq{ 50 };

	constexpr int switch_h{ 52 };
	constexpr int switch_lpf_type_h{ 84 };
	constexpr int switch_w{ 34 };

	static Rectangle<int> env_backdrop_init_bounds{ 834, 167, 102, 58 };
	static Rectangle<int> trig_area_env_init_bounds{ 542, 180, 238, 34 };
	static Rectangle<int> trig_area_vca_env_init_bounds{ 542, 86, 238, 34 };

}
