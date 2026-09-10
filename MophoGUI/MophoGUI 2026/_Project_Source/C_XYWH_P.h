#pragma once

#include <JuceHeader.h>

namespace XYWH
{

	static const float env_init_begin_x{ 5.0f };
	static const float env_init_end_x{ 205.0f };
	static const float env_init_max_y{ 10.0f };
	static const float env_init_min_y{ 80.0f };
	static const float env_stg_init_max_w{ 43.0f };
	static const float env_sust_init_w{ 28.0f };

	static const int cbox_h{ 16 };
	static const int knob_diam{ 38 };
	static const int toggle_diam{ 14 };

	static const int cc_block_spacing{ 62 };
	static const int cc_1_ctr_cy{ 191 };
	static const int cc_2_ctr_cy{ cc_1_ctr_cy + cc_block_spacing };
	static const int cc_3_ctr_cy{ cc_2_ctr_cy + cc_block_spacing };
	static const int cc_4_ctr_cy{ cc_3_ctr_cy + cc_block_spacing };
	static const int cc_5_ctr_cy{ cc_4_ctr_cy + cc_block_spacing };
	static const int cc_amt_cx{ 776 };
	static const int cc_dst_cx{ 680 };
	static const int cc_dst_w{ 136 };

	static const int clock_ctr_cy{ 126 };
	static const int clock_div_cx{ 1139 };
	static const int clock_tempo_cx{ 1236 };
	static const int clock_div_w{ 124 };

	static const int ctr_col_w{ knob_diam + 7 };
	static const int ctr_col_1_cx{ 48 };
	static const int ctr_col_2_cx{ ctr_col_1_cx + ctr_col_w };
	static const int ctr_col_3_cx{ ctr_col_2_cx + ctr_col_w };
	static const int ctr_col_4_cx{ ctr_col_3_cx + ctr_col_w };
	static const int ctr_col_5_cx{ ctr_col_4_cx + ctr_col_w };
	static const int ctr_col_6_cx{ ctr_col_5_cx + ctr_col_w };
	static const int ctr_col_7_cx{ ctr_col_6_cx + ctr_col_w };
	static const int ctr_col_8_cx{ ctr_col_7_cx + ctr_col_w };
	static const int ctr_col_9_cx{ ctr_col_8_cx + ctr_col_w };
	static const int ctr_col_10_cx{ 500 };
	static const int ctr_col_10_w{ 124 };

	static const int editor_init_w{ 1273 }, editor_init_h{ 626 };

	static const int env_3_row_1_cy{ 531 };
	static const int env_3_row_2_cy{ 583 };
	static const int env_block_spacing{ 158 };
	static const int env_init_h{ 90 };
	static const int env_init_w{ 210 };
	static const int env_init_x{ 168 };
	static const int env_lpf_init_y{ 154 };

	static const int flex_knb_cbx_spacing{ 28 };
	static const int flex_knb_cbx_1_cy{ 521 };
	static const int flex_knb_cbx_2_cy{ flex_knb_cbx_1_cy + flex_knb_cbx_spacing };
	static const int flex_knb_cbx_3_cy{ flex_knb_cbx_2_cy + flex_knb_cbx_spacing };
	static const int flex_knb_cbx_4_cy{ flex_knb_cbx_3_cy + flex_knb_cbx_spacing };
	static const int flex_knb_cbx_cx{ 1089 };
	static const int flex_knb_cbx_w{ 134 };

	static const int lfo_block_spacing{ 155 };
	static const int lfo_1_amt_cx{ 461 };
	static const int lfo_1_cbx_cx{ 463 };
	static const int lfo_1_frq_cx{ 416 };
	static const int lfo_1_snc_cx{ 507 };
	static const int lfo_2_amt_cx{ lfo_1_amt_cx + lfo_block_spacing };
	static const int lfo_2_cbx_cx{ lfo_1_cbx_cx + lfo_block_spacing };
	static const int lfo_2_frq_cx{ lfo_1_frq_cx + lfo_block_spacing };
	static const int lfo_2_snc_cx{ lfo_1_snc_cx + lfo_block_spacing };
	static const int lfo_3_amt_cx{ lfo_2_amt_cx + lfo_block_spacing };
	static const int lfo_3_cbx_cx{ lfo_2_cbx_cx + lfo_block_spacing };
	static const int lfo_3_frq_cx{ lfo_2_frq_cx + lfo_block_spacing };
	static const int lfo_3_snc_cx{ lfo_2_snc_cx + lfo_block_spacing };
	static const int lfo_4_amt_cx{ lfo_3_amt_cx + lfo_block_spacing };
	static const int lfo_4_cbx_cx{ lfo_3_cbx_cx + lfo_block_spacing };
	static const int lfo_4_frq_cx{ lfo_3_frq_cx + lfo_block_spacing };
	static const int lfo_4_snc_cx{ lfo_3_snc_cx + lfo_block_spacing };
	static const int lfo_cbx_w{ 134 };
	static const int lfo_dst_cy{ 594 };
	static const int lfo_knb_cy{ 515 };
	static const int lfo_shp_cy{ 560 };
	static const int lfo_snc_cy{ 526 };
	static const int lfo_snc_h{ 36 };
	static const int lfo_snc_w{ 28 };
	static const int lfo_tgl_cy{ 515 };

	static const int lpf_row_1_cy{ 215 };
	static const int lpf_row_2_cy{ 267 };

