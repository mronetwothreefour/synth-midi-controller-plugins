#pragma once

#include "C_ENUM_P.h"
#include "C_ID_Exp_P.h"

using namespace ENUM;

namespace MAP
{

	static const std::unordered_map<String, Ctrl> ctrl_type{
		//exposed osc
		{ ID::exp_osc_1_pitch, Ctrl::slider_osc_pitch },
		{ ID::exp_osc_1_type, Ctrl::cbox },
		{ ID::exp_osc_1_pulse_w, Ctrl::knob },
		{ ID::exp_osc_1_saw_tri, Ctrl::knob },
		{ ID::exp_osc_1_sync, Ctrl::cbox },
		{ ID::exp_osc_1_lfo_1_fm, Ctrl::knob },
		{ ID::exp_osc_1_lfo_2_pwm, Ctrl::knob },
		{ ID::exp_osc_1_key_click, Ctrl::cbox },
		{ ID::exp_osc_1_key_track, Ctrl::cbox },
		{ ID::exp_osc_1_lever_ctrl, Ctrl::cbox },
		{ ID::exp_osc_2_pitch, Ctrl::slider_osc_pitch },
		{ ID::exp_osc_2_type, Ctrl::cbox },
		{ ID::exp_osc_2_pulse_w, Ctrl::knob },
		{ ID::exp_osc_2_saw_tri, Ctrl::knob },
		{ ID::exp_osc_2_detune, Ctrl::knob },
		{ ID::exp_osc_2_lfo_1_fm, Ctrl::knob },
		{ ID::exp_osc_2_lfo_2_pwm, Ctrl::knob },
		{ ID::exp_osc_1_key_click, Ctrl::cbox },
		{ ID::exp_osc_1_key_track, Ctrl::cbox },
		{ ID::exp_osc_1_lever_ctrl, Ctrl::cbox },
		{ ID::exp_osc_balance, Ctrl::slider_osc_balance },
		//exposed vcf
		{ ID::exp_vcf_freq, Ctrl::knob },
		{ ID::exp_vcf_reso, Ctrl::knob },
		{ ID::exp_vcf_env_1_amt, Ctrl::knob },
		{ ID::exp_vcf_press_amt, Ctrl::knob },
		{ ID::exp_vcf_lever_ctrl, Ctrl::cbox },
		{ ID::exp_vcf_key_track, Ctrl::cbox },
		//exposed vca
		{ ID::exp_vca_1_volume, Ctrl::knob },
		{ ID::exp_vca_1_velo_amt, Ctrl::knob },
		{ ID::exp_vca_2_env_2_amt, Ctrl::knob },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, Ctrl::knob },
		{ ID::exp_vcf_fm_env_3_amt, Ctrl::knob },
		{ ID::exp_vcf_fm_press_amt, Ctrl::knob },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, Ctrl::knob },
		{ ID::exp_porta_velo, Ctrl::knob },
		{ ID::exp_porta_mode, Ctrl::cbox },
		{ ID::exp_porta_legato, Ctrl::cbox },
		{ ID::exp_keyboard_mode, Ctrl::cbox },
		//exposed lfo
		{ ID::exp_lfo_1_speed, Ctrl::knob },
		{ ID::exp_lfo_1_wave_type, Ctrl::cbox },
		{ ID::exp_lfo_1_samp_source, Ctrl::cbox },
		{ ID::exp_lfo_1_amp, Ctrl::knob },
		{ ID::exp_lfo_1_press_amt, Ctrl::knob },
		{ ID::exp_lfo_1_ramp_1_amt, Ctrl::knob },
		{ ID::exp_lfo_1_trig_mode, Ctrl::cbox },
		{ ID::exp_lfo_1_retrig_point, Ctrl::knob },
		{ ID::exp_lfo_1_lag, Ctrl::cbox },
		{ ID::exp_lfo_2_speed,Ctrl::knob },
		{ ID::exp_lfo_2_wave_type, Ctrl::cbox },
		{ ID::exp_lfo_2_samp_source, Ctrl::cbox },
		{ ID::exp_lfo_2_amp, Ctrl::knob },
		{ ID::exp_lfo_2_key_track_amt, Ctrl::knob },
		{ ID::exp_lfo_2_ramp_2_amt, Ctrl::knob },
		{ ID::exp_lfo_2_trig_mode, Ctrl::cbox },
		{ ID::exp_lfo_2_retrig_point, Ctrl::knob },
		{ ID::exp_lfo_2_lag, Ctrl::cbox },
		//exposed ramp
		{ ID::exp_ramp_1_rate, Ctrl::knob },
		{ ID::exp_ramp_1_trig, Ctrl::cbox },
		{ ID::exp_ramp_2_rate, Ctrl::knob },
		{ ID::exp_ramp_2_trig, Ctrl::cbox },
		//exposed tracking
		{ ID::exp_track_input, Ctrl::cbox },
		{ ID::exp_track_point_1, Ctrl::knob },
		{ ID::exp_track_point_2, Ctrl::knob },
		{ ID::exp_track_point_3, Ctrl::knob },
		{ ID::exp_track_point_4, Ctrl::knob },
		{ ID::exp_track_point_5, Ctrl::knob },
		//exposed env
		{ ID::exp_env_1_amp, Ctrl::knob },
		{ ID::exp_env_1_velo_amt, Ctrl::knob },
		{ ID::exp_env_1_trig_mode, Ctrl::cbox },
		{ ID::exp_env_1_mode, Ctrl::cbox },
		{ ID::exp_env_1_lfo_1_trig, Ctrl::cbox },
		{ ID::exp_env_1_delay, Ctrl::knob },
		{ ID::exp_env_1_attack, Ctrl::knob },
		{ ID::exp_env_1_decay, Ctrl::knob },
		{ ID::exp_env_1_sustain, Ctrl::knob },
		{ ID::exp_env_1_release, Ctrl::knob },
		{ ID::exp_env_2_amp, Ctrl::knob },
		{ ID::exp_env_2_velo_amt, Ctrl::knob },
		{ ID::exp_env_2_trig_mode, Ctrl::cbox },
		{ ID::exp_env_2_mode, Ctrl::cbox },
		{ ID::exp_env_2_lfo_1_trig, Ctrl::cbox },
		{ ID::exp_env_2_delay, Ctrl::knob },
		{ ID::exp_env_2_attack, Ctrl::knob },
		{ ID::exp_env_2_decay, Ctrl::knob },
		{ ID::exp_env_2_sustain, Ctrl::knob },
		{ ID::exp_env_2_release, Ctrl::knob },
		{ ID::exp_env_3_amp, Ctrl::knob },
		{ ID::exp_env_3_velo_amt, Ctrl::knob },
		{ ID::exp_env_3_trig_mode, Ctrl::cbox },
		{ ID::exp_env_3_mode, Ctrl::cbox },
		{ ID::exp_env_3_lfo_1_trig, Ctrl::cbox },
		{ ID::exp_env_3_delay, Ctrl::knob },
		{ ID::exp_env_3_attack, Ctrl::knob },
		{ ID::exp_env_3_decay, Ctrl::knob },
		{ ID::exp_env_3_sustain, Ctrl::knob },
		{ ID::exp_env_3_release, Ctrl::knob },
	};

}
