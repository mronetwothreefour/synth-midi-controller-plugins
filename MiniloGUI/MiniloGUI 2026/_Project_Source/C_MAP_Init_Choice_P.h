#pragma once

#include "C_ID_EXP_P.h"

namespace MAP
{

	static const std::unordered_map<String, int> init_choice{
		//osc
		{ ID::exp_osc_1_octave, 1 },
		{ ID::exp_osc_1_wave, 2 },
		{ ID::exp_osc_1_pitch_fine, 512 },
		{ ID::exp_osc_1_shape, 0 },
		{ ID::exp_osc_2_octave, 1 },
		{ ID::exp_osc_2_wave, 2 },
		{ ID::exp_osc_2_pitch_fine, 512 },
		{ ID::exp_osc_2_shape, 0 },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, 0 },
		{ ID::exp_osc_2_pitch_eg_int, 512 },
		{ ID::exp_osc_2_sync, 0 },
		{ ID::exp_osc_2_ring_mod, 0 },
		//mix
		{ ID::exp_mix_osc_1, 1023 },
		{ ID::exp_mix_osc_2, 0 },
		{ ID::exp_mix_noise, 0 },
		//lpf
		{ ID::exp_lpf_freq, 1023 },
		{ ID::exp_lpf_reso, 0 },
		{ ID::exp_lpf_eg_int, 512 },
		{ ID::exp_lpf_type, 1 },
		{ ID::exp_lpf_key_track, 0 },
		{ ID::exp_lpf_vel_amt, 0 },
		//vca env
		{ ID::exp_vca_env_attack, 0 },
		{ ID::exp_vca_env_decay, 512 },
		{ ID::exp_vca_env_sustain, 1023 },
		{ ID::exp_vca_env_release, 0 },
		//env
		{ ID::exp_env_attack, 0 },
		{ ID::exp_env_decay, 512 },
		{ ID::exp_env_sustain, 0 },
		{ ID::exp_env_release, 0 },
		//lfo
		{ ID::exp_lfo_wave, 1 },
		{ ID::exp_lfo_eg_mod, 0 },
		{ ID::exp_lfo_rate, 512 },
		{ ID::exp_lfo_int, 0 },
		{ ID::exp_lfo_target, 2 },
		//delay
		{ ID::exp_delay_hpf_freq, 256 },
		{ ID::exp_delay_time, 1023 },
		{ ID::exp_delay_feedback, 512 },
		{ ID::exp_delay_routing, 0 },
		//voice mode depth
		{ ID::exp_voice_mode_depth, 0 }
	};

}
