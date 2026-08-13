#pragma once

#include "C_ID_EXP_P.h"
#include "D_BUILD_Choices_P.h"

using Choices = Build_Choices;

namespace MAP
{

	static const std::unordered_map<String, StringArray> choices{
		//osc
		{ ID::exp_osc_1_octave, Choices::exp_osc_octave() },
		{ ID::exp_osc_1_wave, Choices::exp_osc_and_lfo_wave() },
		{ ID::exp_osc_1_pitch_fine, Choices::exp_osc_pitch_fine() },
		{ ID::exp_osc_1_shape, Choices::unsigned_int(1023) },
		{ ID::exp_osc_2_octave, Choices::exp_osc_octave() },
		{ ID::exp_osc_2_wave, Choices::exp_osc_and_lfo_wave() },
		{ ID::exp_osc_2_pitch_fine, Choices::exp_osc_pitch_fine() },
		{ ID::exp_osc_2_shape, Choices::unsigned_int(1023) },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, Choices::unsigned_int(1023) },
		{ ID::exp_osc_2_pitch_eg_int, Choices::exp_osc_2_pitch_eg_int() },
		{ ID::exp_osc_2_sync, Choices::off_on() },
		{ ID::exp_osc_2_ring_mod, Choices::off_on() },
		//mix
		{ ID::exp_mix_osc_1, Choices::unsigned_int(1023) },
		{ ID::exp_mix_osc_2, Choices::unsigned_int(1023) },
		{ ID::exp_mix_noise, Choices::unsigned_int(1023) },
		//lpf
		{ ID::exp_lpf_freq, Choices::unsigned_int(1023) },
		{ ID::exp_lpf_reso, Choices::unsigned_int(1023) },
		{ ID::exp_lpf_eg_int, Choices::exp_lpf_eg_int() },
		{ ID::exp_lpf_type, Choices::exp_lpf_type() },
		{ ID::exp_lpf_key_track, Choices::exp_zero_50_100() },
		{ ID::exp_lpf_velo_amt, Choices::exp_zero_50_100() },
		//vca env
		{ ID::exp_vca_env_attack, Choices::unsigned_int(1023) },
		{ ID::exp_vca_env_decay, Choices::unsigned_int(1023) },
		{ ID::exp_vca_env_sustain, Choices::unsigned_int(1023) },
		{ ID::exp_vca_env_release, Choices::unsigned_int(1023) },
		//env
		{ ID::exp_env_attack, Choices::unsigned_int(1023) },
		{ ID::exp_env_decay, Choices::unsigned_int(1023) },
		{ ID::exp_env_sustain, Choices::unsigned_int(1023) },
		{ ID::exp_env_release, Choices::unsigned_int(1023) },
		//lfo
		{ ID::exp_lfo_wave, Choices::exp_osc_and_lfo_wave() },
		{ ID::exp_lfo_eg_mod, Choices::exp_lfo_eg_mod() },
		{ ID::exp_lfo_rate, Choices::exp_lfo_rate() },
		{ ID::exp_lfo_int, Choices::unsigned_int(1023) },
		{ ID::exp_lfo_target, Choices::exp_lfo_target() },
		//delay
		{ ID::exp_delay_hpf_freq, Choices::unsigned_int(1023) },
		{ ID::exp_delay_time, Choices::unsigned_int(1023) },
		{ ID::exp_delay_feedback, Choices::unsigned_int(1023) },
		{ ID::exp_delay_routing, Choices::exp_delay_routing() },
		//voice mode depth
		{ ID::exp_voice_mode_depth, Choices::exp_voice_mode_depth() }
	};

}
