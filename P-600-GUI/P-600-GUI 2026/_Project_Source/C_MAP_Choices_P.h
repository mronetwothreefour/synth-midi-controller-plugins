#pragma once

#include "C_ID_Main_P.h"
#include "D_BUILD_Choices_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, StringArray> choices{
		//osc
		{ ID::exp_unison_track, Choices_For::off_on() },
		{ ID::exp_osc_a_pitch, Choices_For::osc_pitch(49) },
		{ ID::exp_osc_a_sync, Choices_For::off_on() },
		{ ID::exp_osc_a_saw, Choices_For::off_on() },
		{ ID::exp_osc_a_tri, Choices_For::off_on() },
		{ ID::exp_osc_a_pulse, Choices_For::off_on() },
		{ ID::exp_osc_a_pulse_w, Choices_For::unsigned_int(127) },
		{ ID::exp_osc_b_pitch, Choices_For::osc_pitch(49) },
		{ ID::exp_osc_b_fine, Choices_For::unsigned_int(127) },
		{ ID::exp_osc_b_saw, Choices_For::off_on() },
		{ ID::exp_osc_b_tri, Choices_For::off_on() },
		{ ID::exp_osc_b_pulse, Choices_For::off_on() },
		{ ID::exp_osc_b_pulse_w, Choices_For::unsigned_int(127) },
		{ ID::exp_mixer, Choices_For::unsigned_int(63) },
		{ ID::exp_glide, Choices_For::unsigned_int(15) },
		//filter
		{ ID::exp_filter_cutoff, Choices_For::unsigned_int(127) },
		{ ID::exp_filter_reso, Choices_For::unsigned_int(63) },
		{ ID::exp_filter_env_amt, Choices_For::unsigned_int(15) },
		{ ID::exp_filter_key_track, Choices_For::exp_filter_key_track() },
		{ ID::exp_filter_env_attack, Choices_For::unsigned_int(15) },
		{ ID::exp_filter_env_decay, Choices_For::unsigned_int(15) },
		{ ID::exp_filter_env_sustain, Choices_For::unsigned_int(15) },
		{ ID::exp_filter_env_release, Choices_For::unsigned_int(15) },
		//amp
		{ ID::exp_amp_env_attack, Choices_For::unsigned_int(15) },
		{ ID::exp_amp_env_decay, Choices_For::unsigned_int(15) },
		{ ID::exp_amp_env_sustain, Choices_For::unsigned_int(15) },
		{ ID::exp_amp_env_release, Choices_For::unsigned_int(15) },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, Choices_For::unsigned_int(15) },
		{ ID::exp_p_mod_amt_osc_b, Choices_For::unsigned_int(127) },
		{ ID::exp_p_mod_dest_osc_a_freq, Choices_For::off_on() },
		{ ID::exp_p_mod_dest_filter, Choices_For::off_on() },
		//lfo
		{ ID::exp_lfo_freq, Choices_For::unsigned_int(15) },
		{ ID::exp_lfo_shape, Choices_For::exp_lfo_shape() },
		{ ID::exp_lfo_init_amt, Choices_For::unsigned_int(31) },
		{ ID::exp_lfo_dest_osc_pitch, Choices_For::off_on() },
		{ ID::exp_lfo_dest_osc_pw, Choices_For::off_on() },
		{ ID::exp_lfo_dest_filter, Choices_For::off_on() },
	};

}
