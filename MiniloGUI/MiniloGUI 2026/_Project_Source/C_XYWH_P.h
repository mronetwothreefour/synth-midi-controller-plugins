#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr auto cbox_h = 16;
	constexpr auto cbox_item_h = cbox_h - 2;
	constexpr auto ctr_row_h = 94;
	constexpr auto ctr_row_1_cy = 103;
	constexpr auto ctr_row_2_cy = ctr_row_1_cy + ctr_row_h;
	constexpr auto ctr_row_3_cy = ctr_row_2_cy + ctr_row_h;
	constexpr auto ctr_row_4_cy = 449;

	constexpr auto editor_init_w = 1176, editor_init_h = 540;

	constexpr auto env_init_begin_x = 839.0f;
	constexpr auto env_init_end_x = 931.0f;
	constexpr auto env_init_max_y = 174.0f;
	constexpr auto env_init_min_y = 218.0f;
	constexpr auto env_stage_init_max_w = 24.0f;
	constexpr auto env_sustain_init_w = 20.0f;

	constexpr auto knob_diam = 34;
	constexpr auto knob_diam_lpf_freq = 50;

	constexpr auto mix_knb_cx = 318;

	constexpr auto switch_h = 52;
	constexpr auto switch_lpf_type_h = 80;
	constexpr auto switch_w = 34;

	constexpr auto vmode_btn_spacing = 37;
	constexpr auto vmode_btn_0_x = 834;
	constexpr auto vmode_btn_1_x = vmode_btn_0_x + vmode_btn_spacing;
	constexpr auto vmode_btn_2_x = vmode_btn_1_x + vmode_btn_spacing;
	constexpr auto vmode_btn_3_x = vmode_btn_2_x + vmode_btn_spacing;
	constexpr auto vmode_btn_4_x = vmode_btn_3_x + vmode_btn_spacing;
	constexpr auto vmode_btn_5_x = vmode_btn_4_x + vmode_btn_spacing;
	constexpr auto vmode_btn_6_x = vmode_btn_5_x + vmode_btn_spacing;
	constexpr auto vmode_btn_7_x = vmode_btn_6_x + vmode_btn_spacing;
	constexpr auto vmode_btn_h = 28;
	constexpr auto vmode_btn_row_y = 307;
	constexpr auto vmode_btn_w = 34;

	static Rectangle<int> env_backdrop_init_bounds{ 834, 167, 102, 58 };
	static Rectangle<int> trig_area_env_init_bounds{ 542, 180, 238, 34 };
	static Rectangle<int> trig_area_vca_env_init_bounds{ 542, 86, 238, 34 };

}
