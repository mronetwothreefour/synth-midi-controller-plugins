#pragma once

#include "C_MISC_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> edit_allowed_chars{
		//exposed osc
		{ ID::exp_osc_1_pitch, MISC::allowed_chars_pitch },
		{ ID::exp_osc_1_pulse_w, MISC::allowed_chars_u_int },
		{ ID::exp_osc_1_saw_tri, MISC::allowed_chars_u_int },
		{ ID::exp_osc_1_lfo_1_fm, MISC::allowed_chars_s_int },
		{ ID::exp_osc_1_lfo_2_pwm, MISC::allowed_chars_s_int },
		{ ID::exp_osc_2_pitch, MISC::allowed_chars_pitch },
		{ ID::exp_osc_2_pulse_w, MISC::allowed_chars_u_int },
		{ ID::exp_osc_2_saw_tri, MISC::allowed_chars_u_int },
		{ ID::exp_osc_2_detune, MISC::allowed_chars_s_int },
		{ ID::exp_osc_2_lfo_1_fm, MISC::allowed_chars_s_int },
		{ ID::exp_osc_2_lfo_2_pwm, MISC::allowed_chars_s_int },
		{ ID::exp_osc_balance, MISC::allowed_chars_u_int },
		//exposed vcf
		{ ID::exp_vcf_freq, MISC::allowed_chars_u_int },
		{ ID::exp_vcf_reso, MISC::allowed_chars_u_int },
		{ ID::exp_vcf_env_1_amt, MISC::allowed_chars_s_int },
		{ ID::exp_vcf_press_amt, MISC::allowed_chars_s_int },
		//exposed vca
		{ ID::exp_vca_1_volume, MISC::allowed_chars_u_int },
		{ ID::exp_vca_1_velo_amt, MISC::allowed_chars_s_int },
		{ ID::exp_vca_2_env_2_amt, MISC::allowed_chars_s_int },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, MISC::allowed_chars_u_int },
		{ ID::exp_vcf_fm_env_3_amt, MISC::allowed_chars_s_int },
		{ ID::exp_vcf_fm_press_amt, MISC::allowed_chars_s_int },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, MISC::allowed_chars_u_int },
		{ ID::exp_porta_velo, MISC::allowed_chars_s_int },
		//exposed lfo
		{ ID::exp_lfo_1_speed, MISC::allowed_chars_u_int },
		{ ID::exp_lfo_1_amp, MISC::allowed_chars_u_int },
		{ ID::exp_lfo_1_press_amt, MISC::allowed_chars_s_int },
		{ ID::exp_lfo_1_ramp_1_amt, MISC::allowed_chars_s_int },
		{ ID::exp_lfo_1_retrig_point, MISC::allowed_chars_u_int },
		{ ID::exp_lfo_2_speed, MISC::allowed_chars_u_int },
		{ ID::exp_lfo_2_amp, MISC::allowed_chars_u_int },
		{ ID::exp_lfo_2_key_track_amt, MISC::allowed_chars_s_int },
		{ ID::exp_lfo_2_ramp_2_amt, MISC::allowed_chars_s_int },
		{ ID::exp_lfo_2_retrig_point, MISC::allowed_chars_u_int },
		//exposed ramp
		{ ID::exp_ramp_1_rate, MISC::allowed_chars_u_int },
		{ ID::exp_ramp_2_rate, MISC::allowed_chars_u_int },
		//exposed tracking
		{ ID::exp_track_point_1, MISC::allowed_chars_u_int },
		{ ID::exp_track_point_2, MISC::allowed_chars_u_int },
		{ ID::exp_track_point_3, MISC::allowed_chars_u_int },
		{ ID::exp_track_point_4, MISC::allowed_chars_u_int },
		{ ID::exp_track_point_5, MISC::allowed_chars_u_int },
		//exposed env
		{ ID::exp_env_1_amp, MISC::allowed_chars_u_int },
		{ ID::exp_env_1_velo_amt, MISC::allowed_chars_s_int },
		{ ID::exp_env_1_delay, MISC::allowed_chars_u_int },
		{ ID::exp_env_1_attack, MISC::allowed_chars_u_int },
		{ ID::exp_env_1_decay, MISC::allowed_chars_u_int },
		{ ID::exp_env_1_sustain, MISC::allowed_chars_u_int },
		{ ID::exp_env_1_release, MISC::allowed_chars_u_int },
		{ ID::exp_env_2_amp, MISC::allowed_chars_u_int },
		{ ID::exp_env_2_velo_amt, MISC::allowed_chars_s_int },
		{ ID::exp_env_2_delay, MISC::allowed_chars_u_int },
		{ ID::exp_env_2_attack, MISC::allowed_chars_u_int },
		{ ID::exp_env_2_decay, MISC::allowed_chars_u_int },
		{ ID::exp_env_2_sustain, MISC::allowed_chars_u_int },
		{ ID::exp_env_2_release, MISC::allowed_chars_u_int },
		{ ID::exp_env_3_amp, MISC::allowed_chars_u_int },
		{ ID::exp_env_3_velo_amt, MISC::allowed_chars_s_int },
		{ ID::exp_env_3_delay, MISC::allowed_chars_u_int },
		{ ID::exp_env_3_attack, MISC::allowed_chars_u_int },
		{ ID::exp_env_3_decay, MISC::allowed_chars_u_int },
		{ ID::exp_env_3_sustain, MISC::allowed_chars_u_int },
		{ ID::exp_env_3_release, MISC::allowed_chars_u_int },

		{ ID::mmod_0_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_1_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_2_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_3_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_4_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_5_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_6_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_7_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_8_amt, MISC::allowed_chars_s_int },
		{ ID::mmod_9_amt, MISC::allowed_chars_s_int },
	};

}