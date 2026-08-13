#pragma once

#include "C_ID_Exp_P.h"
#include "D_BUILD_Tip_P.h"

using Tip = Build_Tip;

namespace MAP
{

	static const std::unordered_map<String, String> tip{
		//osc
		{ ID::exp_unison_track, Tip::exp_unison_track() },
		{ ID::exp_osc_a_pitch, Tip::exp_osc_pitch("A") },
		{ ID::exp_osc_a_sync, Tip::exp_osc_a_sync() },
		{ ID::exp_osc_a_saw, Tip::exp_osc_saw("A") },
		{ ID::exp_osc_a_tri, Tip::exp_osc_tri("A") },
		{ ID::exp_osc_a_pulse, Tip::exp_osc_pulse("A") },
		{ ID::exp_osc_a_pulse_w, Tip::exp_osc_pulse_w("A") },
		{ ID::exp_osc_b_pitch, Tip::exp_osc_pitch("B") },
		{ ID::exp_osc_b_fine, Tip::exp_osc_b_fine() },
		{ ID::exp_osc_a_saw, Tip::exp_osc_saw("B") },
		{ ID::exp_osc_a_tri, Tip::exp_osc_tri("B") },
		{ ID::exp_osc_a_pulse, Tip::exp_osc_pulse("B") },
		{ ID::exp_osc_a_pulse_w, Tip::exp_osc_pulse_w("B") },
		{ ID::exp_mixer, Tip::exp_mixer() },
		{ ID::exp_glide, Tip::exp_glide() },
		//filter
		{ ID::exp_filter_cutoff, Tip::exp_filter_cutoff() },
		{ ID::exp_filter_reso, Tip::exp_filter_reso() },
		{ ID::exp_filter_env_amt, Tip::exp_filter_env_amt() },
		{ ID::exp_filter_key_track, Tip::exp_filter_key_track() },
		{ ID::exp_filter_env_attack, Tip::exp_env_attack(true) },
		{ ID::exp_filter_env_decay, Tip::exp_env_decay(true) },
		{ ID::exp_filter_env_sustain, Tip::exp_env_sustain(true) },
		{ ID::exp_filter_env_release, Tip::exp_env_release(true) },
		//amp
		{ ID::exp_amp_env_attack, Tip::exp_env_attack() },
		{ ID::exp_amp_env_decay, Tip::exp_env_decay() },
		{ ID::exp_amp_env_sustain, Tip::exp_env_sustain() },
		{ ID::exp_amp_env_release, Tip::exp_env_release() },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, Tip::exp_poly_mod_amt_filter_env() },
		{ ID::exp_p_mod_amt_osc_b, Tip::exp_poly_mod_amt_osc_b() },
		{ ID::exp_p_mod_dest_osc_a_freq, Tip::exp_poly_mod_dest_osc_a_freq() },
		{ ID::exp_p_mod_dest_filter, Tip::exp_poly_mod_dest_filter_freq() },
		//lfo
		{ ID::exp_lfo_freq, Tip::exp_lfo_freq() },
		{ ID::exp_lfo_shape, Tip::exp_lfo_shape() },
		{ ID::exp_lfo_init_amt, Tip::exp_lfo_init_amt() },
		{ ID::exp_lfo_dest_osc_pitch, Tip::exp_lfo_dest_osc_pitch() },
		{ ID::exp_lfo_dest_osc_pw, Tip::exp_lfo_dest_osc_pw() },
		{ ID::exp_lfo_dest_filter, Tip::exp_lfo_dest_filter() },
	};

}
