#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double editor_aspect_ratio{ 2.10067 };

	constexpr float env_init_begin_x{ 11.0f };
	constexpr float env_init_end_x{ 217.0f };
	constexpr float env_init_max_y{ 10.0f };
	constexpr float env_init_min_y{ 98.0f };
	constexpr float env_stage_init_max_w{ 43.0f };
	constexpr float env_sustain_init_w{ 34.0f };

	constexpr float led_display_y{ 3 };

	constexpr float rotary_slider_begin_angle{ degreesToRadians(225.0f) };
	constexpr float rotary_slider_end_angle{ degreesToRadians(495.0f) };

	constexpr float track_env_init_begin_x{ 849.0f };
	constexpr float track_env_init_max_y{ 193.0f };
	constexpr float track_env_init_min_y{ 253.0f };
	constexpr float track_env_init_h{ track_env_init_min_y - track_env_init_max_y };
	constexpr float track_env_segment_init_w{ 33.0f };

	constexpr int btn_main_big_h{ 38 };
	constexpr int btn_main_big_w{ 68 };
	constexpr int btn_main_big_y{ 353 };
	constexpr int btn_main_master_x{ 1164 };
	constexpr int btn_main_patches_x{ 1006 };
	constexpr int btn_main_pull_x{ 704 };
	constexpr int btn_main_push_x{ 663 };
	constexpr int btn_main_quick_w{ 63 };
	constexpr int btn_main_quick_x{ 596 };
	constexpr int btn_main_redo_x{ 367 };
	constexpr int btn_main_splits_x{ 1085 };
	constexpr int btn_main_tx_undo_w{ 36 };
	constexpr int btn_main_undo_x{ 745 };

	constexpr int ctrl_h{ 20 };
	constexpr int ctrl_row_h{ ctrl_h + 8 };
	constexpr int ctrl_row_01_y{ 69 };
	constexpr int ctrl_row_02_y{ ctrl_row_01_y + ctrl_row_h };
	constexpr int ctrl_row_03_y{ ctrl_row_02_y + ctrl_row_h };
	constexpr int ctrl_row_04_y{ ctrl_row_03_y + ctrl_row_h };
	constexpr int ctrl_row_05_y{ ctrl_row_04_y + ctrl_row_h };
	constexpr int ctrl_row_06_y{ ctrl_row_05_y + ctrl_row_h };
	constexpr int ctrl_row_07_y{ ctrl_row_06_y + ctrl_row_h };
	constexpr int ctrl_row_08_y{ ctrl_row_07_y + ctrl_row_h };
	constexpr int ctrl_row_09_y{ ctrl_row_08_y + ctrl_row_h };
	constexpr int ctrl_row_10_y{ ctrl_row_09_y + ctrl_row_h };
	constexpr int ctrl_row_11_y{ ctrl_row_10_y + ctrl_row_h };
	constexpr int ctrl_row_12_y{ ctrl_row_11_y + ctrl_row_h };

	constexpr int editor_init_w{ 1252 }, editor_init_h{ 596 };

	constexpr int env_block_spacing{ 410 };
	constexpr int env_dadsr_spacing{ 50 };
	constexpr int env_col_1_x{ 134 };
	constexpr int env_1_delay_x{ 198 };
	constexpr int env_1_attack_x{ env_1_delay_x + env_dadsr_spacing };
	constexpr int env_1_decay_x{ env_1_attack_x + env_dadsr_spacing };
	constexpr int env_1_sustain_x{ env_1_decay_x + env_dadsr_spacing };
	constexpr int env_1_release_x{ env_1_sustain_x + env_dadsr_spacing };
	constexpr int env_ctrl_row_1_y{ 450 };
	constexpr int env_ctrl_row_2_y{ env_ctrl_row_1_y + ctrl_row_h };
	constexpr int env_ctrl_row_3_y{ env_ctrl_row_2_y + ctrl_row_h };
	constexpr int env_ctrl_row_4_y{ env_ctrl_row_3_y + ctrl_row_h };
	constexpr int env_ctrl_row_5_y{ env_ctrl_row_4_y + ctrl_row_h };
	constexpr int env_ctrl_w{ 72 };
	constexpr int env_dadsr_ctrl_w{ 28 };
	constexpr int env_1_init_x{ 184 };
	constexpr int env_init_h{ 108 };
	constexpr int env_init_w{ 228 };
	constexpr int env_init_y{ 408 };

	constexpr int led_display_char_w{ 11 };
	constexpr int led_display_left_inset{ 6 };
	constexpr int led_display_right_inset{ 1 };

	constexpr int lfo_col_1_x{ 726 };
	constexpr int lfo_col_2_x{ 792 };
	constexpr int lfo_ctrl_w{ 60 };

	constexpr int mmod_col_1_x{ 1016 };
	constexpr int mmod_col_2_x{ 1104 };
	constexpr int mmod_col_3_x{ 1150 };
	constexpr int mmod_ctrl_amt_w{ 40 };
	constexpr int mmod_ctrl_src_dest_w{ 82 };

	constexpr int osc_col_1_x{ 130 };
	constexpr int osc_col_2_x{ 196 };
	constexpr int osc_ctrl_w{ 60 };

	constexpr int patch_name_w{ 117 };
	constexpr int patch_name_x{ 873 };
	constexpr int patch_num_w{ 28 };
	constexpr int patch_num_x{ 840 };

	constexpr int porta_key_mode_col_w{ 72 };
	constexpr int porta_key_mode_col_x{ 544 };

	constexpr int ramp_col_1_x{ 894 };
	constexpr int ramp_col_2_x{ 960 };
	constexpr int ramp_ctrl_w{ 60 };

	constexpr int track_input_w{ 94 };
	constexpr int track_input_x{ 943 };
	constexpr int track_input_y{ 165 };
	constexpr int track_pt_1_x{ 853 };
	constexpr int track_pt_spacing{ 31 };
	constexpr int track_pt_w{ 26 };
	constexpr int track_pt_y{ 279 };

	constexpr int vcf_fm_col_x{ 550 };
	constexpr int vcf_fm_ctrl_w{ 60 };

	constexpr int vcf_vca_col_x{ 382 };
	constexpr int vcf_vca_ctrl_w{ 60 };

}