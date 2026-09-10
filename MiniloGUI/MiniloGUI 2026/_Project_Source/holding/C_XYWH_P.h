#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	static const float env_init_begin_x{ 839.0f };
	static const float env_init_end_x{ 931.0f };
	static const float env_init_max_y{ 174.0f };
	static const float env_init_min_y{ 218.0f };
	static const float env_stage_init_max_w{ 24.0f };
	static const float env_sustain_init_w{ 20.0f };

	static const int cbox_h{ 16 };
	static const int ctrl_row_h{ 94 };
	static const int ctrl_row_1_cntr_y{ 103 };
	static const int ctrl_row_2_cntr_y{ ctrl_row_1_cntr_y + ctrl_row_h };
	static const int ctrl_row_3_cntr_y{ ctrl_row_2_cntr_y + ctrl_row_h };
	static const int ctrl_row_4_cntr_y{ 449 };

	static const int editor_init_w{ 1176 }, editor_init_h{ 540 };

	static const int knob_diam{ 34 };
	static const int knob_diam_lpf_freq{ 50 };

	static const int switch_h{ 52 };
	static const int switch_lpf_type_h{ 80 };
	static const int switch_w{ 34 };

	static Rectangle<int> env_backdrop_init_bounds{ 834, 167, 102, 58 };
	static Rectangle<int> trig_area_env_init_bounds{ 542, 180, 238, 34 };
	static Rectangle<int> trig_area_vca_env_init_bounds{ 542, 86, 238, 34 };

}
