#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double editor_aspect_ratio{ 2.03354 };

	constexpr float env_init_begin_x{ 5.0f };
	constexpr float env_init_end_x{ 205.0f };
	constexpr float env_init_max_y{ 10.0f };
	constexpr float env_init_min_y{ 80.0f };
	constexpr float env_stage_init_max_w{ 43.0f };
	constexpr float env_sustain_init_w{ 28.0f };

	constexpr float rotary_slider_begin_angle{ degreesToRadians(45.0f) };
	constexpr float rotary_slider_end_angle{ degreesToRadians(315.0f) };

	constexpr int cbox_h{ 16 };

	constexpr int cc_cbox_w{ 136 };
	constexpr int cc_col_1_x{ 680 };
	constexpr int cc_col_2_x{ 776 };
	constexpr int cc_block_spacing{ 62 };
	constexpr int cc_row_1_y{ 191 };
	constexpr int cc_row_2_y{ cc_row_1_y + cc_block_spacing };
	constexpr int cc_row_3_y{ cc_row_2_y + cc_block_spacing };
	constexpr int cc_row_4_y{ cc_row_3_y + cc_block_spacing };
	constexpr int cc_row_5_y{ cc_row_4_y + cc_block_spacing };

	constexpr int clock_and_seq_row_y{ 126 };

	constexpr int knob_diam{ 38 };
	constexpr int ctrl_col_w{ knob_diam + 7 };
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

	constexpr int editor_init_w{ 1273 }, editor_init_h{ 626 };

	constexpr int env_3_row_1_y{ 531 };
	constexpr int env_3_row_2_y{ 583 };
	constexpr int env_block_spacing{ 158 };
	constexpr int env_init_h{ 90 };
	constexpr int env_init_w{ 210 };
	constexpr int env_init_x{ 168 };
	constexpr int env_lpf_init_y{ 154 };

	constexpr int flex_knob_cbox_w{ 134 };
	constexpr int flex_knob_cbox_x{ 1089 };
	constexpr int flex_knob_spacing{ 28 };

	constexpr int lfo_1_cbox_x{ 463 };
	constexpr int lfo_block_spacing{ 155 };
	constexpr int lfo_cbox_w{ 134 };
	constexpr int lfo_row_1_y{ 515 };
	constexpr int lfo_row_2_y{ 560 };
	constexpr int lfo_row_3_y{ 594 };

	constexpr int lpf_row_1_y{ 167 };
	constexpr int lpf_row_2_y{ 215 };
	constexpr int lpf_row_3_y{ 267 };

	constexpr int mod_block_spacing{ 78 };
	constexpr int mod_cbox_w{ 126 };
	constexpr int mod_col_1_x{ 486 };
	constexpr int mod_col_2_x{ 575 };

	constexpr int osc_cbox_w{ 124 };
	constexpr int osc_row_h{ 60 };
	constexpr int osc_row_1_y{ 50 };
	constexpr int osc_row_2_y{ osc_row_1_y + osc_row_h };

	constexpr int push_it_knob_row_y{ 528 };

	constexpr int seq_step_col_1{ 825 };
	constexpr int seq_step_h{ 26 };
	constexpr int seq_step_w{ 26 };
	constexpr int seq_track_block_spacing{ 83 };
	constexpr int seq_track_1_dest_cbox_y{ 169 };
	constexpr int seq_track_dest_cbox_w{ 126 };
	constexpr int seq_track_dest_cbox_x{ 1065 };
	constexpr int step_and_char_gap{ 2 };

	constexpr int toggle_cntr_offset{ 1 };
	constexpr int toggle_diam{ 14 };

	constexpr int vca_row_1_y{ 373 };
	constexpr int vca_row_2_y{ 425 };

	constexpr int voice_name_char_h{ 17 };
	constexpr int voice_name_char_w{ 12 };
	constexpr int voice_name_char_y{ 52 };

}
