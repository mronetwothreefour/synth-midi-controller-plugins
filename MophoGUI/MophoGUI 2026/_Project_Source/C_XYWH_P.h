#pragma once

namespace XYWH
{

	constexpr auto cbox_h = 16;
	constexpr auto cbox_item_h = cbox_h - 2;
	constexpr auto knob_diam = 38;
	constexpr auto toggle_diam = 14;

	constexpr auto cc_block_spacing = 62;
	constexpr auto cc_1_ctr_cy = 191;
	constexpr auto cc_2_ctr_cy = cc_1_ctr_cy + cc_block_spacing;
	constexpr auto cc_3_ctr_cy = cc_2_ctr_cy + cc_block_spacing;
	constexpr auto cc_4_ctr_cy = cc_3_ctr_cy + cc_block_spacing;
	constexpr auto cc_5_ctr_cy = cc_4_ctr_cy + cc_block_spacing;
	constexpr auto cc_amt_cx = 776;
	constexpr auto cc_dst_cx = 680;
	constexpr auto cc_dst_w = 136;

	constexpr auto clock_ctr_cy = 126;

	constexpr auto ctr_col_w = knob_diam + 7;
	constexpr auto ctr_col_1_cx = 48;
	constexpr auto ctr_col_2_cx = ctr_col_1_cx + ctr_col_w;
	constexpr auto ctr_col_3_cx = ctr_col_2_cx + ctr_col_w;
	constexpr auto ctr_col_4_cx = ctr_col_3_cx + ctr_col_w;
	constexpr auto ctr_col_5_cx = ctr_col_4_cx + ctr_col_w;
	constexpr auto ctr_col_6_cx = ctr_col_5_cx + ctr_col_w;
	constexpr auto ctr_col_7_cx = ctr_col_6_cx + ctr_col_w;
	constexpr auto ctr_col_8_cx = ctr_col_7_cx + ctr_col_w;
	constexpr auto ctr_col_9_cx = ctr_col_8_cx + ctr_col_w;
	constexpr auto ctr_col_10_cx = 500;
	constexpr auto ctr_col_10_w = 124;

	constexpr auto editor_init_w = 1273, editor_init_h = 626;

	constexpr auto env_3_row_1_cy = 531;
	constexpr auto env_3_row_2_cy = 583;

	constexpr auto env_block_spacing = 158;
	constexpr auto env_init_begin_x = 5.0f;
	constexpr auto env_init_end_x = 205.0f;
	constexpr auto env_init_max_y = 10.0f;
	constexpr auto env_init_min_y = 80.0f;
	constexpr auto env_stg_init_max_w = 43.0f;
	constexpr auto env_sust_init_w = 28.0f;
	constexpr auto env_init_h = 90;
	constexpr auto env_init_w = 210;
	constexpr auto env_init_x = 168;
	constexpr auto env_lpf_init_y = 154;
	constexpr auto env_vca_init_y = env_lpf_init_y + env_block_spacing;
	constexpr auto env_3_init_y = env_vca_init_y + env_block_spacing;

	constexpr auto flex_knb_cbx_spacing = 28;
	constexpr auto flex_knb_cbx_1_cy = 521;
	constexpr auto flex_knb_cbx_2_cy = flex_knb_cbx_1_cy + flex_knb_cbx_spacing;
	constexpr auto flex_knb_cbx_3_cy = flex_knb_cbx_2_cy + flex_knb_cbx_spacing;
	constexpr auto flex_knb_cbx_4_cy = flex_knb_cbx_3_cy + flex_knb_cbx_spacing;
	constexpr auto flex_knb_cbx_cx = 1089;
	constexpr auto flex_knb_cbx_w = 134;

