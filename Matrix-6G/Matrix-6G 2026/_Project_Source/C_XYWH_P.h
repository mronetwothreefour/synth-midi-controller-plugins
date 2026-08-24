#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	static const float env_init_begin_x{ 11.0f };
	static const float env_init_end_x{ 217.0f };
	static const float env_init_max_y{ 10.0f };
	static const float env_init_min_y{ 98.0f };
	static const float env_stage_init_max_w{ 43.0f };
	static const float env_sustain_init_w{ 34.0f };

	static const float led_display_y{ 3 };

	static const float track_env_init_begin_x{ 849.0f };
	static const float track_env_init_max_y{ 193.0f };
	static const float track_env_init_min_y{ 253.0f };
	static const float track_env_init_h{ track_env_init_min_y - track_env_init_max_y };
	static const float track_env_segment_init_w{ 33.0f };

	static const int btn_main_big_h{ 38 };
	static const int btn_main_big_w{ 68 };
	static const int btn_main_big_y{ 353 };
	static const int btn_main_master_x{ 1164 };
	static const int btn_main_patches_x{ 1006 };
	static const int btn_main_pull_x{ 704 };
	static const int btn_main_push_x{ 663 };
	static const int btn_main_quick_w{ 63 };
	static const int btn_main_quick_x{ 596 };
	static const int btn_main_redo_x{ 367 };
	static const int btn_main_splits_x{ 1085 };
	static const int btn_main_tx_undo_w{ 36 };
	static const int btn_main_undo_x{ 745 };

	static const int ctrl_h{ 20 };
	static const int ctrl_row_h{ ctrl_h + 8 };
	static const int ctrl_row_0_y{ 59 };

	static const int editor_init_w{ 1252 }, editor_init_h{ 596 };

	static const int env_1_init_x{ 184 };
	static const int env_1_stage_0_x{ 184 };
	static const int env_block_spacing{ 410 };
	static const int env_ctrl_col_x{ 98 };
	static const int env_ctrl_row_0_y{ 440 };
	static const int env_ctrl_w{ 72 };
	static const int env_init_h{ 108 };
	static const int env_init_w{ 228 };
	static const int env_init_y{ 408 };
	static const int env_stage_ctrl_w{ 28 };
	static const int env_stage_spacing{ 50 };

	static const int led_display_char_w{ 11 };
	static const int led_display_left_inset{ 6 };
	static const int led_display_right_inset{ 1 };

	static const int lfo_col_1_x{ 696 };
	static const int lfo_col_2_x{ 762 };
	static const int lfo_ctrl_w{ 60 };

	static const int mmod_col_amt_x{ 1104 };
	static const int mmod_col_dest_x{ 1150 };
	static const int mmod_col_src_x{ 1016 };
	static const int mmod_ctrl_amt_w{ 40 };
	static const int mmod_ctrl_src_dest_w{ 82 };

	static const int osc_col_1_x{ 100 };
	static const int osc_col_2_x{ 166 };
	static const int osc_ctrl_w{ 60 };

	static const int patch_name_w{ 117 };
	static const int patch_name_x{ 873 };
	static const int patch_num_w{ 28 };
	static const int patch_num_x{ 840 };

	static const int porta_key_mode_ctrl_w{ 72 };
	static const int porta_key_mode_col_x{ 508 };

	static const int ramp_col_1_x{ 864 };
	static const int ramp_col_2_x{ 930 };
	static const int ramp_ctrl_w{ 60 };

	static const int track_input_w{ 94 };
	static const int track_input_x{ 896 };
	static const int track_input_y{ 155 };
	static const int track_pt_1_x{ 840 };
	static const int track_pt_spacing{ 31 };
	static const int track_pt_w{ 26 };
	static const int track_pt_y{ 269 };

	static const int vcf_fm_col_x{ 520 };
	static const int vcf_fm_ctrl_w{ 60 };

	static const int vcf_vca_col_x{ 352 };
	static const int vcf_vca_ctrl_w{ 60 };

}
