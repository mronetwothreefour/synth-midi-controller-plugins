#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_NAME_P.h"
#include "C_XYWH_P.h"

using namespace std;
using namespace XYWH;

namespace MAP
{

	static const unordered_map<string, tuple<bool, int, int, int, int>> init_bounds{
		{ ID::avp_voice_mode_btn_0, { false, btn_main_0_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_1, { false, btn_main_1_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_2, { false, btn_main_2_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_3, { false, btn_main_3_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_4, { false, btn_main_4_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_5, { false, btn_main_5_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_6, { false, btn_main_6_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_voice_mode_btn_7, { false, btn_main_7_x, btn_main_vmode_y, btn_main_vmode_w, btn_main_vmode_h } },
		{ ID::avp_keyboard_octave, { false, 42, 432, 64, 34 } },
		{ ID::avp_flex_sli_target, { false, 132, 441, 104, cbox_h } },
		{ ID::avp_flex_sli_range, { true, 269, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_flex_sli_bend_pos, { true, 329, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_flex_sli_bend_neg, { true, 389, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_lfo_sync_bpm_on, { true, 448, ctr_row_4_cy, switch_w, switch_h } },
		{ ID::avp_lfo_sync_key_on, { true, 493, ctr_row_4_cy, switch_w, switch_h } },
		{ ID::avp_lfo_sync_voice_on, { true, 538, ctr_row_4_cy, switch_w, switch_h } },
		{ ID::avp_porta_time, { true, 612, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_porta_mode_on, { false, 647, 423, 40, switch_h } },
		{ ID::avp_porta_sync_bpm_on, { false, 692, 423, switch_w, switch_h } },
		{ ID::avp_amp_mod_by_velo_amt, { true, 769, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_level, { true, 829, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_microtune_scale, { false, 875, 441, 82, cbox_h } },
		{ ID::avp_scale_key, { true, 992, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_fine_tune, { true, 1052, ctr_row_4_cy, knob_diam, knob_diam } },
		{ ID::avp_transpose, { true, 1112, ctr_row_4_cy, knob_diam, knob_diam } },

		{ ID::exp_osc_1_octave, { true, 64, ctr_row_1_cy, switch_w, switch_h } },
		{ ID::exp_osc_1_wave, { true, 124, ctr_row_1_cy, switch_w, switch_h } },
		{ ID::exp_osc_1_pitch_fine, { true, 184, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_1_shape, { true, 244, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_2_octave, { true, 64, ctr_row_2_cy, switch_w, switch_h } },
		{ ID::exp_osc_2_wave, { true, 124, ctr_row_2_cy, switch_w, switch_h } },
		{ ID::exp_osc_2_pitch_fine, { true, 184, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_2_shape, { true, 244, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_2_xmod_depth, { true, 64, ctr_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_2_pitch_eg_int, { true, 124, ctr_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_2_sync, { true, 184, ctr_row_3_cy, switch_w, switch_h } },
		{ ID::exp_osc_2_ring_mod, { true, 244, ctr_row_3_cy, switch_w, switch_h } },
		{ ID::exp_mix_osc_1, { true, mix_knb_cx, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_mix_osc_2, { true, mix_knb_cx, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_mix_noise, { true, mix_knb_cx, ctr_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_lpf_freq, { false, 408, 86, knob_diam_lpf_freq, knob_diam_lpf_freq } },
		{ ID::exp_lpf_reso, { true, 397, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_lpf_eg_int, { true, 469, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_lpf_type, { false, 363, 251, switch_w, switch_lpf_type_h } },
		{ ID::exp_lpf_key_track, { true, 434, ctr_row_3_cy, switch_w, switch_h } },
		{ ID::exp_lpf_velo_amt, { true, 479, ctr_row_3_cy, switch_w, switch_h } },
		{ ID::exp_vca_env_attack, { true, 559, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_vca_env_decay, { true, 627, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_vca_env_sustain, { true, 695, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_vca_env_release, { true, 763, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_env_attack, { true, 559, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_env_decay, { true, 627, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_env_sustain, { true, 695, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_env_release, { true, 763, ctr_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_lfo_wave, { true, 540, ctr_row_3_cy, switch_w, switch_h } },
		{ ID::exp_lfo_eg_mod, { true, 584, ctr_row_3_cy, 39, switch_h } },
		{ ID::exp_lfo_rate, { true, 627, ctr_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_lfo_int, { true, 695, ctr_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_lfo_target, { false, 744, 265, 50, switch_h } },
		{ ID::exp_delay_hpf_freq, { true, 848, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_delay_time, { true, 908, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_delay_feedback, { true, 968, ctr_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_delay_routing, { false, 1008, 77, 50, switch_h } },
		{ ID::exp_voice_mode_depth, { true, 1112, ctr_row_2_cy, knob_diam, knob_diam } },

		{ NAME::btn_main_global, { false, btn_main_4_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_microtune, { false, btn_main_7_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_pgm_bank, { false, btn_main_6_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_pull, { false, btn_main_1_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_push, { false, btn_main_0_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_redo, { false, btn_main_3_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_seq, { false, btn_main_5_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
		{ NAME::btn_main_undo, { false, btn_main_2_x, btn_main_small_y, btn_main_small_w, btn_main_small_h } },
	};

}
