#pragma once

#include "C_ID_Exp_P.h"
#include "D_BUILD_Choices_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, StringArray> choices{
		//exposed osc
		{ ID::exp_osc_1_pitch, Choices_For::osc_pitch(64) },
		{ ID::exp_osc_1_type, Choices_For::exp_osc_type(1) },
		{ ID::exp_osc_1_pulse_w, Choices_For::unsigned_int(63) },
		{ ID::exp_osc_1_saw_tri, Choices_For::unsigned_int(63) },
		{ ID::exp_osc_1_sync, Choices_For::exp_osc_1_sync() },
		{ ID::exp_osc_1_lfo_1_fm, Choices_For::signed_int(-63, 63) },
		{ ID::exp_osc_1_lfo_2_pwm, Choices_For::signed_int(-63, 63) },
		{ ID::exp_osc_1_key_click, Choices_For::off_on() },
		{ ID::exp_osc_1_key_track, Choices_For::exp_osc_1_key_track() },
		{ ID::exp_osc_1_lever_ctrl, Choices_For::exp_osc_lever_control() },
		{ ID::exp_osc_2_pitch, Choices_For::osc_pitch(64) },
		{ ID::exp_osc_2_type, Choices_For::exp_osc_type(2) },
		{ ID::exp_osc_2_pulse_w, Choices_For::unsigned_int(63) },
		{ ID::exp_osc_2_saw_tri, Choices_For::unsigned_int(63) },
		{ ID::exp_osc_2_detune, Choices_For::signed_int(-31, 31) },
		{ ID::exp_osc_2_lfo_1_fm, Choices_For::signed_int(-63, 63) },
		{ ID::exp_osc_2_lfo_2_pwm, Choices_For::signed_int(-63, 63) },
		{ ID::exp_osc_2_key_click, Choices_For::off_on() },
		{ ID::exp_osc_2_key_track, Choices_For::exp_osc_2_and_vcf_key_track() },
		{ ID::exp_osc_2_lever_ctrl, Choices_For::exp_osc_lever_control() },
		{ ID::exp_osc_balance, Choices_For::unsigned_int(63) },
		//exposed vcf
		{ ID::exp_vcf_freq, Choices_For::unsigned_int(127) },
		{ ID::exp_vcf_reso, Choices_For::unsigned_int(63) },
		{ ID::exp_vcf_env_1_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_vcf_press_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_vcf_lever_ctrl, Choices_For::exp_lever_ctrl() },
		{ ID::exp_vcf_key_track, Choices_For::exp_osc_2_and_vcf_key_track() },
		//exposed vca
		{ ID::exp_vca_1_volume, Choices_For::unsigned_int(63) },
		{ ID::exp_vca_1_velo_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_vca_2_env_2_amt, Choices_For::signed_int(-63, 63) },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, Choices_For::unsigned_int(63) },
		{ ID::exp_vcf_fm_env_3_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_vcf_fm_press_amt, Choices_For::signed_int(-63, 63) },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, Choices_For::unsigned_int(63) },
		{ ID::exp_porta_velo, Choices_For::signed_int(-63, 63) },
		{ ID::exp_porta_mode, Choices_For::exp_porta_mode() },
		{ ID::exp_porta_legato, Choices_For::exp_off_on_matrix() },
		{ ID::exp_keyboard_mode, Choices_For::exp_keyboard_mode() },
		//exposed lfo
		{ ID::exp_lfo_1_speed, Choices_For::unsigned_int(63) },	
		{ ID::exp_lfo_1_wave_type, Choices_For::exp_lfo_wave_type() },
		{ ID::exp_lfo_1_samp_source, Choices_For::exp_input_source(true) },
		{ ID::exp_lfo_1_amp, Choices_For::unsigned_int(63) },
		{ ID::exp_lfo_1_press_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_lfo_1_ramp_1_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_lfo_1_trig_mode, Choices_For::exp_lfo_trig_mode() },
		{ ID::exp_lfo_1_retrig_point, Choices_For::unsigned_int(63) },
		{ ID::exp_lfo_1_lag, Choices_For::exp_off_on_matrix() },
		{ ID::exp_lfo_2_speed, Choices_For::unsigned_int(63) },
		{ ID::exp_lfo_2_wave_type, Choices_For::exp_lfo_wave_type() },
		{ ID::exp_lfo_2_samp_source, Choices_For::exp_input_source(true) },
		{ ID::exp_lfo_2_amp, Choices_For::unsigned_int(63) },
		{ ID::exp_lfo_2_key_track_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_lfo_2_ramp_2_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_lfo_2_trig_mode,  Choices_For::exp_lfo_trig_mode() },
		{ ID::exp_lfo_2_retrig_point, Choices_For::unsigned_int(63) },
		{ ID::exp_lfo_2_lag, Choices_For::exp_off_on_matrix() },
		//exposed ramp
		{ ID::exp_ramp_1_rate, Choices_For::unsigned_int(63) },
		{ ID::exp_ramp_1_trig, Choices_For::exp_ramp_trig() },
		{ ID::exp_ramp_2_rate, Choices_For::unsigned_int(63) },
		{ ID::exp_ramp_2_trig, Choices_For::exp_ramp_trig() },
		//exposed tracking
		{ ID::exp_track_input, Choices_For::exp_input_source(false) },
		{ ID::exp_track_point_1, Choices_For::unsigned_int(63) },
		{ ID::exp_track_point_2, Choices_For::unsigned_int(63) },
		{ ID::exp_track_point_3, Choices_For::unsigned_int(63) },
		{ ID::exp_track_point_4, Choices_For::unsigned_int(63) },
		{ ID::exp_track_point_5, Choices_For::unsigned_int(63) },
		//exposed env
		{ ID::exp_env_1_amp, Choices_For::unsigned_int(63) },
		{ ID::exp_env_1_velo_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_env_1_trig_mode, Choices_For::exp_env_trig_mode() },
		{ ID::exp_env_1_mode, Choices_For::exp_env_mode() },
		{ ID::exp_env_1_lfo_1_trig, Choices_For::exp_env_lfo_1_trig() },
		{ ID::exp_env_1_delay, Choices_For::unsigned_int(63) },
		{ ID::exp_env_1_attack, Choices_For::unsigned_int(63) },
		{ ID::exp_env_1_decay, Choices_For::unsigned_int(63) },
		{ ID::exp_env_1_sustain, Choices_For::unsigned_int(63) },
		{ ID::exp_env_1_release, Choices_For::unsigned_int(63) },
		{ ID::exp_env_2_amp, Choices_For::unsigned_int(63) },
		{ ID::exp_env_2_velo_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_env_2_trig_mode, Choices_For::exp_env_trig_mode() },
		{ ID::exp_env_2_mode, Choices_For::exp_env_mode() },
		{ ID::exp_env_2_lfo_1_trig, Choices_For::exp_env_lfo_1_trig() },
		{ ID::exp_env_2_delay, Choices_For::unsigned_int(63) },
		{ ID::exp_env_2_attack, Choices_For::unsigned_int(63) },
		{ ID::exp_env_2_decay, Choices_For::unsigned_int(63) },
		{ ID::exp_env_2_sustain, Choices_For::unsigned_int(63) },
		{ ID::exp_env_2_release, Choices_For::unsigned_int(63) },
		{ ID::exp_env_3_amp, Choices_For::unsigned_int(63) },
		{ ID::exp_env_3_velo_amt, Choices_For::signed_int(-63, 63) },
		{ ID::exp_env_3_trig_mode, Choices_For::exp_env_trig_mode() },
		{ ID::exp_env_3_mode, Choices_For::exp_env_mode() },
		{ ID::exp_env_3_lfo_1_trig, Choices_For::exp_env_lfo_1_trig() },
		{ ID::exp_env_3_delay, Choices_For::unsigned_int(63) },
		{ ID::exp_env_3_attack, Choices_For::unsigned_int(63) },
		{ ID::exp_env_3_decay, Choices_For::unsigned_int(63) },
		{ ID::exp_env_3_sustain, Choices_For::unsigned_int(63) },
		{ ID::exp_env_3_release, Choices_For::unsigned_int(63) },
	};

}
