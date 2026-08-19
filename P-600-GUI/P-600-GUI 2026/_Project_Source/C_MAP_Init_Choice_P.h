#pragma once

#include "C_ID_Exp_P.h"

namespace MAP
{

	static const std::unordered_map<String, int> init_choice{
		//osc
		{ ID::exp_unison_track, 0 },
		{ ID::exp_osc_a_pitch, 12 },
		{ ID::exp_osc_a_sync, 0 },
		{ ID::exp_osc_a_saw, 0 },
		{ ID::exp_osc_a_tri, 1 },
		{ ID::exp_osc_a_pulse, 0 },
		{ ID::exp_osc_a_pulse_w, 64 },
		{ ID::exp_osc_b_pitch, 12 },
		{ ID::exp_osc_b_fine, 0 },
		{ ID::exp_osc_b_saw, 0 },
		{ ID::exp_osc_b_tri, 1 },
		{ ID::exp_osc_b_pulse, 0 },
		{ ID::exp_osc_b_pulse_w, 64 },
		{ ID::exp_mixer, 32 },
		{ ID::exp_glide, 0 },
		//filter
		{ ID::exp_filter_cutoff, 64 },
		{ ID::exp_filter_reso, 32 },
		{ ID::exp_filter_env_amt, 0 },
		{ ID::exp_filter_key_track, 2 },
		{ ID::exp_filter_env_attack, 0 },
		{ ID::exp_filter_env_decay, 0 },
		{ ID::exp_filter_env_sustain, 0 },
		{ ID::exp_filter_env_release, 0 },
		//amp
		{ ID::exp_amp_env_attack, 0 },
		{ ID::exp_amp_env_decay, 0 },
		{ ID::exp_amp_env_sustain, 15 },
		{ ID::exp_amp_env_release, 0 },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, 0 },
		{ ID::exp_p_mod_amt_osc_b, 0 },
		{ ID::exp_p_mod_dest_osc_a_freq, 0 },
		{ ID::exp_p_mod_dest_filter, 0 },
		//lfo
		{ ID::exp_lfo_freq, 0 },
		{ ID::exp_lfo_shape, 1 },
		{ ID::exp_lfo_init_amt, 0 },
		{ ID::exp_lfo_dest_osc_pitch, 0 },
		{ ID::exp_lfo_dest_osc_pw, 0 },
		{ ID::exp_lfo_dest_filter, 0 },
	};

}
