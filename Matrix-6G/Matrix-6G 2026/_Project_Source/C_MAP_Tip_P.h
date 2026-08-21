#pragma once

#include "C_ID_Exp_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;

namespace MAP
{

	static const std::unordered_map<String, String> tip{
		//exposed osc
		{ ID::exp_osc_1_pitch, Tip_For::exp_osc_pitch(1) },
		{ ID::exp_osc_1_type, Tip_For::exp_osc_type(1) },
		{ ID::exp_osc_1_pulse_w, Tip_For::exp_osc_pulse_w(1) },
		{ ID::exp_osc_1_saw_tri, Tip_For::exp_osc_saw_tri(1) },
		{ ID::exp_osc_1_sync, Tip_For::from_string_literal(SL::osc_1_sync_tip) },
		{ ID::exp_osc_1_lfo_1_fm, Tip_For::exp_osc_lfo_1_fm(1) },
		{ ID::exp_osc_1_lfo_2_pwm, Tip_For::exp_osc_lfo_2_pwm(1) },
		{ ID::exp_osc_1_key_click, Tip_For::from_string_literal(SL::osc_key_click_tip) },
		{ ID::exp_osc_1_key_track, Tip_For::exp_osc_key_track(1) },
		{ ID::exp_osc_1_lever_ctrl, Tip_For::exp_osc_lever_control(1) },
		{ ID::exp_osc_2_pitch, Tip_For::exp_osc_pitch(2) },
		{ ID::exp_osc_2_type, Tip_For::exp_osc_type(2) },
		{ ID::exp_osc_2_pulse_w, Tip_For::exp_osc_pulse_w(2) },
		{ ID::exp_osc_2_saw_tri, Tip_For::exp_osc_saw_tri(2) },
		{ ID::exp_osc_2_detune, Tip_For::from_string_literal(SL::osc_2_detune_tip) },
		{ ID::exp_osc_2_lfo_1_fm, Tip_For::exp_osc_lfo_1_fm(1) },
		{ ID::exp_osc_2_lfo_2_pwm, Tip_For::exp_osc_lfo_2_pwm(1) },
		{ ID::exp_osc_2_key_click, Tip_For::from_string_literal(SL::osc_key_click_tip) },
		{ ID::exp_osc_2_key_track, Tip_For::exp_osc_key_track(1) },
		{ ID::exp_osc_2_lever_ctrl, Tip_For::exp_osc_lever_control(2) },
		{ ID::exp_osc_balance, Tip_For::from_string_literal(SL::osc_balance_tip) },
		//exposed vcf
		{ ID::exp_vcf_freq, Tip_For::from_string_literal(SL::vcf_freq_tip) },
		{ ID::exp_vcf_reso, Tip_For::from_string_literal(SL::vcf_reso_tip) },
		{ ID::exp_vcf_env_1_amt, Tip_For::from_string_literal(SL::vcf_env_1_amt_tip) },
		{ ID::exp_vcf_press_amt, Tip_For::from_string_literal(SL::vcf_lever_ctrl_tip) },
		{ ID::exp_vcf_lever_ctrl, Tip_For::from_string_literal(SL::vcf_pressure_amt_tip) },
		{ ID::exp_vcf_key_track, Tip_For::from_string_literal(SL::vcf_key_track_tip) },
		//exposed vca
		{ ID::exp_vca_1_volume, Tip_For::from_string_literal(SL::vca_1_volume_tip) },
		{ ID::exp_vca_1_velo_amt, Tip_For::from_string_literal(SL::vca_1_velo_amt_tip) },
		{ ID::exp_vca_2_env_2_amt, Tip_For::from_string_literal(SL::vca_2_env_2_amt_tip) },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, Tip_For::from_string_literal(SL::vcf_fm_osc_1_amt_tip) },
		{ ID::exp_vcf_fm_env_3_amt, Tip_For::from_string_literal(SL::vcf_fm_env_3_amt_tip) },
		{ ID::exp_vcf_fm_press_amt, Tip_For::from_string_literal(SL::vcf_fm_pressure_amt_tip) },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, Tip_For::from_string_literal(SL::porta_rate_tip) },
		{ ID::exp_porta_velo, Tip_For::from_string_literal(SL::porta_velo_tip) },
		{ ID::exp_porta_mode, Tip_For::from_string_literal(SL::porta_mode_tip) },
		{ ID::exp_porta_legato, Tip_For::from_string_literal(SL::porta_legato_tip) },
		{ ID::exp_keyboard_mode, Tip_For::from_string_literal(SL::keyboard_mode_tip) },
		//exposed lfo
		{ ID::exp_lfo_1_speed, Tip_For::exp_lfo_speed(1) },
		{ ID::exp_lfo_1_wave_type, Tip_For::exp_lfo_wave_type(1) },
		{ ID::exp_lfo_1_samp_source, Tip_For::exp_lfo_sample_source(1) },
		{ ID::exp_lfo_1_amp, Tip_For::exp_lfo_amp(1) },
		{ ID::exp_lfo_1_press_amt, Tip_For::from_string_literal(SL::lfo_1_pressure_amt_tip) },
		{ ID::exp_lfo_1_ramp_1_amt, Tip_For::exp_lfo_ramp_amt(1) },
		{ ID::exp_lfo_1_trig_mode, Tip_For::exp_lfo_trig_mode(1) },
		{ ID::exp_lfo_1_retrig_point, Tip_For::exp_lfo_retrig_point(1) },
		{ ID::exp_lfo_1_lag, Tip_For::exp_lfo_lag(1) },
		{ ID::exp_lfo_2_speed, Tip_For::exp_lfo_speed(2) },
		{ ID::exp_lfo_2_wave_type, Tip_For::exp_lfo_wave_type(2) },
		{ ID::exp_lfo_2_samp_source, Tip_For::exp_lfo_sample_source(2) },
		{ ID::exp_lfo_2_amp, Tip_For::exp_lfo_amp(2) },
		{ ID::exp_lfo_2_key_track_amt, Tip_For::from_string_literal(SL::lfo_2_key_track_amt_tip) },
		{ ID::exp_lfo_1_ramp_1_amt, Tip_For::exp_lfo_ramp_amt(2) },
		{ ID::exp_lfo_1_trig_mode, Tip_For::exp_lfo_trig_mode(2) },
		{ ID::exp_lfo_1_retrig_point, Tip_For::exp_lfo_retrig_point(2) },
		{ ID::exp_lfo_1_lag, Tip_For::exp_lfo_lag(2) },
		//exposed ramp
		{ ID::exp_ramp_1_rate, Tip_For::exp_ramp_rate(1) },
		{ ID::exp_ramp_1_trig, Tip_For::exp_ramp_trig(1) },
		{ ID::exp_ramp_2_rate, Tip_For::exp_ramp_rate(2) },
		{ ID::exp_ramp_2_trig, Tip_For::exp_ramp_trig(2) },
		//exposed tracking
		{ ID::exp_track_input, Tip_For::from_string_literal(SL::track_input_tip) },
		{ ID::exp_track_point_1, Tip_For::exp_track_point(1, 0) },
		{ ID::exp_track_point_2, Tip_For::exp_track_point(2, 15) },
		{ ID::exp_track_point_3, Tip_For::exp_track_point(3, 31) },
		{ ID::exp_track_point_4, Tip_For::exp_track_point(4, 47) },
		{ ID::exp_track_point_5, Tip_For::exp_track_point(5, 63) },
		//exposed env
		{ ID::exp_env_1_amp, Tip_For::exp_env_amp(1) },
		{ ID::exp_env_1_velo_amt, Tip_For::exp_env_velo_amt(1) },
		{ ID::exp_env_1_trig_mode, Tip_For::exp_env_trig_mode(1) },
		{ ID::exp_env_1_mode, Tip_For::exp_env_mode(1) },
		{ ID::exp_env_1_lfo_1_trig, Tip_For::exp_env_lfo_1_trig(1) },
		{ ID::exp_env_1_delay, Tip_For::exp_env_delay(1) },
		{ ID::exp_env_1_attack, Tip_For::exp_env_attack(1) },
		{ ID::exp_env_1_decay, Tip_For::exp_env_decay(1) },
		{ ID::exp_env_1_sustain, Tip_For::exp_env_sustain(1) },
		{ ID::exp_env_1_release, Tip_For::exp_env_release(1) },
		{ ID::exp_env_2_amp, Tip_For::exp_env_amp(2) },
		{ ID::exp_env_2_velo_amt, Tip_For::exp_env_velo_amt(2) },
		{ ID::exp_env_2_trig_mode, Tip_For::exp_env_trig_mode(2) },
		{ ID::exp_env_2_mode, Tip_For::exp_env_mode(2) },
		{ ID::exp_env_2_lfo_1_trig, Tip_For::exp_env_lfo_1_trig(2) },
		{ ID::exp_env_2_delay, Tip_For::exp_env_delay(2) },
		{ ID::exp_env_2_attack, Tip_For::exp_env_attack(2) },
		{ ID::exp_env_2_decay, Tip_For::exp_env_decay(2) },
		{ ID::exp_env_2_sustain, Tip_For::exp_env_sustain(2) },
		{ ID::exp_env_2_release, Tip_For::exp_env_release(2) },
		{ ID::exp_env_3_amp, Tip_For::exp_env_amp(3) },
		{ ID::exp_env_3_velo_amt, Tip_For::exp_env_velo_amt(3) },
		{ ID::exp_env_3_trig_mode, Tip_For::exp_env_trig_mode(3) },
		{ ID::exp_env_3_mode, Tip_For::exp_env_mode(3) },
		{ ID::exp_env_3_lfo_1_trig, Tip_For::exp_env_lfo_1_trig(3) },
		{ ID::exp_env_3_delay, Tip_For::exp_env_delay(3) },
		{ ID::exp_env_3_attack, Tip_For::exp_env_attack(3) },
		{ ID::exp_env_3_decay, Tip_For::exp_env_decay(3) },
		{ ID::exp_env_3_sustain, Tip_For::exp_env_sustain(3) },
		{ ID::exp_env_3_release, Tip_For::exp_env_release(3) },
	};

}
