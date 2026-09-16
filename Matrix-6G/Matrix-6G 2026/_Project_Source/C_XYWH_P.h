#pragma once

namespace XYWH
{

	constexpr auto btn_main_big_cy = 372;
	constexpr auto btn_main_big_h = 38;
	constexpr auto btn_main_big_w = 68;
	constexpr auto btn_main_master_cx = 1198;
	constexpr auto btn_main_patches_cx = 1040;
	constexpr auto btn_main_pull_cx = 722;
	constexpr auto btn_main_push_cx = 681;
	constexpr auto btn_main_quick_w = 63;
	constexpr auto btn_main_quick_x = 596;
	constexpr auto btn_main_quick_y = 367;
	constexpr auto btn_main_redo_cx = 804;
	constexpr auto btn_main_splits_cx = 1119;
	constexpr auto btn_main_tx_undo_w = 36;
	constexpr auto btn_main_undo_cx = 763;

	constexpr auto ctr_h = 20;
	constexpr auto ctr_h_row = ctr_h + 8;
	constexpr auto ctr_main_r_00_cy = 69;
	constexpr auto ctr_main_r_01_cy = ctr_main_r_00_cy + ctr_h_row;
	constexpr auto ctr_main_r_02_cy = ctr_main_r_01_cy + ctr_h_row;
	constexpr auto ctr_main_r_03_cy = ctr_main_r_02_cy + ctr_h_row;
	constexpr auto ctr_main_r_04_cy = ctr_main_r_03_cy + ctr_h_row;
	constexpr auto ctr_main_r_05_cy = ctr_main_r_04_cy + ctr_h_row;
	constexpr auto ctr_main_r_06_cy = ctr_main_r_05_cy + ctr_h_row;
	constexpr auto ctr_main_r_07_cy = ctr_main_r_06_cy + ctr_h_row;
	constexpr auto ctr_main_r_08_cy = ctr_main_r_07_cy + ctr_h_row;
	constexpr auto ctr_main_r_09_cy = ctr_main_r_08_cy + ctr_h_row;
	constexpr auto ctr_main_r_10_cy = ctr_main_r_09_cy + ctr_h_row;
	constexpr auto ctr_main_r_11_cy = ctr_main_r_10_cy + ctr_h_row;
	constexpr auto ctr_main_r_12_cy = 450;
	constexpr auto ctr_main_r_13_cy = ctr_main_r_12_cy + ctr_h_row;
	constexpr auto ctr_main_r_14_cy = ctr_main_r_13_cy + ctr_h_row;
	constexpr auto ctr_main_r_15_cy = ctr_main_r_14_cy + ctr_h_row;
	constexpr auto ctr_main_r_16_cy = ctr_main_r_15_cy + ctr_h_row;

	constexpr auto editor_aspect_ratio = 2.10067;
	constexpr auto editor_init_w = 1252, editor_init_h = 596;

	constexpr auto env_init_begin_x = 11.0f;
	constexpr auto env_init_end_x = 217.0f;
	constexpr auto env_init_max_y = 10.0f;
	constexpr auto env_init_min_y = 98.0f;
	constexpr auto env_stage_init_max_w = 43.0f;
	constexpr auto env_sustain_init_w = 34.0f;

