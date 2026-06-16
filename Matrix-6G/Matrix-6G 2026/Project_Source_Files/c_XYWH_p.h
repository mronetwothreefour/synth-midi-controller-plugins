#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double gui_aspect_ratio{ 2.10067  };

	constexpr float led_display_y{ 3 };
	constexpr float rotary_slider_end_angle{ degreesToRadians(495.0f) };
	constexpr float rotary_slider_start_angle{ degreesToRadians(225.0f) };

	constexpr int btn_editor_patches_x{ 1006 };
	constexpr int btn_editor_splits_x{ 1085 };
	constexpr int btn_editor_master_x{ 1164 };
	constexpr int btn_editor_big_h{ 38 };
	constexpr int btn_editor_big_w{ 68 };
	constexpr int btn_editor_big_y{ 353 };

	constexpr int btn_editor_quick_x{ 596 };
	constexpr int btn_editor_quick_w{ 63 };
	constexpr int btn_editor_push_x{ 663 };
	constexpr int btn_editor_pull_x{ 704 };
	constexpr int btn_editor_undo_x{ 745 };
	constexpr int btn_editor_redo_x{ 367 };
	constexpr int btn_editor_tx_undo_w{ 36 };

	constexpr int choice_menu_col_count_6_bit{ 8 };
	constexpr int choice_menu_col_count_7_bit{ 16 };
	constexpr int choice_menu_col_w_6_bit{ 16 };
	constexpr int choice_menu_col_w_7_bit{ 22 };
	constexpr int choice_menu_col_w_signed{ 26 };
	constexpr int choice_menu_row_count_numeric{ 8 };

	constexpr int ctrl_h{ 20 };
	constexpr int ctrl_row_h{ ctrl_h + 8 };
	constexpr int ctrl_row_01_y{ 59 };
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

	constexpr int env_block_spacing{ 410 };
	constexpr int env_dadsr_spacing{ 50 };
	constexpr int env_col_1_x{ 98 };
	constexpr int env_1_delay_x{ 184 };
	constexpr int env_1_attack_x{ env_1_delay_x + env_dadsr_spacing };
	constexpr int env_1_decay_x{ env_1_attack_x + env_dadsr_spacing };
	constexpr int env_1_sustain_x{ env_1_decay_x + env_dadsr_spacing };
	constexpr int env_1_release_x{ env_1_sustain_x + env_dadsr_spacing };
	constexpr int env_ctrl_row_1_y{ 440 };
	constexpr int env_ctrl_row_2_y{ env_ctrl_row_1_y + ctrl_row_h };
	constexpr int env_ctrl_row_3_y{ env_ctrl_row_2_y + ctrl_row_h };
	constexpr int env_ctrl_row_4_y{ env_ctrl_row_3_y + ctrl_row_h };
	constexpr int env_ctrl_row_5_y{ env_ctrl_row_4_y + ctrl_row_h };
	constexpr int env_ctrl_w{ 72 };
	constexpr int env_dadsr_ctrl_w{ 28 };

	constexpr int gui_init_w{ 1252 }, gui_init_h{ 596 };

	constexpr int osc_col_1_x{ 100 };
	constexpr int osc_col_2_x{ 166 };
	constexpr int osc_ctrl_w{ 60 };

	constexpr int lfo_col_1_x{ 696 };
	constexpr int lfo_col_2_x{ 762 };
	constexpr int lfo_ctrl_w{ 60 };

	constexpr int mmod_col_1_x{ 1016 };
	constexpr int mmod_col_2_x{ 1104 };
	constexpr int mmod_col_3_x{ 1150 };
	constexpr int mmod_ctrl_amt_w{ 40 };
	constexpr int mmod_ctrl_src_dest_w{ 82 };

	constexpr int txt_edit_circ_fill_inset{ 0 };

	constexpr int led_display_left_inset{ 3 };
	constexpr int led_display_right_inset{ 1 };
	constexpr int led_display_char_w{ 11 };

	constexpr int patch_name_x{ 873 };
	constexpr int patch_name_w{ 117 };
	constexpr int patch_num_x{ 840 };
	constexpr int patch_num_w{ 28 };

	constexpr int porta_key_mode_col_x{ 508 };
	constexpr int porta_key_mode_col_w{ 72 };

	constexpr int ramp_col_1_x{ 864 };
	constexpr int ramp_col_2_x{ 930 };
	constexpr int ramp_ctrl_w{ 60 };

	constexpr int track_input_x{ 896 };
	constexpr int track_input_y{ 155 };
	constexpr int track_input_w{ 94 };
	constexpr int track_pt_spacing{ 31 };
	constexpr int track_pt_1_x{ 840 };
	constexpr int track_pt_w{ 26 };
	constexpr int track_pt_y{ 279 };

	constexpr int vcf_fm_col_x{ 520 };
	constexpr int vcf_fm_ctrl_w{ 60 };

	constexpr int vcf_vca_col_x{ 352 };
	constexpr int vcf_vca_ctrl_w{ 60 };

}