#pragma once

#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> exp_name{
		//osc
		{ ID::exp_unison_track, "Unison Tracking" },
		{ ID::exp_osc_a_pitch, "Oscillator A Frequency" },
		{ ID::exp_osc_a_sync, "Oscillator A Sync" },
		{ ID::exp_osc_a_saw, "Oscillator A Shape: Sawtooth" },
		{ ID::exp_osc_a_tri, "Oscillator A Shape: Triangle" },
		{ ID::exp_osc_a_pulse, "Oscillator A Shape: Pulse" },
		{ ID::exp_osc_a_pulse_w, "Oscillator A Pulse Width" },
		{ ID::exp_osc_b_pitch, "Oscillator B Frequency" },
		{ ID::exp_osc_b_fine, "Oscillator B Fine Tune" },
		{ ID::exp_osc_b_saw, "Oscillator B Shape: Sawtooth" },
		{ ID::exp_osc_b_tri, "Oscillator B Shape: Triangle" },
		{ ID::exp_osc_b_pulse, "Oscillator B Shape: Pulse" },
		{ ID::exp_osc_b_pulse_w, "Oscillator B Pulse Width" },
		{ ID::exp_mixer, "Mixer" },
		{ ID::exp_glide, "Glide" },
		//filter
		{ ID::exp_filter_cutoff, "Filter Cutoff Frequency" },
		{ ID::exp_filter_reso, "Filter Resonance" },
		{ ID::exp_filter_env_amt, "Filter Envelope Amount" },
		{ ID::exp_filter_key_track, "Filter Keyboard Tracking" },
		{ ID::exp_filter_env_attack, "Filter Envelope Attack" },
		{ ID::exp_filter_env_decay, "Filter Envelope Decay" },
		{ ID::exp_filter_env_sustain, "Filter Envelope Sustain" },
		{ ID::exp_filter_env_release, "Filter Envelope Release" },
		//amp
		{ ID::exp_amp_env_attack, "Amplifier Envelope Attack" },
		{ ID::exp_amp_env_decay, "Amplifier Envelope Decay" },
		{ ID::exp_amp_env_sustain, "Amplifier Envelope Sustain" },
		{ ID::exp_amp_env_release, "Amplifier Envelope Release" },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, "Poly-Mod Source: Filter Envelope Amount" },
		{ ID::exp_p_mod_amt_osc_b, "Poly-Mod Source: Oscillator B Amount" },
		{ ID::exp_p_mod_dest_osc_a_freq, "Poly-Mod Destination: Oscillator A Frequency" },
		{ ID::exp_p_mod_dest_filter, "Poly-Mod Destination: Filter Cutoff Frequency" },
		//lfo
		{ ID::exp_lfo_freq, "LFO Frequency" },
		{ ID::exp_lfo_shape, "LFO Wave Shape" },
		{ ID::exp_lfo_init_amt, "LFO Initial Amount" },
		{ ID::exp_lfo_dest_osc_pitch, "LFO Destination: Oscillator Frequency" },
		{ ID::exp_lfo_dest_osc_pw, "LFO Destination: Oscillator Pulse Width" },
		{ ID::exp_lfo_dest_filter, "LFO Destination: Filter Cutoff" },
	};

}
