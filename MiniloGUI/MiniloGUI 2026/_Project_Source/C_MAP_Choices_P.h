#pragma once

#include "C_ID_Exp_P.h"
#include "D_BUILD_Choices_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, StringArray> choices{
		//osc
		{ ID::exp_osc_1_octave, Choices_For::exp_osc_octave() },
		{ ID::exp_osc_1_wave, Choices_For::exp_osc_and_lfo_wave() },
		{ ID::exp_osc_1_pitch_fine, Choices_For::exp_osc_pitch_fine() },
		{ ID::exp_osc_1_shape, Choices_For::unsigned_int(1023) },
		{ ID::exp_osc_2_octave, Choices_For::exp_osc_octave() },
		{ ID::exp_osc_2_wave, Choices_For::exp_osc_and_lfo_wave() },
		{ ID::exp_osc_2_pitch_fine, Choices_For::exp_osc_pitch_fine() },
		{ ID::exp_osc_2_shape, Choices_For::unsigned_int(1023) },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, Choices_For::unsigned_int(1023) },
		{ ID::exp_osc_2_pitch_eg_int, Choices_For::exp_osc_2_pitch_eg_int() },
		{ ID::exp_osc_2_sync, Choices_For::off_on() },
		{ ID::exp_osc_2_ring_mod, Choices_For::off_on() },
		//mix
		{ ID::exp_mix_osc_1, Choices_For::unsigned_int(1023) },
		{ ID::exp_mix_osc_2, Choices_For::unsigned_int(1023) },
		{ ID::exp_mix_noise, Choices_For::unsigned_int(1023) },
		//lpf
		{ ID::exp_lpf_freq, Choices_For::unsigned_int(1023) },
		{ ID::exp_lpf_reso, Choices_For::unsigned_int(1023) },
		{ ID::exp_lpf_eg_int, Choices_For::exp_lpf_eg_int() },
		{ ID::exp_lpf_type, Choices_For::exp_lpf_type() },
		{ ID::exp_lpf_key_track, Choices_For::exp_zero_50_100() },
		{ ID::exp_lpf_velo_amt, Choices_For::exp_zero_50_100() },
		//vca env
		{ ID::exp_vca_env_attack, Choices_For::unsigned_int(1023) },
		{ ID::exp_vca_env_decay, Choices_For::unsigned_int(1023) },
		{ ID::exp_vca_env_sustain, Choices_For::unsigned_int(1023) },
		{ ID::exp_vca_env_release, Choices_For::unsigned_int(1023) },
		//env
		{ ID::exp_env_attack, Choices_For::unsigned_int(1023) },
		{ ID::exp_env_decay, Choices_For::unsigned_int(1023) },
		{ ID::exp_env_sustain, Choices_For::unsigned_int(1023) },
		{ ID::exp_env_release, Choices_For::unsigned_int(1023) },
		//lfo
		{ ID::exp_lfo_wave, Choices_For::exp_osc_and_lfo_wave() },
		{ ID::exp_lfo_eg_mod, Choices_For::exp_lfo_eg_mod() },
		{ ID::exp_lfo_rate, Choices_For::exp_lfo_rate() },
		{ ID::exp_lfo_int, Choices_For::unsigned_int(1023) },
		{ ID::exp_lfo_target, Choices_For::exp_lfo_target() },
		//delay
		{ ID::exp_delay_hpf_freq, Choices_For::unsigned_int(1023) },
		{ ID::exp_delay_time, Choices_For::unsigned_int(1023) },
		{ ID::exp_delay_feedback, Choices_For::unsigned_int(1023) },
		{ ID::exp_delay_routing, Choices_For::exp_delay_routing() },
		//voice mode depth
		{ ID::exp_voice_mode_depth, Choices_For::exp_voice_mode_depth() }
	};

}
