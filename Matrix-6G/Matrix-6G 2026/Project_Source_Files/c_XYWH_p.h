#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	constexpr double gui_aspect_ratio{ 2.10067  };

	constexpr int choice_menu_col_count_6_bit{ 8 };
	constexpr int choice_menu_col_count_7_bit{ 16 };
	constexpr int choice_menu_col_w_6_bit{ 16 };
	constexpr int choice_menu_col_w_7_bit{ 22 };
	constexpr int choice_menu_col_w_signed{ 26 };
	constexpr int choice_menu_row_count_numeric{ 8 };

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

	constexpr int gui_init_w{ 1252 }, gui_init_h{ 596 };

	constexpr int osc_col_1_x{ 130 };
	constexpr int osc_col_2_x{ 196 };
	constexpr int osc_ctrl_w{ 60 };

	constexpr int lfo_col_1_x{ 726 };
	constexpr int lfo_col_2_x{ 792 };
	constexpr int lfo_ctrl_w{ 60 };

	constexpr int porta_key_mode_col_x{ 544 };
	constexpr int porta_key_mode_col_w{ 72 };

	constexpr int ramp_col_1_x{ 894 };
	constexpr int ramp_col_2_x{ 960 };
	constexpr int ramp_ctrl_w{ 60 };

	constexpr int track_input_x{ 943 };
	constexpr int track_input_y{ 165 };
	constexpr int track_input_w{ 94 };
	constexpr int track_pt_spacing{ 31 };
	constexpr int track_pt_1_x{ 853 };
	constexpr int track_pt_w{ 26 };
	constexpr int track_pt_y{ 279 };

	constexpr int vcf_fm_col_x{ 550 };
	constexpr int vcf_fm_ctrl_w{ 60 };

	constexpr int vcf_vca_col_x{ 382 };
	constexpr int vcf_vca_ctrl_w{ 60 };

}