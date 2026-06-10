#pragma once

#include <JuceHeader.h>

#include "C_ID_B.h"

namespace ID
{

	static const Identifier exp_00_osc_a_pitch           { "exp_00_osc_a_pitch" };
	static const Identifier exp_01_osc_a_sync            { "exp_01_osc_a_sync" };
	static const Identifier exp_02_osc_a_saw             { "exp_02_osc_a_saw" };
	static const Identifier exp_03_osc_a_tri             { "exp_03_osc_a_tri" };
	static const Identifier exp_04_osc_a_pulse           { "exp_04_osc_a_pulse" };
	static const Identifier exp_05_osc_a_pulse_w         { "exp_05_osc_a_pulse_w" };
	static const Identifier exp_06_osc_b_pitch           { "exp_06_osc_b_pitch" };
	static const Identifier exp_07_osc_b_fine            { "exp_07_osc_b_fine" };
	static const Identifier exp_08_osc_b_saw             { "exp_08_osc_b_saw" };
	static const Identifier exp_09_osc_b_tri             { "exp_09_osc_b_tri" };
	static const Identifier exp_10_osc_b_pulse           { "exp_10_osc_b_pulse" };
	static const Identifier exp_11_osc_b_pulse_w         { "exp_11_osc_b_pulse_w" };
	static const Identifier exp_12_mixer                 { "exp_12_mixer" };
	static const Identifier exp_13_glide                 { "exp_13_glide" };
	static const Identifier exp_14_filter_cutoff         { "exp_14_filter_cutoff" };
	static const Identifier exp_15_filter_reso           { "exp_15_filter_reso" };
	static const Identifier exp_16_filter_env_amt        { "exp_16_filter_env_amt" };
	static const Identifier exp_17_filter_key_track      { "exp_17_filter_key_track" };
	static const Identifier exp_18_filter_env_attack     { "exp_18_filter_env_attack" };
	static const Identifier exp_19_filter_env_decay      { "exp_19_filter_env_decay" };
	static const Identifier exp_20_filter_env_sustain    { "exp_20_filter_env_sustain" };
	static const Identifier exp_21_filter_env_release    { "exp_21_filter_env_release" };
	static const Identifier exp_22_amp_env_attack        { "exp_22_amp_env_attack" };
	static const Identifier exp_23_amp_env_decay         { "exp_23_amp_env_decay" };
	static const Identifier exp_24_amp_env_sustain       { "exp_24_amp_env_sustain" };
	static const Identifier exp_25_amp_env_release       { "exp_25_amp_env_release" };
	static const Identifier exp_26_p_mod_amt_filter_env  { "exp_26_p_mod_amt_filter_env" };
	static const Identifier exp_27_p_mod_amt_osc_b       { "exp_27_p_mod_amt_osc_b" };
	static const Identifier exp_28_p_mod_dest_osc_a_freq { "exp_28_p_mod_dest_osc_a_freq" };
	static const Identifier exp_29_p_mod_dest_filter     { "exp_29_p_mod_dest_filter" };
	static const Identifier exp_30_unison_track          { "exp_30_unison_track" };
	static const Identifier exp_31_lfo_freq              { "exp_31_lfo_freq" };
	static const Identifier exp_32_lfo_shape             { "exp_32_lfo_shape" };
	static const Identifier exp_33_lfo_init_amt          { "exp_33_lfo_init_amt" };
	static const Identifier exp_34_lfo_dest_osc_pitch    { "exp_34_lfo_dest_osc_pitch" };
	static const Identifier exp_35_lfo_dest_osc_pw       { "exp_35_lfo_dest_osc_pw" };
	static const Identifier exp_36_lfo_dest_filter       { "exp_36_lfo_dest_filter" };

	// exposed parameter properties
	static const Identifier exp_p_bit_count{ "exp_p_bit_count" };
	static const Identifier exp_p_first_bit_index{ "exp_p_first_bit_index" };
	static const Identifier exp_p_first_nybble_index{ "exp_p_first_nybble_index" };

	static const Identifier label_led{ "label_led" };
}