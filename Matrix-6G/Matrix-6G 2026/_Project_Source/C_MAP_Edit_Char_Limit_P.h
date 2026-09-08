#pragma once

#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, int> edit_char_limit{
		//exposed osc
		{ ID::exp_osc_1_pitch, 3 },
		{ ID::exp_osc_1_pulse_w, 2 },
		{ ID::exp_osc_1_saw_tri, 2 },
		{ ID::exp_osc_1_lfo_1_fm, 3 },
		{ ID::exp_osc_1_lfo_2_pwm, 3 },
		{ ID::exp_osc_2_pitch, 3 },
		{ ID::exp_osc_2_pulse_w, 2 },
		{ ID::exp_osc_2_saw_tri, 2 },
		{ ID::exp_osc_2_detune, 3 },
		{ ID::exp_osc_2_lfo_1_fm, 3 },
		{ ID::exp_osc_2_lfo_2_pwm, 3 },
		{ ID::exp_osc_balance, 2 },
		//exposed vcf
		{ ID::exp_vcf_freq, 3 },
		{ ID::exp_vcf_reso, 2 },
		{ ID::exp_vcf_env_1_amt, 3 },
		{ ID::exp_vcf_press_amt, 3 },
		//exposed vca
		{ ID::exp_vca_1_volume, 2 },
		{ ID::exp_vca_1_velo_amt, 3 },
		{ ID::exp_vca_2_env_2_amt, 3 },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, 2 },
		{ ID::exp_vcf_fm_env_3_amt, 3 },
		{ ID::exp_vcf_fm_press_amt, 3 },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, 2 },
		{ ID::exp_porta_velo, 3 },
		//exposed lfo
		{ ID::exp_lfo_1_speed, 2 },
		{ ID::exp_lfo_1_amp, 2 },
		{ ID::exp_lfo_1_press_amt, 3 },
		{ ID::exp_lfo_1_ramp_1_amt, 3 },
		{ ID::exp_lfo_1_retrig_point, 2 },
		{ ID::exp_lfo_2_speed, 2 },
		{ ID::exp_lfo_2_amp, 2 },
		{ ID::exp_lfo_2_key_track_amt, 3 },
		{ ID::exp_lfo_2_ramp_2_amt, 3 },
		{ ID::exp_lfo_2_retrig_point, 2 },
		//exposed ramp
		{ ID::exp_ramp_1_rate, 2 },
		{ ID::exp_ramp_2_rate, 2 },
		//exposed tracking
		{ ID::exp_track_point_1, 2 },
		{ ID::exp_track_point_2, 2 },
		{ ID::exp_track_point_3, 2 },
		{ ID::exp_track_point_4, 2 },
		{ ID::exp_track_point_5, 2 },
		//exposed env
		{ ID::exp_env_1_amp, 2 },
		{ ID::exp_env_1_velo_amt, 3 },
		{ ID::exp_env_1_delay, 2 },
		{ ID::exp_env_1_attack, 2 },
		{ ID::exp_env_1_decay, 2 },
		{ ID::exp_env_1_sustain, 2 },
		{ ID::exp_env_1_release, 2 },
		{ ID::exp_env_2_amp, 2 },
		{ ID::exp_env_2_velo_amt, 3 },
		{ ID::exp_env_2_delay, 2 },
		{ ID::exp_env_2_attack, 2 },
		{ ID::exp_env_2_decay, 2 },
		{ ID::exp_env_2_sustain, 2 },
		{ ID::exp_env_2_release, 2 },
		{ ID::exp_env_3_amp, 2 },
		{ ID::exp_env_3_velo_amt, 3 },
		{ ID::exp_env_3_delay, 2 },
		{ ID::exp_env_3_attack, 2 },
		{ ID::exp_env_3_decay, 2 },
		{ ID::exp_env_3_sustain, 2 },
		{ ID::exp_env_3_release, 2 },

		{ ID::mmod_0_amt, 3 },
		{ ID::mmod_1_amt, 3 },
		{ ID::mmod_2_amt, 3 },
		{ ID::mmod_3_amt, 3 },
		{ ID::mmod_4_amt, 3 },
		{ ID::mmod_5_amt, 3 },
		{ ID::mmod_6_amt, 3 },
		{ ID::mmod_7_amt, 3 },
		{ ID::mmod_8_amt, 3 },
		{ ID::mmod_9_amt, 3 },
	};

}