	constexpr auto lfo_block_spacing = 155;
	constexpr auto lfo_1_amt_cx = 461;
	constexpr auto lfo_1_cbx_cx = 463;
	constexpr auto lfo_1_frq_cx = 416;
	constexpr auto lfo_1_snc_cx = 507;
	constexpr auto lfo_2_amt_cx = lfo_1_amt_cx + lfo_block_spacing;
	constexpr auto lfo_2_cbx_cx = lfo_1_cbx_cx + lfo_block_spacing;
	constexpr auto lfo_2_frq_cx = lfo_1_frq_cx + lfo_block_spacing;
	constexpr auto lfo_2_snc_cx = lfo_1_snc_cx + lfo_block_spacing;
	constexpr auto lfo_3_amt_cx = lfo_2_amt_cx + lfo_block_spacing;
	constexpr auto lfo_3_cbx_cx = lfo_2_cbx_cx + lfo_block_spacing;
	constexpr auto lfo_3_frq_cx = lfo_2_frq_cx + lfo_block_spacing;
	constexpr auto lfo_3_snc_cx = lfo_2_snc_cx + lfo_block_spacing;
	constexpr auto lfo_4_amt_cx = lfo_3_amt_cx + lfo_block_spacing;
	constexpr auto lfo_4_cbx_cx = lfo_3_cbx_cx + lfo_block_spacing;
	constexpr auto lfo_4_frq_cx = lfo_3_frq_cx + lfo_block_spacing;
	constexpr auto lfo_4_snc_cx = lfo_3_snc_cx + lfo_block_spacing;
	constexpr auto lfo_cbx_w = 134;
	constexpr auto lfo_dst_cy = 594;
	constexpr auto lfo_knb_cy = 515;
	constexpr auto lfo_shp_cy = 560;
	constexpr auto lfo_snc_cy = 526;
	constexpr auto lfo_snc_h = 36;
	constexpr auto lfo_snc_w = 28;
	constexpr auto lfo_tgl_cy = 515;

	constexpr auto lpf_row_1_cy = 215;
	constexpr auto lpf_row_2_cy = 267;

	constexpr auto mod_block_spacing = 78;
	constexpr auto mod_1_amt_cy = 201;
	constexpr auto mod_1_dst_cy = 218;
	constexpr auto mod_1_src_cy = 184;
	constexpr auto mod_2_amt_cy = mod_1_amt_cy + mod_block_spacing;
	constexpr auto mod_2_dst_cy = mod_1_dst_cy + mod_block_spacing;
	constexpr auto mod_2_src_cy = mod_1_src_cy + mod_block_spacing;
	constexpr auto mod_3_amt_cy = mod_2_amt_cy + mod_block_spacing;
	constexpr auto mod_3_dst_cy = mod_2_dst_cy + mod_block_spacing;
	constexpr auto mod_3_src_cy = mod_2_src_cy + mod_block_spacing;
	constexpr auto mod_4_amt_cy = mod_3_amt_cy + mod_block_spacing;
	constexpr auto mod_4_dst_cy = mod_3_dst_cy + mod_block_spacing;
	constexpr auto mod_4_src_cy = mod_3_src_cy + mod_block_spacing;
	constexpr auto mod_amt_cx = 575;
	constexpr auto mod_cbx_cx = 486;
	constexpr auto mod_cbx_w = 126;

	constexpr auto name_char_and_step_gap = 2;
	constexpr auto name_char_w = 12;
	constexpr auto name_char_spacing = name_char_w + name_char_and_step_gap;
	constexpr auto name_char_01_cx = 596;
	constexpr auto name_char_02_cx = name_char_01_cx + name_char_spacing;
	constexpr auto name_char_03_cx = name_char_02_cx + name_char_spacing;
	constexpr auto name_char_04_cx = name_char_03_cx + name_char_spacing;
	constexpr auto name_char_05_cx = name_char_04_cx + name_char_spacing;
	constexpr auto name_char_06_cx = name_char_05_cx + name_char_spacing;
	constexpr auto name_char_07_cx = name_char_06_cx + name_char_spacing;
	constexpr auto name_char_08_cx = name_char_07_cx + name_char_spacing;
	constexpr auto name_char_09_cx = name_char_08_cx + name_char_spacing;
	constexpr auto name_char_10_cx = name_char_09_cx + name_char_spacing;
	constexpr auto name_char_11_cx = name_char_10_cx + name_char_spacing;
	constexpr auto name_char_12_cx = name_char_11_cx + name_char_spacing;
	constexpr auto name_char_13_cx = name_char_12_cx + name_char_spacing;
	constexpr auto name_char_14_cx = name_char_13_cx + name_char_spacing;
	constexpr auto name_char_15_cx = name_char_14_cx + name_char_spacing;
	constexpr auto name_char_16_cx = name_char_15_cx + name_char_spacing;
	constexpr auto name_char_cy = 52;
	constexpr auto name_char_h = 17;

