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

	static const float trk_env_init_begin_x{ 849.0f };
	static const float trk_env_init_max_y{ 193.0f };
	static const float trk_env_init_min_y{ 253.0f };
	static const float trk_env_init_h{ trk_env_init_min_y - trk_env_init_max_y };
	static const float trk_env_segment_init_w{ 33.0f };

	static const int btn_main_big_cy{ 372 };
	static const int btn_main_big_h{ 38 };
	static const int btn_main_big_w{ 68 };
	static const int btn_main_master_cx{ 1198 };
	static const int btn_main_patches_cx{ 1040 };
	static const int btn_main_pull_cx{ 722 };
	static const int btn_main_push_cx{ 681 };
	static const int btn_main_quick_w{ 63 };
	static const int btn_main_quick_x{ 596 };
	static const int btn_main_quick_y{ 367 };
	static const int btn_main_redo_cx{ 804 };
	static const int btn_main_splits_cx{ 1119 };
	static const int btn_main_tx_undo_w{ 36 };
	static const int btn_main_undo_cx{ 763 };

	static const int ctr_h{ 20 };
	static const int ctr_h_row{ ctr_h + 8 };
	static const int ctr_main_r_00_cy{ 69 };
	static const int ctr_main_r_01_cy{ ctr_main_r_00_cy + ctr_h_row };
	static const int ctr_main_r_02_cy{ ctr_main_r_01_cy + ctr_h_row };
	static const int ctr_main_r_03_cy{ ctr_main_r_02_cy + ctr_h_row };
	static const int ctr_main_r_04_cy{ ctr_main_r_03_cy + ctr_h_row };
	static const int ctr_main_r_05_cy{ ctr_main_r_04_cy + ctr_h_row };
	static const int ctr_main_r_06_cy{ ctr_main_r_05_cy + ctr_h_row };
	static const int ctr_main_r_07_cy{ ctr_main_r_06_cy + ctr_h_row };
	static const int ctr_main_r_08_cy{ ctr_main_r_07_cy + ctr_h_row };
	static const int ctr_main_r_09_cy{ ctr_main_r_08_cy + ctr_h_row };
	static const int ctr_main_r_10_cy{ ctr_main_r_09_cy + ctr_h_row };
	static const int ctr_main_r_11_cy{ ctr_main_r_10_cy + ctr_h_row };
	static const int ctr_main_r_12_cy{ 450 };
	static const int ctr_main_r_13_cy{ ctr_main_r_12_cy + ctr_h_row };
	static const int ctr_main_r_14_cy{ ctr_main_r_13_cy + ctr_h_row };
	static const int ctr_main_r_15_cy{ ctr_main_r_14_cy + ctr_h_row };
	static const int ctr_main_r_16_cy{ ctr_main_r_15_cy + ctr_h_row };

	static const int editor_init_w{ 1252 }, editor_init_h{ 596 };

	static const int env_block_spacing{ 410 };
	static const int env_stg_spacing{ 50 };
	static const int env_1_ctr_cx{ 134 };
	static const int env_1_stg_0_cx{ 198 };
	static const int env_1_stg_1_cx{ env_1_stg_0_cx + env_stg_spacing };
	static const int env_1_stg_2_cx{ env_1_stg_1_cx + env_stg_spacing };
	static const int env_1_stg_3_cx{ env_1_stg_2_cx + env_stg_spacing };
	static const int env_1_stg_4_cx{ env_1_stg_3_cx + env_stg_spacing };
	static const int env_2_ctr_cx{ env_1_ctr_cx + env_block_spacing };
	static const int env_2_stg_0_cx{ env_1_stg_0_cx + env_block_spacing };
	static const int env_2_stg_1_cx{ env_2_stg_0_cx + env_stg_spacing };
	static const int env_2_stg_2_cx{ env_2_stg_1_cx + env_stg_spacing };
	static const int env_2_stg_3_cx{ env_2_stg_2_cx + env_stg_spacing };
	static const int env_2_stg_4_cx{ env_2_stg_3_cx + env_stg_spacing };
	static const int env_3_ctr_cx{ env_2_ctr_cx + env_block_spacing };
	static const int env_3_stg_0_cx{ env_2_stg_0_cx + env_block_spacing };
	static const int env_3_stg_1_cx{ env_3_stg_0_cx + env_stg_spacing };
	static const int env_3_stg_2_cx{ env_3_stg_1_cx + env_stg_spacing };
	static const int env_3_stg_3_cx{ env_3_stg_2_cx + env_stg_spacing };
	static const int env_3_stg_4_cx{ env_3_stg_3_cx + env_stg_spacing };
	static const int env_1_init_x{ 184 };
	static const int env_ctr_w{ 72 };
	static const int env_init_h{ 108 };
	static const int env_init_w{ 228 };
	static const int env_init_y{ 408 };
	static const int env_stg_ctr_w{ 28 };

	static const int led_display_char_w{ 11 };
	static const int led_display_left_inset{ 6 };
	static const int led_display_right_inset{ 1 };

	static const int lfo_col_1_cx{ 726 };
	static const int lfo_col_2_cx{ 792 };
	static const int lfo_ctr_w{ 60 };

	static const int mmod_col_amt_cx{ 1124 };
	static const int mmod_col_dst_cx{ 1191 };
	static const int mmod_col_src_cx{ 1057 };
	static const int mmod_ctr_amt_w{ 40 };
	static const int mmod_ctr_src_dst_w{ 82 };

	static const int osc_bal_cx{ 163 };
	static const int osc_bal_w{ 126 };
	static const int osc_col_1_cx{ 130 };
	static const int osc_col_2_cx{ 196 };
	static const int osc_ctr_w{ 60 };

	static const int patch_name_cx{ 931 };
	static const int patch_name_w{ 116 };
	static const int patch_num_cx{ 854 };
	static const int patch_num_w{ 28 };

	static const int porta_key_mode_col_cx{ 544 };
	static const int porta_key_mode_ctr_w{ 72 };

	static const int ramp_col_1_cx{ 894 };
	static const int ramp_col_2_cx{ 960 };
	static const int ramp_ctr_w{ 60 };

	static const int track_input_cx{ 943 };
	static const int track_input_cy{ 165 };
	static const int track_input_w{ 94 };
	static const int track_pt_spacing{ 31 };
	static const int track_pt_1_cx{ 853 };
	static const int track_pt_2_cx{ track_pt_1_cx + track_pt_spacing };
	static const int track_pt_3_cx{ track_pt_2_cx + track_pt_spacing };
	static const int track_pt_4_cx{ track_pt_3_cx + track_pt_spacing };
	static const int track_pt_5_cx{ track_pt_4_cx + track_pt_spacing };
	static const int track_pt_cy{ 279 };
	static const int track_pt_w{ 26 };

	static const int vcf_fm_col_cx{ 550 };
	static const int vcf_fm_ctr_w{ 60 };

	static const int vcf_vca_col_cx{ 382 };
	static const int vcf_vca_ctr_w{ 60 };

}
