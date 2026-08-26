#pragma once

#include "C_ID_Main_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, String> tip{
		//osc
		{ ID::exp_unison_track, Tip_For::from_string_literal(SL::unison_track_tip) },
		{ ID::exp_osc_a_pitch, Tip_For::exp_osc_pitch("A") },
		{ ID::exp_osc_a_sync, Tip_For::from_string_literal(SL::osc_a_sync_tip) },
		{ ID::exp_osc_a_saw, Tip_For::exp_osc_saw("A") },
		{ ID::exp_osc_a_tri, Tip_For::exp_osc_tri("A") },
		{ ID::exp_osc_a_pulse, Tip_For::exp_osc_pulse("A") },
		{ ID::exp_osc_a_pulse_w, Tip_For::exp_osc_pulse_w("A") },
		{ ID::exp_osc_b_pitch, Tip_For::exp_osc_pitch("B") },
		{ ID::exp_osc_b_fine, Tip_For::from_string_literal(SL::osc_b_fine_tip) },
		{ ID::exp_osc_a_saw, Tip_For::exp_osc_saw("B") },
		{ ID::exp_osc_a_tri, Tip_For::exp_osc_tri("B") },
		{ ID::exp_osc_a_pulse, Tip_For::exp_osc_pulse("B") },
		{ ID::exp_osc_a_pulse_w, Tip_For::exp_osc_pulse_w("B") },
		{ ID::exp_mixer, Tip_For::from_string_literal(SL::mixer_tip) },
		{ ID::exp_glide, Tip_For::from_string_literal(SL::glide_tip) },
		//filter
		{ ID::exp_filter_cutoff, Tip_For::from_string_literal(SL::filter_cutoff_tip) },
		{ ID::exp_filter_reso, Tip_For::from_string_literal(SL::filter_reso_tip) },
		{ ID::exp_filter_env_amt, Tip_For::from_string_literal(SL::filter_env_amt_tip) },
		{ ID::exp_filter_key_track, Tip_For::from_string_literal(SL::filter_key_track_tip) },
		{ ID::exp_filter_env_attack, Tip_For::exp_env_attack(true) },
		{ ID::exp_filter_env_decay, Tip_For::exp_env_decay(true) },
		{ ID::exp_filter_env_sustain, Tip_For::exp_env_sustain(true) },
		{ ID::exp_filter_env_release, Tip_For::exp_env_release(true) },
		//amp
		{ ID::exp_amp_env_attack, Tip_For::exp_env_attack() },
		{ ID::exp_amp_env_decay, Tip_For::exp_env_decay() },
		{ ID::exp_amp_env_sustain, Tip_For::exp_env_sustain() },
		{ ID::exp_amp_env_release, Tip_For::exp_env_release() },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, Tip_For::from_string_literal(SL::poly_mod_src_filter_env_amt_tip) },
		{ ID::exp_p_mod_amt_osc_b, Tip_For::from_string_literal(SL::poly_mod_src_osc_b_amt_tip) },
		{ ID::exp_p_mod_dest_osc_a_freq, Tip_For::from_string_literal(SL::poly_mod_dest_osc_a_pitch_tip) },
		{ ID::exp_p_mod_dest_filter, Tip_For::from_string_literal(SL::poly_mod_dest_filter_freq_tip) },
		//lfo
		{ ID::exp_lfo_freq, Tip_For::from_string_literal(SL::lfo_freq_tip) },
		{ ID::exp_lfo_shape, Tip_For::from_string_literal(SL::lfo_shape_tip) },
		{ ID::exp_lfo_init_amt, Tip_For::from_string_literal(SL::lfo_init_amt_tip) },
		{ ID::exp_lfo_dest_osc_pitch, Tip_For::from_string_literal(SL::lfo_dest_osc_pitch_tip) },
		{ ID::exp_lfo_dest_osc_pw, Tip_For::from_string_literal(SL::lfo_dest_osc_pw_tip) },
		{ ID::exp_lfo_dest_filter, Tip_For::from_string_literal(SL::lfo_dest_filter_tip) },
	};

}