	constexpr auto osc_row_1_cy = 50;
	constexpr auto osc_row_2_cy = 110;
	constexpr auto osc_key_trk_1_cy = osc_row_1_cy + 11;
	constexpr auto osc_key_trk_2_cy = osc_row_2_cy + 11;
	constexpr auto osc_key_trk_h = 36;
	constexpr auto osc_key_trk_w = 34;

	constexpr auto push_it_knb_cy = 528;
	constexpr auto push_it_mode_cx = 1215;
	constexpr auto push_it_mode_cy = 577;
	constexpr auto push_it_mode_w = 88;
	constexpr auto push_it_pitch_cx = 1191;
	constexpr auto push_it_velo_cx = 1239;

	constexpr auto seq_step_h = 26;
	constexpr auto seq_step_w = 26;
	constexpr auto seq_step_spacing = seq_step_w + name_char_and_step_gap;
	constexpr auto seq_step_01_cx = 825;
	constexpr auto seq_step_02_cx = seq_step_01_cx + seq_step_spacing;
	constexpr auto seq_step_03_cx = seq_step_02_cx + seq_step_spacing;
	constexpr auto seq_step_04_cx = seq_step_03_cx + seq_step_spacing;
	constexpr auto seq_step_05_cx = seq_step_04_cx + seq_step_spacing;
	constexpr auto seq_step_06_cx = seq_step_05_cx + seq_step_spacing;
	constexpr auto seq_step_07_cx = seq_step_06_cx + seq_step_spacing;
	constexpr auto seq_step_08_cx = seq_step_07_cx + seq_step_spacing;
	constexpr auto seq_step_09_cx = seq_step_08_cx + seq_step_spacing;
	constexpr auto seq_step_10_cx = seq_step_09_cx + seq_step_spacing;
	constexpr auto seq_step_11_cx = seq_step_10_cx + seq_step_spacing;
	constexpr auto seq_step_12_cx = seq_step_11_cx + seq_step_spacing;
	constexpr auto seq_step_13_cx = seq_step_12_cx + seq_step_spacing;
	constexpr auto seq_step_14_cx = seq_step_13_cx + seq_step_spacing;
	constexpr auto seq_step_15_cx = seq_step_14_cx + seq_step_spacing;
	constexpr auto seq_step_16_cx = seq_step_15_cx + seq_step_spacing;
	constexpr auto seq_trk_block_spacing = 83;
	constexpr auto seq_trk_1_dst_cy = 169;
	constexpr auto seq_trk_1_stp_cy = 196;
	constexpr auto seq_trk_2_dst_cy = seq_trk_1_dst_cy + seq_trk_block_spacing;
	constexpr auto seq_trk_2_stp_cy = seq_trk_1_stp_cy + seq_trk_block_spacing;
	constexpr auto seq_trk_3_dst_cy = seq_trk_2_dst_cy + seq_trk_block_spacing;
	constexpr auto seq_trk_3_stp_cy = seq_trk_2_stp_cy + seq_trk_block_spacing;
	constexpr auto seq_trk_4_dst_cy = seq_trk_3_dst_cy + seq_trk_block_spacing;
	constexpr auto seq_trk_4_stp_cy = seq_trk_3_stp_cy + seq_trk_block_spacing;
	constexpr auto seq_trk_dst_cx = 1065;
	constexpr auto seq_trk_dst_w = 126;

	constexpr auto vca_row_1_cy = 373;
	constexpr auto vca_row_2_cy = 425;

}
