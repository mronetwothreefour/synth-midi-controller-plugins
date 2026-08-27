#pragma once

#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> exp_name{
		//osc
		{ ID::exp_osc_1_octave, "Oscillator 1 Octave" },
		{ ID::exp_osc_1_wave, "Oscillator 1 Wave" },
		{ ID::exp_osc_1_pitch_fine, "Oscillator 1 Pitch Fine Tune" },
		{ ID::exp_osc_1_shape, "Oscillator 1 Shape" },
		{ ID::exp_osc_2_octave, "Oscillator 2 Octave" },
		{ ID::exp_osc_2_wave, "Oscillator 2 Wave" },
		{ ID::exp_osc_2_pitch_fine, "Oscillator 2 Pitch Fine Tune" },
		{ ID::exp_osc_2_shape, "Oscillator 2 Shape" },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, "Oscillator 2 Cross-Modulation Depth" },
		{ ID::exp_osc_2_pitch_eg_int, "Oscillator 2 Pitch EG Intensity" },
		{ ID::exp_osc_2_sync, "Oscillator 2 Sync" },
		{ ID::exp_osc_2_ring_mod, "Oscillator 2 Ring Modulation" },
		//mix
		{ ID::exp_mix_osc_1, "Oscillator 1 Level" },
		{ ID::exp_mix_osc_2, "Oscillator 2 Level" },
		{ ID::exp_mix_noise, "Noise Level" },
		//lpf
		{ ID::exp_lpf_freq, "LPF Cutoff Frequency" },
		{ ID::exp_lpf_reso, "LPF Resonance" },
		{ ID::exp_lpf_eg_int, "LPF EG Intensity" },
		{ ID::exp_lpf_type, "LPF Type" },
		{ ID::exp_lpf_key_track, "LPF Key Tracking" },
		{ ID::exp_lpf_velo_amt, "LPF Velocity Amount" },
		//vca env
		{ ID::exp_vca_env_attack, "VCA Envelope Attack" },
		{ ID::exp_vca_env_decay, "VCA Envelope Decay" },
		{ ID::exp_vca_env_sustain, "VCA Envelope Sustain" },
		{ ID::exp_vca_env_release, "VCA Envelope Release" },
		//env
		{ ID::exp_env_attack, "Envelope Attack" },
		{ ID::exp_env_decay, "Envelope Decay" },
		{ ID::exp_env_sustain, "Envelope Sustain" },
		{ ID::exp_env_release, "Envelope Release" },
		//lfo
		{ ID::exp_lfo_wave, "LFO Wave" },
		{ ID::exp_lfo_eg_mod, "LFO EG Modulation Target" },
		{ ID::exp_lfo_rate, "LFO Rate" },
		{ ID::exp_lfo_int, "LFO Intensity" },
		{ ID::exp_lfo_target, "LFO Modulation Target" },
		//delay
		{ ID::exp_delay_hpf_freq, "Delay HPF Cutoff Frequency" },
		{ ID::exp_delay_time, "Delay Time" },
		{ ID::exp_delay_feedback, "Delay Feedback" },
		{ ID::exp_delay_routing, "Delay Output Routing" },
		//voice mode depth
		{ ID::exp_voice_mode_depth, "Voice Mode Depth" }
	};

}
