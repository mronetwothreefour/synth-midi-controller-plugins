#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr float env_init_begin_x{ 5.0f };
	constexpr float env_init_end_x{ 205.0f };
	constexpr float env_init_max_y{ 10.0f };
	constexpr float env_init_min_y{ 80.0f };
	constexpr float env_stage_init_max_w{ 43.0f };
	constexpr float env_sustain_init_w{ 28.0f };

	constexpr int cbox_h{ 16 };

	constexpr int cc_0_amt_cntr_y{ 191 };
	constexpr int cc_0_dest_y{ 183 };
	constexpr int cc_amt_cntr_x{ 776 };
	constexpr int cc_block_spacing{ 62 };
	constexpr int cc_dest_w{ 136 };
	constexpr int cc_dest_x{ 612 };

	constexpr int knob_diam{ 38 };
	constexpr int ctrl_col_0_cntr_x{ 48 };
	constexpr int ctrl_col_9_cntr_x{ 500 };
	constexpr int ctrl_col_w{ knob_diam + 7 };

	constexpr int editor_init_w{ 1273 }, editor_init_h{ 626 };

	constexpr int env_3_row_0_cntr_y{ 531 };
	constexpr int env_3_row_1_cntr_y{ 583 };
	constexpr int env_block_spacing{ 158 };
	constexpr int env_init_h{ 90 };
	constexpr int env_init_w{ 210 };
	constexpr int env_init_x{ 168 };
	constexpr int env_lpf_init_y{ 154 };

	constexpr int flex_knob_cbox_0_y{ 513 };
	constexpr int flex_knob_cbox_w{ 134 };
	constexpr int flex_knob_cbox_x{ 1022 };
	constexpr int flex_knob_cbox_spacing{ 28 };

	constexpr int lfo_0_amt_cntr_x{ 461 };
	constexpr int lfo_0_cbox_x{ 396 };
	constexpr int lfo_0_freq_cntr_x{ 416 };
	constexpr int lfo_0_key_sync_cntr_x{ 507 };
	constexpr int lfo_block_spacing{ 155 };
	constexpr int lfo_cbox_w{ 134 };
	constexpr int lfo_dest_y{ 586 };
	constexpr int lfo_key_sync_cntr_y{ 526 };
	constexpr int lfo_key_sync_h{ 36 };
	constexpr int lfo_key_sync_w{ 28 };
	constexpr int lfo_knob_cntr_y{ 515 };
	constexpr int lfo_shape_y{ 552 };

	constexpr int lpf_row_0_cntr_y{ 215 };
	constexpr int lpf_row_1_cntr_y{ 267 };

	constexpr int mod_0_amt_cntr_y{ 201 };
	constexpr int mod_0_dest_y{ 210 };
	constexpr int mod_0_src_y{ 176 };
	constexpr int mod_amt_cntr_x{ 575 };
	constexpr int mod_block_spacing{ 78 };
	constexpr int mod_cbox_x{ 423 };
	constexpr int mod_cbox_w{ 126 };

	constexpr int osc_cbox_w{ 124 };
	constexpr int osc_row_0_cntr_y{ 50 };
	constexpr int osc_row_1_cntr_y{ 110 };

	constexpr int push_it_knob_cntr_y{ 528 };
	constexpr int push_it_pitch_cntr_x{ 1191 };
	constexpr int push_it_velo_cntr_x{ 1239 };

	constexpr int seq_step_0_x{ 812 };
	constexpr int seq_step_h{ 26 };
	constexpr int seq_step_w{ 26 };
	constexpr int seq_track_block_spacing{ 83 };
	constexpr int seq_track_0_dest_y{ 161 };
	constexpr int seq_track_0_step_y{ 183 };
	constexpr int seq_track_dest_w{ 126 };
	constexpr int seq_track_dest_x{ 1002 };
	constexpr int step_and_char_gap{ 2 };

	constexpr int toggle_diam{ 14 };

	constexpr int vca_row_0_cntr_y{ 373 };
	constexpr int vca_row_1_cntr_y{ 425 };

	constexpr int voice_name_char_0_cntr_x{ 596 };
	constexpr int voice_name_char_h{ 17 };
	constexpr int voice_name_char_w{ 12 };
	constexpr int voice_name_char_cntr_y{ 52 };

}
