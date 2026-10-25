#pragma once

#include <string>
#include <unordered_map>

#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<std::string, std::tuple<int, bool, bool>> quick_edit_traits{
		//exposed osc
		{ ID::exp_osc_1_pitch, { 0, false, false } },
		{ ID::exp_osc_1_type, { 6, false, false } },
		{ ID::exp_osc_1_pulse_w, { 3, false, false } },
		{ ID::exp_osc_1_saw_tri, { 5, false, false } },
		{ ID::exp_osc_1_sync, { 2, false, false } },
		{ ID::exp_osc_1_lfo_1_fm, { 1, false, true } },
		{ ID::exp_osc_1_lfo_2_pwm, { 4, false, true } },
		{ ID::exp_osc_1_key_click, { 9, false, false } },
		{ ID::exp_osc_1_key_track, { 8, false, false } },
		{ ID::exp_osc_1_lever_ctrl, { 7, false, false } },
		{ ID::exp_osc_2_pitch, { 10, false, false } },
		{ ID::exp_osc_2_type, { 16, false, false } },
		{ ID::exp_osc_2_pulse_w, { 13, false, false } },
		{ ID::exp_osc_2_saw_tri, { 15, false, false } },
		{ ID::exp_osc_2_detune, { 12, true, false } },
		{ ID::exp_osc_2_lfo_1_fm, { 11, false, true } },
		{ ID::exp_osc_2_lfo_2_pwm, { 14, false, true } },
		{ ID::exp_osc_2_key_click, { 19, false, false } },
		{ ID::exp_osc_2_key_track, { 18, false, false } },
		{ ID::exp_osc_2_lever_ctrl, { 17, false, false } },
		{ ID::exp_osc_balance, { 20, false, false } },
		//exposed vcf
		{ ID::exp_vcf_freq, { 21, false, false } },
		{ ID::exp_vcf_reso, { 24, false, false } },
		{ ID::exp_vcf_env_1_amt, { 22, false, true } },
		{ ID::exp_vcf_press_amt, { 23, false, true } },
		{ ID::exp_vcf_lever_ctrl, { 25, false, false } },
		{ ID::exp_vcf_key_track, { 26, false, false } },
		//exposed vca
		{ ID::exp_vca_1_volume, { 27, false, false } },
		{ ID::exp_vca_1_velo_amt, { 28, false, true } },
		{ ID::exp_vca_2_env_2_amt, { 29, false, true } },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, { 30, false, false } },
		{ ID::exp_vcf_fm_env_3_amt, { 31, false, true } },
		{ ID::exp_vcf_fm_press_amt, { 32, false, true } },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, { 44, false, false } },
		{ ID::exp_porta_velo, { 45, false, true } },
		{ ID::exp_porta_mode, { 46, false, false } },
		{ ID::exp_porta_legato, { 47, false, false } },
		{ ID::exp_keyboard_mode, { 48, false, false } },
		//exposed lfo
		{ ID::exp_lfo_1_speed, { 80, false, false } },
		{ ID::exp_lfo_1_wave_type, { 82, false, false } },
		{ ID::exp_lfo_1_samp_source, { 88, false, false } },
		{ ID::exp_lfo_1_amp, { 84, false, false } },
		{ ID::exp_lfo_1_press_amt, { 81, false, true } },
		{ ID::exp_lfo_1_ramp_1_amt, { 85, false, true } },
		{ ID::exp_lfo_1_trig_mode, { 86, false, true } },
		{ ID::exp_lfo_1_retrig_point, { 83, false, true } },
		{ ID::exp_lfo_1_lag, { 87, false, true } },
		{ ID::exp_lfo_2_speed, { 90, false, false } },
		{ ID::exp_lfo_2_wave_type, { 92, false, false } },
		{ ID::exp_lfo_2_samp_source, { 98, false, false } },
		{ ID::exp_lfo_2_amp, { 94, false, false } },
		{ ID::exp_lfo_2_key_track_amt, { 91, false, true } },
		{ ID::exp_lfo_2_ramp_2_amt, { 95, false, true } },
		{ ID::exp_lfo_2_trig_mode, { 96, false, false } },
		{ ID::exp_lfo_2_retrig_point, { 93, false, false } },
		{ ID::exp_lfo_2_lag, { 97, false, false } },
		//exposed ramp
		{ ID::exp_ramp_1_rate, { 40, false, false } },
		{ ID::exp_ramp_1_trig, { 41, false, false } },
		{ ID::exp_ramp_2_rate, { 42, false, false } },
		{ ID::exp_ramp_2_trig, { 43, false, false } },
		//exposed tracking
		{ ID::exp_track_input, { 33, false, false } },
		{ ID::exp_track_point_1, { 34, false, false } },
		{ ID::exp_track_point_2, { 35, false, false } },
		{ ID::exp_track_point_3, { 36, false, false } },
		{ ID::exp_track_point_4, { 37, false, false } },
		{ ID::exp_track_point_5, { 38, false, false } },
		//exposed env
		{ ID::exp_env_1_amp, { 55, false, false } },
		{ ID::exp_env_1_velo_amt, { 56, false, true } },
		{ ID::exp_env_1_trig_mode, { 57, false, false } },
		{ ID::exp_env_1_mode, { 58, false, false } },
		{ ID::exp_env_1_lfo_1_trig, { 59, false, false } },
		{ ID::exp_env_1_delay, { 50, false, false } },
		{ ID::exp_env_1_attack, { 51, false, false } },
		{ ID::exp_env_1_decay, { 52, false, false } },
		{ ID::exp_env_1_sustain, { 53, false, false } },
		{ ID::exp_env_1_release, { 54, false, false } },
		{ ID::exp_env_2_amp, { 65, false, false } },
		{ ID::exp_env_2_velo_amt, { 66, false, true } },
		{ ID::exp_env_2_trig_mode, { 67, false, false } },
		{ ID::exp_env_2_mode, { 68, false, false } },
		{ ID::exp_env_2_lfo_1_trig, { 69, false, false } },
		{ ID::exp_env_2_delay, { 60, false, false } },
		{ ID::exp_env_2_attack, { 61, false, false } },
		{ ID::exp_env_2_decay, { 62, false, false } },
		{ ID::exp_env_2_sustain, { 63, false, false } },
		{ ID::exp_env_2_release, { 64, false, false } },
		{ ID::exp_env_3_amp, { 75, false, false } },
		{ ID::exp_env_3_velo_amt, { 76, false, true } },
		{ ID::exp_env_3_trig_mode, { 77, false, false } },
		{ ID::exp_env_3_mode, { 78, false, false } },
		{ ID::exp_env_3_lfo_1_trig, { 79, false, false } },
		{ ID::exp_env_3_delay, { 70, false, false } },
		{ ID::exp_env_3_attack, { 71, false, false } },
		{ ID::exp_env_3_decay, { 72, false, false } },
		{ ID::exp_env_3_sustain, { 73, false, false } },
		{ ID::exp_env_3_release, { 74, false, false } },
	};

}
