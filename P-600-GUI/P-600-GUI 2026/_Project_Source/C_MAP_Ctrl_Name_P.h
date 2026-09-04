#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> ctrl_name{
		//osc
		{ ID::exp_unison_track, NAME::switch_2_pole },
		{ ID::exp_osc_a_pitch, NAME::knob_pitch },
		{ ID::exp_osc_a_sync, NAME::switch_2_pole },
		{ ID::exp_osc_a_saw, NAME::switch_2_pole },
		{ ID::exp_osc_a_tri, NAME::switch_2_pole },
		{ ID::exp_osc_a_pulse, NAME::switch_2_pole },
		{ ID::exp_osc_a_pulse_w, NAME::knob_u_int_7_bit },
		{ ID::exp_osc_b_pitch, NAME::knob_pitch },
		{ ID::exp_osc_b_fine, NAME::knob_u_int_7_bit },
		{ ID::exp_osc_b_saw, NAME::switch_2_pole },
		{ ID::exp_osc_b_tri, NAME::switch_2_pole },
		{ ID::exp_osc_b_pulse, NAME::switch_2_pole },
		{ ID::exp_osc_b_pulse_w, NAME::knob_u_int_7_bit },
		{ ID::exp_mixer, NAME::knob_u_int_6_bit },
		{ ID::exp_glide, NAME::knob_u_int_4_bit },
		//filter
		{ ID::exp_filter_cutoff, NAME::knob_u_int_7_bit },
		{ ID::exp_filter_reso, NAME::knob_u_int_6_bit },
		{ ID::exp_filter_env_amt, NAME::knob_u_int_4_bit },
		{ ID::exp_filter_key_track, NAME::switch_3_pole },
		{ ID::exp_filter_env_attack, NAME::knob_u_int_4_bit },
		{ ID::exp_filter_env_decay, NAME::knob_u_int_4_bit },
		{ ID::exp_filter_env_sustain, NAME::knob_u_int_4_bit },
		{ ID::exp_filter_env_release, NAME::knob_u_int_4_bit },
		//amp
		{ ID::exp_amp_env_attack, NAME::knob_u_int_4_bit },
		{ ID::exp_amp_env_decay, NAME::knob_u_int_4_bit },
		{ ID::exp_amp_env_sustain, NAME::knob_u_int_4_bit },
		{ ID::exp_amp_env_release, NAME::knob_u_int_4_bit },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, NAME::knob_u_int_4_bit },
		{ ID::exp_p_mod_amt_osc_b, NAME::knob_u_int_7_bit },
		{ ID::exp_p_mod_dest_osc_a_freq, NAME::switch_2_pole },
		{ ID::exp_p_mod_dest_filter, NAME::switch_2_pole },
		//lfo
		{ ID::exp_lfo_freq, NAME::knob_u_int_4_bit },
		{ ID::exp_lfo_shape, NAME::switch_2_pole },
		{ ID::exp_lfo_init_amt, NAME::knob_u_int_5_bit },
		{ ID::exp_lfo_dest_osc_pitch, NAME::switch_2_pole },
		{ ID::exp_lfo_dest_osc_pw, NAME::switch_2_pole },
		{ ID::exp_lfo_dest_filter, NAME::switch_2_pole },
	};

}
