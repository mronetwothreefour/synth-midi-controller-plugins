#pragma once

#include <JuceHeader.h>

#include "C_ID_B.h"

namespace ID
{

	static const Identifier avp_00_voice_mode{ "avp_00_voice_mode" };
	static const Identifier avp_01_keyboard_octave{ "avp_01_keyboard_octave" };
	static const Identifier avp_02_slider_target{ "avp_02_slider_target" };
	static const Identifier avp_03_slider_range{ "avp_03_slider_range" };
	static const Identifier avp_04_slider_range_pitch_bend_pos{ "avp_04_slider_range_pitch_bend_pos" };
	static const Identifier avp_05_slider_range_pitch_bend_neg{ "avp_05_slider_range_pitch_bend_neg" };
	static const Identifier avp_06_lfo_sync_bpm_on{ "avp_06_lfo_sync_bpm_on" };
	static const Identifier avp_07_lfo_sync_key_on{ "avp_07_lfo_sync_key_on" };
	static const Identifier avp_08_lfo_sync_voice_on{ "avp_08_lfo_sync_voice_on" };
	static const Identifier avp_09_porta_time{ "avp_09_porta_time" };
	static const Identifier avp_10_porta_mode_on{ "avp_10_porta_mode_on" };
	static const Identifier avp_11_porta_sync_bpm_on{ "avp_11_porta_sync_bpm_on" };
	static const Identifier avp_12_amp_mod_by_velo_amt{ "avp_12_amp_mod_by_velo_amt" };
	static const Identifier avp_13_pgm_level{ "avp_13_pgm_level" };
	static const Identifier avp_14_microtune_scale{ "avp_14_microtune_scale" };
	static const Identifier avp_15_scale_key{ "avp_15_scale_key" };
	static const Identifier avp_16_pgm_fine_tune{ "avp_16_pgm_fine_tune" };
	static const Identifier avp_17_pgm_transpose{ "avp_17_pgm_transpose" };
	static const Identifier avp_current_voice_name{ "avp_current_voice_name" };

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

	static const Identifier subtree_bit_locations{ "subtree_bit_locations" };

	static const Identifier tree_additional_voice{ "tree_additional_voice" };

	static const Identifier xml_state_additional_voice{ "xml_state_additional_voice" };
}