	static const int mod_block_spacing{ 78 };
	static const int mod_1_amt_cy{ 201 };
	static const int mod_1_dst_cy{ 218 };
	static const int mod_1_src_cy{ 184 };
	static const int mod_2_amt_cy{ mod_1_amt_cy + mod_block_spacing };
	static const int mod_2_dst_cy{ mod_1_dst_cy + mod_block_spacing };
	static const int mod_2_src_cy{ mod_1_src_cy + mod_block_spacing };
	static const int mod_3_amt_cy{ mod_2_amt_cy + mod_block_spacing };
	static const int mod_3_dst_cy{ mod_2_dst_cy + mod_block_spacing };
	static const int mod_3_src_cy{ mod_2_src_cy + mod_block_spacing };
	static const int mod_4_amt_cy{ mod_3_amt_cy + mod_block_spacing };
	static const int mod_4_dst_cy{ mod_3_dst_cy + mod_block_spacing };
	static const int mod_4_src_cy{ mod_3_src_cy + mod_block_spacing };
	static const int mod_amt_cx{ 575 };
	static const int mod_cbx_cx{ 486 };
	static const int mod_cbx_w{ 126 };

	static const int char_step_and_gap{ 2 };
	static const int name_char_w{ 12 };
	static const int name_char_spacing{ name_char_w + char_step_and_gap };
	static const int name_char_01_cx{ 596 };
	static const int name_char_02_cx{ name_char_01_cx + name_char_spacing };
	static const int name_char_03_cx{ name_char_02_cx + name_char_spacing };
	static const int name_char_04_cx{ name_char_03_cx + name_char_spacing };
	static const int name_char_05_cx{ name_char_04_cx + name_char_spacing };
	static const int name_char_06_cx{ name_char_05_cx + name_char_spacing };
	static const int name_char_07_cx{ name_char_06_cx + name_char_spacing };
	static const int name_char_08_cx{ name_char_07_cx + name_char_spacing };
	static const int name_char_09_cx{ name_char_08_cx + name_char_spacing };
	static const int name_char_10_cx{ name_char_09_cx + name_char_spacing };
	static const int name_char_11_cx{ name_char_10_cx + name_char_spacing };
	static const int name_char_12_cx{ name_char_11_cx + name_char_spacing };
	static const int name_char_13_cx{ name_char_12_cx + name_char_spacing };
	static const int name_char_14_cx{ name_char_13_cx + name_char_spacing };
	static const int name_char_15_cx{ name_char_14_cx + name_char_spacing };
	static const int name_char_16_cx{ name_char_15_cx + name_char_spacing };
	static const int name_char_cy{ 52 };
	static const int name_char_h{ 17 };

	static const int osc_row_1_cy{ 50 };
	static const int osc_row_2_cy{ 110 };
	static const int osc_key_trk_1_cy{ osc_row_1_cy + 11 };
	static const int osc_key_trk_2_cy{ osc_row_2_cy + 11 };
	static const int osc_key_trk_h{ 36 };
	static const int osc_key_trk_w{ 34 };

	static const int push_it_knb_cy{ 528 };
	static const int push_it_mode_cx{ 1215 };
	static const int push_it_mode_cy{ 577 };
	static const int push_it_mode_w{ 88 };
	static const int push_it_pitch_cx{ 1191 };
	static const int push_it_velo_cx{ 1239 };

	static const int seq_step_h{ 26 };
	static const int seq_step_w{ 26 };
	static const int seq_step_spacing{ seq_step_w + char_step_and_gap };
	static const int seq_step_01_cx{ 825 };
	static const int seq_step_02_cx{ seq_step_01_cx + seq_step_spacing };
	static const int seq_step_03_cx{ seq_step_02_cx + seq_step_spacing };
	static const int seq_step_04_cx{ seq_step_03_cx + seq_step_spacing };
	static const int seq_step_05_cx{ seq_step_04_cx + seq_step_spacing };
	static const int seq_step_06_cx{ seq_step_05_cx + seq_step_spacing };
	static const int seq_step_07_cx{ seq_step_06_cx + seq_step_spacing };
	static const int seq_step_08_cx{ seq_step_07_cx + seq_step_spacing };
	static const int seq_step_09_cx{ seq_step_08_cx + seq_step_spacing };
	static const int seq_step_10_cx{ seq_step_09_cx + seq_step_spacing };
	static const int seq_step_11_cx{ seq_step_10_cx + seq_step_spacing };
	static const int seq_step_12_cx{ seq_step_11_cx + seq_step_spacing };
	static const int seq_step_13_cx{ seq_step_12_cx + seq_step_spacing };
	static const int seq_step_14_cx{ seq_step_13_cx + seq_step_spacing };
	static const int seq_step_15_cx{ seq_step_14_cx + seq_step_spacing };
	static const int seq_step_16_cx{ seq_step_15_cx + seq_step_spacing };
	static const int seq_trk_block_spacing{ 83 };
	static const int seq_trk_1_dst_cy{ 169 };
	static const int seq_trk_1_stp_cy{ 196 };
	static const int seq_trk_2_dst_cy{ seq_trk_1_dst_cy + seq_trk_block_spacing };
	static const int seq_trk_2_stp_cy{ seq_trk_1_stp_cy + seq_trk_block_spacing };
	static const int seq_trk_3_dst_cy{ seq_trk_2_dst_cy + seq_trk_block_spacing };
	static const int seq_trk_3_stp_cy{ seq_trk_2_stp_cy + seq_trk_block_spacing };
	static const int seq_trk_4_dst_cy{ seq_trk_3_dst_cy + seq_trk_block_spacing };
	static const int seq_trk_4_stp_cy{ seq_trk_3_stp_cy + seq_trk_block_spacing };
	static const int seq_trk_dst_cx{ 1065 };
	static const int seq_trk_dst_w{ 126 };

	static const int vca_row_1_cy{ 373 };
	static const int vca_row_2_cy{ 425 };

}
