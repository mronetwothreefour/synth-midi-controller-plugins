#pragma once

#include "C_ID_EXP_P.h"
#include "D_BUILD_Choices_P.h"

using Choices = Build_Choices;

namespace MAP
{

	static const std::unordered_map<String, StringArray> choices{
		{ ID::exp_osc_1_octave, Choices::osc_octave() },
		{ ID::exp_osc_1_wave, Choices::osc_and_lfo_wave() },
		{ ID::exp_osc_1_pitch_fine, Choices::osc_pitch_fine() },
		{ ID::exp_osc_1_shape, Choices::unsigned_int(1023) },
		{ ID::exp_osc_2_octave, Choices::osc_octave() },
		{ ID::exp_osc_2_wave, Choices::osc_and_lfo_wave() },
		{ ID::exp_osc_2_pitch_fine, Choices::osc_pitch_fine() },
		{ ID::exp_osc_2_shape, Choices::unsigned_int(1023) },
		{ ID::exp_osc_2_xmod_depth, Choices::unsigned_int(1023) },
		{ ID::exp_osc_2_pitch_eg_int, Choices::osc_2_pitch_eg_int() },
		{ ID::exp_osc_2_sync, Choices::off_on() },
		{ ID::exp_osc_2_ring_mod, Choices::off_on() },
		{ ID::exp_mix_osc_1, Choices::unsigned_int(1023) },
		{ ID::exp_mix_osc_2, Choices::unsigned_int(1023) },
		{ ID::exp_mix_noise, Choices::unsigned_int(1023) },
		{ ID::exp_lpf_freq, Choices::unsigned_int(1023) },
		{ ID::exp_lpf_reso, Choices::unsigned_int(1023) },
		{ ID::exp_lpf_eg_int, Choices::lpf_eg_int() },
		{ ID::exp_lpf_type, Choices::lpf_type() },
		{ ID::exp_lpf_key_track, Choices::zero_50_100() },
		{ ID::exp_lpf_vel_amt, Choices::zero_50_100() },
		{ ID::exp_vca_env_attack, Choices::unsigned_int(1023) },
		{ ID::exp_vca_env_decay, Choices::unsigned_int(1023) },
		{ ID::exp_vca_env_sustain, Choices::unsigned_int(1023) },
		{ ID::exp_vca_env_release, Choices::unsigned_int(1023) },
		{ ID::exp_env_attack, Choices::unsigned_int(1023) },
		{ ID::exp_env_decay, Choices::unsigned_int(1023) },
		{ ID::exp_env_sustain, Choices::unsigned_int(1023) },
		{ ID::exp_env_release, Choices::unsigned_int(1023) },
		{ ID::exp_lfo_wave, Choices::osc_and_lfo_wave() },
		{ ID::exp_lfo_eg_mod, Choices::lfo_eg_mod() },
		{ ID::exp_lfo_rate, Choices::lfo_rate() },
		{ ID::exp_lfo_int, Choices::unsigned_int(1023) },
		{ ID::exp_lfo_target, Choices::lfo_target() },
		{ ID::exp_delay_hpf_freq, Choices::unsigned_int(1023) },
		{ ID::exp_delay_time, Choices::unsigned_int(1023) },
		{ ID::exp_delay_feedback, Choices::unsigned_int(1023) },
		{ ID::exp_delay_routing, Choices::delay_routing() },
		{ ID::exp_voice_mode_depth, Choices::voice_mode_depth() }
	};

}
