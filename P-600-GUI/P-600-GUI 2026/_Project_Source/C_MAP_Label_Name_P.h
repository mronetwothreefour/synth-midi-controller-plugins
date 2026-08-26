#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> label_name{
		//osc
		{ ID::exp_unison_track, "" },
		{ ID::exp_osc_a_pitch, NAME::lbl_osc_pitch },
		{ ID::exp_osc_a_sync, "" },
		{ ID::exp_osc_a_saw, "" },
		{ ID::exp_osc_a_tri, "" },
		{ ID::exp_osc_a_pulse, "" },
		{ ID::exp_osc_a_pulse_w, NAME::lbl_u_int_7_bit },
		{ ID::exp_osc_b_pitch, NAME::lbl_osc_pitch },
		{ ID::exp_osc_b_fine, NAME::lbl_u_int_7_bit },
		{ ID::exp_osc_b_saw, "" },
		{ ID::exp_osc_b_tri, "" },
		{ ID::exp_osc_b_pulse, "" },
		{ ID::exp_osc_b_pulse_w, NAME::lbl_u_int_7_bit },
		{ ID::exp_mixer, NAME::lbl_u_int_6_bit },
		{ ID::exp_glide, NAME::lbl_u_int_4_bit },
		//filter
		{ ID::exp_filter_cutoff, NAME::lbl_u_int_7_bit },
		{ ID::exp_filter_reso, NAME::lbl_u_int_6_bit },
		{ ID::exp_filter_env_amt, NAME::lbl_u_int_4_bit },
		{ ID::exp_filter_key_track, "" },
		{ ID::exp_filter_env_attack, NAME::lbl_u_int_4_bit },
		{ ID::exp_filter_env_decay, NAME::lbl_u_int_4_bit },
		{ ID::exp_filter_env_sustain, NAME::lbl_u_int_4_bit },
		{ ID::exp_filter_env_release, NAME::lbl_u_int_4_bit },
		//amp
		{ ID::exp_amp_env_attack, NAME::lbl_u_int_4_bit },
		{ ID::exp_amp_env_decay, NAME::lbl_u_int_4_bit },
		{ ID::exp_amp_env_sustain, NAME::lbl_u_int_4_bit },
		{ ID::exp_amp_env_release, NAME::lbl_u_int_4_bit },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, NAME::lbl_u_int_4_bit },
		{ ID::exp_p_mod_amt_osc_b, NAME::lbl_u_int_7_bit },
		{ ID::exp_p_mod_dest_osc_a_freq, "" },
		{ ID::exp_p_mod_dest_filter, "" },
		//lfo
		{ ID::exp_lfo_freq, NAME::lbl_u_int_4_bit },
		{ ID::exp_lfo_shape, "" },
		{ ID::exp_lfo_init_amt, NAME::lbl_u_int_5_bit },
		{ ID::exp_lfo_dest_osc_pitch, "" },
		{ ID::exp_lfo_dest_osc_pw, "" },
		{ ID::exp_lfo_dest_filter, "" },
	};

}