	constexpr auto env_block_spacing = 410;
	constexpr auto env_stg_spacing = 50;
	constexpr auto env_1_ctr_cx = 134;
	constexpr auto env_1_stg_0_cx = 198;
	constexpr auto env_1_stg_1_cx = env_1_stg_0_cx + env_stg_spacing;
	constexpr auto env_1_stg_2_cx = env_1_stg_1_cx + env_stg_spacing;
	constexpr auto env_1_stg_3_cx = env_1_stg_2_cx + env_stg_spacing;
	constexpr auto env_1_stg_4_cx = env_1_stg_3_cx + env_stg_spacing;
	constexpr auto env_2_ctr_cx = env_1_ctr_cx + env_block_spacing;
	constexpr auto env_2_stg_0_cx = env_1_stg_0_cx + env_block_spacing;
	constexpr auto env_2_stg_1_cx = env_2_stg_0_cx + env_stg_spacing;
	constexpr auto env_2_stg_2_cx = env_2_stg_1_cx + env_stg_spacing;
	constexpr auto env_2_stg_3_cx = env_2_stg_2_cx + env_stg_spacing;
	constexpr auto env_2_stg_4_cx = env_2_stg_3_cx + env_stg_spacing;
	constexpr auto env_3_ctr_cx = env_2_ctr_cx + env_block_spacing;
	constexpr auto env_3_stg_0_cx = env_2_stg_0_cx + env_block_spacing;
	constexpr auto env_3_stg_1_cx = env_3_stg_0_cx + env_stg_spacing;
	constexpr auto env_3_stg_2_cx = env_3_stg_1_cx + env_stg_spacing;
	constexpr auto env_3_stg_3_cx = env_3_stg_2_cx + env_stg_spacing;
	constexpr auto env_3_stg_4_cx = env_3_stg_3_cx + env_stg_spacing;
	constexpr auto env_1_init_x = 184;
	constexpr auto env_ctr_w = 72;
	constexpr auto env_init_h = 108;
	constexpr auto env_init_w = 228;
	constexpr auto env_init_y = 408;
	constexpr auto env_stg_ctr_w = 28;

	constexpr auto led_display_char_w = 11;
	constexpr auto led_display_left_inset = 6;
	constexpr auto led_display_right_inset = 1;
	constexpr auto led_display_y = 3;

	constexpr auto lfo_col_1_cx = 726;
	constexpr auto lfo_col_2_cx = 792;
	constexpr auto lfo_ctr_w = 60;

	constexpr auto mmod_col_amt_cx = 1124;
	constexpr auto mmod_col_dst_cx = 1191;
	constexpr auto mmod_col_src_cx = 1057;
	constexpr auto mmod_ctr_amt_w = 40;
	constexpr auto mmod_ctr_dst_w = 82;
	constexpr auto mmod_ctr_src_w = mmod_ctr_dst_w;

	constexpr auto osc_bal_cx = 163;
	constexpr auto osc_bal_w = 126;
	constexpr auto osc_col_1_cx = 130;
	constexpr auto osc_col_2_cx = 196;
	constexpr auto osc_ctr_w = 60;

	constexpr auto patch_name_cx = 931;
	constexpr auto patch_name_w = 116;
	constexpr auto patch_num_cx = 854;
	constexpr auto patch_num_w = 28;

	constexpr auto porta_key_mode_col_cx = 544;
	constexpr auto porta_key_mode_ctr_w = 72;

	constexpr auto ramp_col_1_cx = 894;
	constexpr auto ramp_col_2_cx = 960;
	constexpr auto ramp_ctr_w = 60;

	constexpr auto trk_env_init_begin_x = 849.0f;
	constexpr auto trk_env_init_max_y = 193.0f;
	constexpr auto trk_env_init_min_y = 253.0f;
	constexpr auto trk_env_init_h = trk_env_init_min_y - trk_env_init_max_y;
	constexpr auto trk_env_segment_init_w = 33.0f;

	constexpr auto track_input_cx = 943;
	constexpr auto track_input_cy = 165;
	constexpr auto track_input_w = 94;
	constexpr auto track_pt_spacing = 31;
	constexpr auto track_pt_1_cx = 853;
	constexpr auto track_pt_2_cx = track_pt_1_cx + track_pt_spacing;
	constexpr auto track_pt_3_cx = track_pt_2_cx + track_pt_spacing;
	constexpr auto track_pt_4_cx = track_pt_3_cx + track_pt_spacing;
	constexpr auto track_pt_5_cx = track_pt_4_cx + track_pt_spacing;
	constexpr auto track_pt_cy = 279;
	constexpr auto track_pt_w = 26;

	constexpr auto vcf_fm_col_cx = 550;
	constexpr auto vcf_fm_ctr_w = 60;

	constexpr auto vcf_vca_col_cx = 382;
	constexpr auto vcf_vca_ctr_w = 60;

}
