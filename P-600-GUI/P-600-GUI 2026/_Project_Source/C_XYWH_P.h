#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	static const int editor_init_w{ 1342 }, editor_init_h{ 392 };

	static const int filter_amp_col_spacing{ 75 };
	static const int filter_amp_col_1_cntr_x{ 1057 };
	static const int filter_amp_col_2_cntr_x{ filter_amp_col_1_cntr_x + filter_amp_col_spacing };
	static const int filter_amp_col_3_cntr_x{ filter_amp_col_2_cntr_x + filter_amp_col_spacing };
	static const int filter_amp_col_4_cntr_x{ filter_amp_col_3_cntr_x + filter_amp_col_spacing };

	static const int knob_diam{ 34 };
	static const int knob_row_1_cntr_y{ 67 };
	static const int knob_row_2_cntr_y{ 170 };
	static const int knob_row_3_cntr_y{ 308 };

	static const int mixer_glide_cntr_x{ 939 };

	static const int osc_col_1_cntr_x{ 493 };
	static const int osc_col_2_cntr_x{ 569 };
	static const int osc_col_3_cntr_x{ 628 };
	static const int osc_col_4_cntr_x{ 688 };
	static const int osc_col_5_cntr_x{ 748 };
	static const int osc_col_6_cntr_x{ 817 };

	static const int switch_2_pole_h{ 32 };
	static const int switch_2_pole_w{ 20 };
	static const int switch_3_pole_h{ 48 };
	static const int switch_3_pole_w{ 46 };
	static const int switch_row_1_cntr_y{ 177 };
	static const int switch_row_2_cntr_y{ 315 };

}
