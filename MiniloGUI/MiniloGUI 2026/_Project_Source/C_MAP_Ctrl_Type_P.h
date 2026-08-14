#pragma once

#include "C_ENUM_P.h"
#include "C_ID_Exp_P.h"

using namespace ENUM;

namespace MAP
{

	static const std::unordered_map<String, Ctrl> ctrl_type{
		//osc
		{ ID::exp_osc_1_octave, Ctrl::switch_osc_octave },
		{ ID::exp_osc_1_wave, Ctrl::switch_3_pole },
		{ ID::exp_osc_1_pitch_fine, Ctrl::knob_osc_pitch_fine },
		{ ID::exp_osc_1_shape, Ctrl::knob },
		{ ID::exp_osc_2_octave, Ctrl::switch_osc_octave },
		{ ID::exp_osc_2_wave, Ctrl::switch_3_pole },
		{ ID::exp_osc_2_pitch_fine, Ctrl::knob_osc_pitch_fine },
		{ ID::exp_osc_2_shape, Ctrl::knob },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, Ctrl::knob  },
		{ ID::exp_osc_2_pitch_eg_int, Ctrl::knob_osc_2_pitch_eg_int },
		{ ID::exp_osc_2_sync, Ctrl::switch_2_pole },
		{ ID::exp_osc_2_ring_mod, Ctrl::switch_2_pole },
		//mix
		{ ID::exp_mix_osc_1, Ctrl::knob },
		{ ID::exp_mix_osc_2, Ctrl::knob },
		{ ID::exp_mix_noise, Ctrl::knob },
		//lpf
		{ ID::exp_lpf_freq, Ctrl::knob_lpf_freq },
		{ ID::exp_lpf_reso, Ctrl::knob },
		{ ID::exp_lpf_eg_int, Ctrl::knob_lpf_eg_int },
		{ ID::exp_lpf_type, Ctrl::switch_lpf_type },
		{ ID::exp_lpf_key_track, Ctrl::switch_3_pole },
		{ ID::exp_lpf_velo_amt, Ctrl::switch_3_pole },
		//vca env
		{ ID::exp_vca_env_attack, Ctrl::knob },
		{ ID::exp_vca_env_decay, Ctrl::knob },
		{ ID::exp_vca_env_sustain, Ctrl::knob },
		{ ID::exp_vca_env_release, Ctrl::knob },
		//env
		{ ID::exp_env_attack, Ctrl::knob },
		{ ID::exp_env_decay, Ctrl::knob },
		{ ID::exp_env_sustain, Ctrl::knob },
		{ ID::exp_env_release, Ctrl::knob },
		//lfo
		{ ID::exp_lfo_wave, Ctrl::switch_3_pole },
		{ ID::exp_lfo_eg_mod, Ctrl::switch_3_pole },
		{ ID::exp_lfo_rate, Ctrl::knob_lfo_rate },
		{ ID::exp_lfo_int, Ctrl::knob },
		{ ID::exp_lfo_target, Ctrl::switch_3_pole },
		//delay
		{ ID::exp_delay_hpf_freq, Ctrl::knob },
		{ ID::exp_delay_time, Ctrl::knob },
		{ ID::exp_delay_feedback, Ctrl::knob },
		{ ID::exp_delay_routing, Ctrl::switch_3_pole },
		//voice mode depth
		{ ID::exp_voice_mode_depth, Ctrl::knob_voice_mode_depth }
	};

}
