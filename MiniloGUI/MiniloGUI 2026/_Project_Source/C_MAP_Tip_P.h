#pragma once

#include "C_ID_Exp_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, String> tip{
		//osc
		{ ID::exp_osc_1_octave, Tip_For::exp_osc_octave(1) },
		{ ID::exp_osc_1_wave, Tip_For::exp_osc_wave(1) },
		{ ID::exp_osc_1_pitch_fine, Tip_For::exp_osc_pitch_fine(1) },
		{ ID::exp_osc_1_shape, Tip_For::exp_osc_shape(1) },
		{ ID::exp_osc_2_octave, Tip_For::exp_osc_octave(2) },
		{ ID::exp_osc_2_wave, Tip_For::exp_osc_wave(2) },
		{ ID::exp_osc_2_pitch_fine, Tip_For::exp_osc_pitch_fine(2) },
		{ ID::exp_osc_2_shape, Tip_For::exp_osc_shape(2) },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, Tip_For::exp_osc_2_xmod_depth() },
		{ ID::exp_osc_2_pitch_eg_int, Tip_For::exp_osc_2_pitch_eg_int() },
		{ ID::exp_osc_2_sync, Tip_For::exp_osc_2_sync() },
		{ ID::exp_osc_2_ring_mod, Tip_For::exp_osc_2_ring_mod() },
		//mix
		{ ID::exp_mix_osc_1, Tip_For::exp_level_knob(1)},
		{ ID::exp_mix_osc_2, Tip_For::exp_level_knob(2) },
		{ ID::exp_mix_noise, Tip_For::exp_level_knob(3) },
		//lpf
		{ ID::exp_lpf_freq, Tip_For::exp_lpf_freq() },
		{ ID::exp_lpf_reso, Tip_For::exp_lpf_reso() },
		{ ID::exp_lpf_eg_int, Tip_For::exp_lpf_eg_int() },
		{ ID::exp_lpf_type, Tip_For::exp_lpf_type() },
		{ ID::exp_lpf_key_track, Tip_For::exp_lpf_key_track() },
		{ ID::exp_lpf_velo_amt, Tip_For::exp_lpf_velo_amt() },
		//vca env
		{ ID::exp_vca_env_attack, Tip_For::exp_env_attack(true) },
		{ ID::exp_vca_env_decay, Tip_For::exp_env_decay(true) },
		{ ID::exp_vca_env_sustain, Tip_For::exp_env_sustain(true) },
		{ ID::exp_vca_env_release, Tip_For::exp_env_release(true) },
		//env
		{ ID::exp_env_attack, Tip_For::exp_env_attack() },
		{ ID::exp_env_decay, Tip_For::exp_env_decay() },
		{ ID::exp_env_sustain, Tip_For::exp_env_sustain() },
		{ ID::exp_env_release, Tip_For::exp_env_release() },
		//lfo
		{ ID::exp_lfo_wave, Tip_For::exp_lfo_wave() },
		{ ID::exp_lfo_eg_mod, Tip_For::exp_lfo_eg_mod() },
		{ ID::exp_lfo_rate, Tip_For::exp_lfo_rate() },
		{ ID::exp_lfo_int, Tip_For::exp_lfo_int() },
		{ ID::exp_lfo_target, Tip_For::exp_lfo_target() },
		//delay
		{ ID::exp_delay_hpf_freq, Tip_For::exp_delay_hpf_freq() },
		{ ID::exp_delay_time, Tip_For::exp_delay_time() },
		{ ID::exp_delay_feedback, Tip_For::exp_delay_feedback() },
		{ ID::exp_delay_routing, Tip_For::exp_delay_routing() },
		//voice mode depth
		{ ID::exp_voice_mode_depth, Tip_For::exp_voice_mode_depth() }
	};

}
