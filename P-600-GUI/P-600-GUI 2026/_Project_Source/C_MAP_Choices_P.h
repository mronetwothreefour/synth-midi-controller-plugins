#pragma once

#include "C_ID_EXP_P.h"
#include "D_BUILD_Choices_P.h"

using Choices = Build_Choices;

namespace MAP
{

	static const std::unordered_map<String, StringArray> choices{
		{ ID::exp_unison_track, Choices::off_on() },
		{ ID::exp_osc_a_pitch, Choices::osc_pitch(49) },
		{ ID::exp_osc_a_sync, Choices::off_on() },
		{ ID::exp_osc_a_saw, Choices::off_on() },
		{ ID::exp_osc_a_tri, Choices::off_on() },
		{ ID::exp_osc_a_pulse, Choices::off_on() },
		{ ID::exp_osc_a_pulse_w, Choices::unsigned_int(127) },
		{ ID::exp_osc_b_pitch, Choices::osc_pitch(49) },
		{ ID::exp_osc_b_fine, Choices::unsigned_int(127) },
		{ ID::exp_osc_b_saw, Choices::off_on() },
		{ ID::exp_osc_b_tri, Choices::off_on() },
		{ ID::exp_osc_b_pulse, Choices::off_on() },
		{ ID::exp_osc_b_pulse_w, Choices::unsigned_int(127) },
		{ ID::exp_mixer, Choices::unsigned_int(63) },
		{ ID::exp_glide, Choices::unsigned_int(15) },
		{ ID::exp_filter_cutoff, Choices::unsigned_int(127) },
		{ ID::exp_filter_reso, Choices::unsigned_int(63) },
		{ ID::exp_filter_env_amt, Choices::unsigned_int(15) },
		{ ID::exp_filter_key_track, Choices::filter_key_track() },
		{ ID::exp_filter_env_attack, Choices::unsigned_int(15) },
		{ ID::exp_filter_env_decay, Choices::unsigned_int(15) },
		{ ID::exp_filter_env_sustain, Choices::unsigned_int(15) },
		{ ID::exp_filter_env_release, Choices::unsigned_int(15) },
		{ ID::exp_amp_env_attack, Choices::unsigned_int(15) },
		{ ID::exp_amp_env_decay, Choices::unsigned_int(15) },
		{ ID::exp_amp_env_sustain, Choices::unsigned_int(15) },
		{ ID::exp_amp_env_release, Choices::unsigned_int(15) },
		{ ID::exp_p_mod_amt_filter_env, Choices::unsigned_int(15) },
		{ ID::exp_p_mod_amt_osc_b, Choices::unsigned_int(127) },
		{ ID::exp_p_mod_dest_osc_a_freq, Choices::off_on() },
		{ ID::exp_p_mod_dest_filter, Choices::off_on() },
		{ ID::exp_lfo_freq, Choices::unsigned_int(15) },
		{ ID::exp_lfo_shape, Choices::lfo_shape() },
		{ ID::exp_lfo_init_amt, Choices::unsigned_int(31) },
		{ ID::exp_lfo_dest_osc_pitch, Choices::off_on() },
		{ ID::exp_lfo_dest_osc_pw, Choices::off_on() },
		{ ID::exp_lfo_dest_filter, Choices::off_on() },
	};

}
