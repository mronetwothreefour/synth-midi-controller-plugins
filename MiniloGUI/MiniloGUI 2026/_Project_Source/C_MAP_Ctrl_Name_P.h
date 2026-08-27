#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> ctrl_name{
		//osc
		{ ID::exp_osc_1_octave, NAME::switch_osc_octave },
		{ ID::exp_osc_1_wave, NAME::switch_3_pole },
		{ ID::exp_osc_1_pitch_fine, NAME::knob_osc_pitch_fine },
		{ ID::exp_osc_1_shape, NAME::knob },
		{ ID::exp_osc_2_octave, NAME::switch_osc_octave },
		{ ID::exp_osc_2_wave, NAME::switch_3_pole },
		{ ID::exp_osc_2_pitch_fine, NAME::knob_osc_pitch_fine },
		{ ID::exp_osc_2_shape, NAME::knob },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, NAME::knob  },
		{ ID::exp_osc_2_pitch_eg_int, NAME::knob_osc_2_pitch_eg_int },
		{ ID::exp_osc_2_sync, NAME::switch_2_pole },
		{ ID::exp_osc_2_ring_mod, NAME::switch_2_pole },
		//mix
		{ ID::exp_mix_osc_1, NAME::knob },
		{ ID::exp_mix_osc_2, NAME::knob },
		{ ID::exp_mix_noise, NAME::knob },
		//lpf
		{ ID::exp_lpf_freq, NAME::knob_lpf_freq },
		{ ID::exp_lpf_reso, NAME::knob },
		{ ID::exp_lpf_eg_int, NAME::knob_lpf_eg_int },
		{ ID::exp_lpf_type, NAME::switch_lpf_type },
		{ ID::exp_lpf_key_track, NAME::switch_3_pole },
		{ ID::exp_lpf_velo_amt, NAME::switch_3_pole },
		//vca env
		{ ID::exp_vca_env_attack, NAME::knob },
		{ ID::exp_vca_env_decay, NAME::knob },
		{ ID::exp_vca_env_sustain, NAME::knob },
		{ ID::exp_vca_env_release, NAME::knob },
		//env
		{ ID::exp_env_attack, NAME::knob },
		{ ID::exp_env_decay, NAME::knob },
		{ ID::exp_env_sustain, NAME::knob },
		{ ID::exp_env_release, NAME::knob },
		//lfo
		{ ID::exp_lfo_wave, NAME::switch_3_pole },
		{ ID::exp_lfo_eg_mod, NAME::switch_3_pole },
		{ ID::exp_lfo_rate, NAME::knob_lfo_rate },
		{ ID::exp_lfo_int, NAME::knob },
		{ ID::exp_lfo_target, NAME::switch_3_pole },
		//delay
		{ ID::exp_delay_hpf_freq, NAME::knob },
		{ ID::exp_delay_time, NAME::knob },
		{ ID::exp_delay_feedback, NAME::knob },
		{ ID::exp_delay_routing, NAME::switch_3_pole },
		//voice mode depth
		{ ID::exp_voice_mode_depth, NAME::knob_voice_mode_depth }
	};

}
