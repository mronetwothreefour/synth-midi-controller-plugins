#pragma once

#include <JuceHeader.h>

#include "C_ID_B.h"

namespace ID
{

	static const Identifier exp_00_osc_1_octave       { "exp_00_osc_1_octave" };
	static const Identifier exp_01_osc_1_wave         { "exp_01_osc_1_wave" };
	static const Identifier exp_02_osc_1_pitch_fine   { "exp_02_osc_1_pitch_fine" };
	static const Identifier exp_03_osc_1_shape        { "exp_03_osc_1_shape" };
	static const Identifier exp_04_osc_2_octave       { "exp_04_osc_2_octave" };
	static const Identifier exp_05_osc_2_wave         { "exp_05_osc_2_wave" };
	static const Identifier exp_06_osc_2_pitch_fine   { "exp_06_osc_2_pitch_fine" };
	static const Identifier exp_07_osc_2_shape        { "exp_07_osc_2_shape" };
	static const Identifier exp_08_osc_2_xmod_depth   { "exp_08_osc_2_xmod_depth" };
	static const Identifier exp_09_osc_2_pitch_eg_int { "exp_09_osc_2_pitch_eg_int" };
	static const Identifier exp_10_osc_2_sync         { "exp_10_osc_2_sync" };
	static const Identifier exp_11_osc_2_ring_mod     { "exp_11_osc_2_ring_mod" };
	static const Identifier exp_12_osc_1_level        { "exp_12_osc_1_level" };
	static const Identifier exp_13_osc_2_level        { "exp_13_osc_2_level" };
	static const Identifier exp_14_noise_level        { "exp_14_noise_level" };
	static const Identifier exp_15_lpf_freq           { "exp_15_lpf_freq" };
	static const Identifier exp_16_lpf_reso           { "exp_16_lpf_reso" };
	static const Identifier exp_17_lpf_eg_int         { "exp_17_lpf_eg_int" };
	static const Identifier exp_18_lpf_type           { "exp_18_lpf_type" };
	static const Identifier exp_19_lpf_key_track      { "exp_19_lpf_key_track" };
	static const Identifier exp_20_lpf_vel_amt        { "exp_20_lpf_vel_amt" };
	static const Identifier exp_21_vca_env_attack     { "exp_21_vca_env_attack" };
	static const Identifier exp_22_vca_env_decay      { "exp_22_vca_env_decay" };
	static const Identifier exp_23_vca_env_sustain    { "exp_23_vca_env_sustain" };
	static const Identifier exp_24_vca_env_release    { "exp_24_vca_env_release" };
	static const Identifier exp_25_env_attack         { "exp_25_env_attack" };
	static const Identifier exp_26_env_decay          { "exp_26_env_decay" };
	static const Identifier exp_27_env_sustain        { "exp_27_env_sustain" };
	static const Identifier exp_28_env_release        { "exp_28_env_release" };
	static const Identifier exp_29_LFO_Wave           { "exp_29_LFO_Wave" };
	static const Identifier exp_30_lfo_eg_mod         { "exp_30_lfo_eg_mod" };
	static const Identifier exp_31_lfo_rate           { "exp_31_lfo_rate" };
	static const Identifier exp_32_lfo_int            { "exp_32_lfo_int" };
	static const Identifier exp_33_lfo_target         { "exp_33_lfo_target" };
	static const Identifier exp_34_delay_hpf_freq     { "exp_34_delay_hpf_freq" };
	static const Identifier exp_35_delay_time         { "exp_35_delay_time" };
	static const Identifier exp_36_delay_feedback     { "exp_36_delay_feedback" };
	static const Identifier exp_37_delay_routing      { "exp_37_delay_routing" };
	static const Identifier exp_38_voice_mode_depth   { "exp_38_voice_mode_depth" };

	// exposed parameter properties
	static const Identifier exp_p_bit_count{ "exp_p_bit_count" };
	static const Identifier exp_p_cc_num{ "exp_p_cc_num" };

	static const Identifier tree_bit_locations{ "tree_bit_locations" };
}