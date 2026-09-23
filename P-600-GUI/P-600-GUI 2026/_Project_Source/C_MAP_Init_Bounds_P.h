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
		{ ID::exp_unison_track, { true, 416, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_a_pitch, { true, osc_col_1_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_a_sync, { true, osc_col_2_cx, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_a_saw, { true, osc_col_3_cx, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_a_tri, { true, osc_col_4_cx, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_a_pulse, { true, osc_col_5_cx, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_a_pulse_w, { true, osc_col_6_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_b_pitch, { true, osc_col_1_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_b_fine, { true, osc_col_2_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_osc_b_saw, { true, osc_col_3_cx, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_b_tri, { true, osc_col_4_cx, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_b_pulse, { true, osc_col_5_cx, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_osc_b_pulse_w, { true, osc_col_6_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_mixer, { true, mix_glide_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_glide, { true, mix_glide_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_cutoff, { true, fltr_amp_col_1_cx, knob_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_reso, { true, fltr_amp_col_2_cx, knob_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_env_amt, { true, fltr_amp_col_3_cx, knob_row_1_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_key_track, { false, 1268, 48, 46, 48 } },
		{ ID::exp_filter_env_attack, { true, fltr_amp_col_1_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_env_decay, { true, fltr_amp_col_2_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_env_sustain, { true, fltr_amp_col_3_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_filter_env_release, { true, fltr_amp_col_4_cx, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_amp_env_attack, { true, fltr_amp_col_1_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_amp_env_decay, { true, fltr_amp_col_2_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_amp_env_sustain, { true, fltr_amp_col_3_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_amp_env_release, { true, fltr_amp_col_4_cx, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_p_mod_amt_filter_env, { true, 60, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_p_mod_amt_osc_b, { true, 184, knob_row_2_cy, knob_diam, knob_diam } },
		{ ID::exp_p_mod_dest_osc_a_freq, { true, 287, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_p_mod_dest_filter, { true, 347, sw_row_1_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_lfo_freq, { true, 60, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_lfo_shape, { true, 126, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_lfo_init_amt, { true, 207, knob_row_3_cy, knob_diam, knob_diam } },
		{ ID::exp_lfo_dest_osc_pitch, { true, 282, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_lfo_dest_osc_pw, { true, 342, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
		{ ID::exp_lfo_dest_filter, { true, 402, sw_row_2_cy, sw_2_pole_w, sw_2_pole_h } },
	};

}
