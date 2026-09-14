#pragma once

#include <array>

namespace ID
{

	constexpr auto exp_env_1_amp = "exp_env_1_amp";
	constexpr auto exp_env_1_attack = "exp_env_1_attack";
	constexpr auto exp_env_1_decay = "exp_env_1_decay";
	constexpr auto exp_env_1_delay = "exp_env_1_delay";
	constexpr auto exp_env_1_lfo_1_trig = "exp_env_1_lfo_1_trig";
	constexpr auto exp_env_1_mode = "exp_env_1_mode";
	constexpr auto exp_env_1_release = "exp_env_1_release";
	constexpr auto exp_env_1_sustain = "exp_env_1_sustain";
	constexpr auto exp_env_1_trig_mode = "exp_env_1_trig_mode";
	constexpr auto exp_env_1_velo_amt = "exp_env_1_velo_amt";
	constexpr auto exp_env_2_amp = "exp_env_2_amp";
	constexpr auto exp_env_2_attack = "exp_env_2_attack";
	constexpr auto exp_env_2_decay = "exp_env_2_decay";
	constexpr auto exp_env_2_delay = "exp_env_2_delay";
	constexpr auto exp_env_2_lfo_1_trig = "exp_env_2_lfo_1_trig";
	constexpr auto exp_env_2_mode = "exp_env_2_mode";
	constexpr auto exp_env_2_release = "exp_env_2_release";
	constexpr auto exp_env_2_sustain = "exp_env_2_sustain";
	constexpr auto exp_env_2_trig_mode = "exp_env_2_trig_mode";
	constexpr auto exp_env_2_velo_amt = "exp_env_2_velo_amt";
	constexpr auto exp_env_3_amp = "exp_env_3_amp";
	constexpr auto exp_env_3_attack = "exp_env_3_attack";
	constexpr auto exp_env_3_decay = "exp_env_3_decay";
	constexpr auto exp_env_3_delay = "exp_env_3_delay";
	constexpr auto exp_env_3_lfo_1_trig = "exp_env_3_lfo_1_trig";
	constexpr auto exp_env_3_mode = "exp_env_3_mode";
	constexpr auto exp_env_3_release = "exp_env_3_release";
	constexpr auto exp_env_3_sustain = "exp_env_3_sustain";
	constexpr auto exp_env_3_trig_mode = "exp_env_3_trig_mode";
	constexpr auto exp_env_3_velo_amt = "exp_env_3_velo_amt";
	constexpr auto exp_keyboard_mode = "exp_keyboard_mode";
	constexpr auto exp_lfo_1_amp = "exp_lfo_1_amp";
	constexpr auto exp_lfo_1_lag = "exp_lfo_1_lag";
	constexpr auto exp_lfo_1_press_amt = "exp_lfo_1_press_amt";
	constexpr auto exp_lfo_1_ramp_1_amt = "exp_lfo_1_ramp_1_amt";
	constexpr auto exp_lfo_1_retrig_point = "exp_lfo_1_retrig_point";
	constexpr auto exp_lfo_1_samp_source = "exp_lfo_1_samp_source";
	constexpr auto exp_lfo_1_speed = "exp_lfo_1_speed";
	constexpr auto exp_lfo_1_trig_mode = "exp_lfo_1_trig_mode";
	constexpr auto exp_lfo_1_wave_type = "exp_lfo_1_wave_type";
	constexpr auto exp_lfo_2_amp = "exp_lfo_2_amp";
	constexpr auto exp_lfo_2_key_track_amt = "exp_lfo_2_key_track_amt";
	constexpr auto exp_lfo_2_lag = "exp_lfo_2_lag";
	constexpr auto exp_lfo_2_ramp_2_amt = "exp_lfo_2_ramp_2_amt";
	constexpr auto exp_lfo_2_retrig_point = "exp_lfo_2_retrig_point";
	constexpr auto exp_lfo_2_samp_source = "exp_lfo_2_samp_source";
	constexpr auto exp_lfo_2_speed = "exp_lfo_2_speed";
	constexpr auto exp_lfo_2_trig_mode = "exp_lfo_2_trig_mode";
	constexpr auto exp_lfo_2_wave_type = "exp_lfo_2_wave_type";
	constexpr auto exp_osc_1_key_click = "exp_osc_1_key_click";
	constexpr auto exp_osc_1_key_track = "exp_osc_1_key_track";
	constexpr auto exp_osc_1_lever_ctrl = "exp_osc_1_lever_ctrl";
	constexpr auto exp_osc_1_lfo_1_fm = "exp_osc_1_lfo_1_fm";
	constexpr auto exp_osc_1_lfo_2_pwm = "exp_osc_1_lfo_2_pwm";
	constexpr auto exp_osc_1_pitch = "exp_osc_1_pitch";
	constexpr auto exp_osc_1_pulse_w = "exp_osc_1_pulse_w";
	constexpr auto exp_osc_1_saw_tri = "exp_osc_1_saw_tri";
	constexpr auto exp_osc_1_sync = "exp_osc_1_sync";
	constexpr auto exp_osc_1_type = "exp_osc_1_type";
	constexpr auto exp_osc_2_detune = "exp_osc_2_detune";
	constexpr auto exp_osc_2_key_click = "exp_osc_2_key_click";
	constexpr auto exp_osc_2_key_track = "exp_osc_2_key_track";
	constexpr auto exp_osc_2_lever_ctrl = "exp_osc_2_lever_ctrl";
	constexpr auto exp_osc_2_lfo_1_fm = "exp_osc_2_lfo_1_fm";
	constexpr auto exp_osc_2_lfo_2_pwm = "exp_osc_2_lfo_2_pwm";
	constexpr auto exp_osc_2_pitch = "exp_osc_2_pitch";
	constexpr auto exp_osc_2_pulse_w = "exp_osc_2_pulse_w";
	constexpr auto exp_osc_2_saw_tri = "exp_osc_2_saw_tri";
	constexpr auto exp_osc_2_type = "exp_osc_2_type";
	constexpr auto exp_osc_balance = "exp_osc_balance";
	constexpr auto exp_porta_legato = "exp_porta_legato";
	constexpr auto exp_porta_mode = "exp_porta_mode";
	constexpr auto exp_porta_rate = "exp_porta_rate";
	constexpr auto exp_porta_velo = "exp_porta_velo";
	constexpr auto exp_vca_1_velo_amt = "exp_vca_1_velo_amt";
	constexpr auto exp_vca_1_volume = "exp_vca_1_volume";
	constexpr auto exp_vca_2_env_2_amt = "exp_vca_2_env_2_amt";
	constexpr auto exp_vcf_env_1_amt = "exp_vcf_env_1_amt";
	constexpr auto exp_vcf_fm_env_3_amt = "exp_vcf_fm_env_3_amt";
	constexpr auto exp_vcf_fm_osc_1_amt = "exp_vcf_fm_osc_1_amt";
	constexpr auto exp_vcf_fm_press_amt = "exp_vcf_fm_press_amt";
	constexpr auto exp_vcf_freq = "exp_vcf_freq";
	constexpr auto exp_vcf_key_track = "exp_vcf_key_track";
	constexpr auto exp_vcf_lever_ctrl = "exp_vcf_lever_ctrl";
	constexpr auto exp_vcf_press_amt = "exp_vcf_press_amt";
	constexpr auto exp_vcf_reso = "exp_vcf_reso";
	constexpr auto exp_ramp_1_rate = "exp_ramp_1_rate";
	constexpr auto exp_ramp_1_trig = "exp_ramp_1_trig";
	constexpr auto exp_ramp_2_rate = "exp_ramp_2_rate";
	constexpr auto exp_ramp_2_trig = "exp_ramp_2_trig";
	constexpr auto exp_track_input = "exp_track_input";
	constexpr auto exp_track_point_1 = "exp_track_point_1";
	constexpr auto exp_track_point_2 = "exp_track_point_2";
	constexpr auto exp_track_point_3 = "exp_track_point_3";
	constexpr auto exp_track_point_4 = "exp_track_point_4";
	constexpr auto exp_track_point_5 = "exp_track_point_5";

	constexpr auto mmod_0_amt = "mmod_0_amt";
	constexpr auto mmod_0_dst = "mmod_0_dst";
	constexpr auto mmod_0_src = "mmod_0_src";
	constexpr auto mmod_1_amt = "mmod_1_amt";
	constexpr auto mmod_1_dst = "mmod_1_dst";
	constexpr auto mmod_1_src = "mmod_1_src";
	constexpr auto mmod_2_amt = "mmod_2_amt";
	constexpr auto mmod_2_dst = "mmod_2_dst";
	constexpr auto mmod_2_src = "mmod_2_src";
	constexpr auto mmod_3_amt = "mmod_3_amt";
	constexpr auto mmod_3_dst = "mmod_3_dst";
	constexpr auto mmod_3_src = "mmod_3_src";
	constexpr auto mmod_4_amt = "mmod_4_amt";
	constexpr auto mmod_4_dst = "mmod_4_dst";
	constexpr auto mmod_4_src = "mmod_4_src";
	constexpr auto mmod_5_amt = "mmod_5_amt";
	constexpr auto mmod_5_dst = "mmod_5_dst";
	constexpr auto mmod_5_src = "mmod_5_src";
	constexpr auto mmod_6_amt = "mmod_6_amt";
	constexpr auto mmod_6_dst = "mmod_6_dst";
	constexpr auto mmod_6_src = "mmod_6_src";
	constexpr auto mmod_7_amt = "mmod_7_amt";
	constexpr auto mmod_7_dst = "mmod_7_dst";
	constexpr auto mmod_7_src = "mmod_7_src";
	constexpr auto mmod_8_amt = "mmod_8_amt";
	constexpr auto mmod_8_dst = "mmod_8_dst";
	constexpr auto mmod_8_src = "mmod_8_src";
	constexpr auto mmod_9_amt = "mmod_9_amt";
	constexpr auto mmod_9_dst = "mmod_9_dst";
	constexpr auto mmod_9_src = "mmod_9_src";

	constexpr std::array<const char*, 96> exp_params{
		exp_osc_1_pitch,
		exp_osc_1_type,
		exp_osc_1_pulse_w,
		exp_osc_1_saw_tri,
		exp_osc_1_sync,
		exp_osc_1_lfo_1_fm,
		exp_osc_1_lfo_2_pwm,
		exp_osc_1_key_click,
		exp_osc_1_key_track,
		exp_osc_1_lever_ctrl,
		exp_osc_2_pitch,
		exp_osc_2_type,
		exp_osc_2_pulse_w,
		exp_osc_2_saw_tri,
		exp_osc_2_detune,
		exp_osc_2_lfo_1_fm,
		exp_osc_2_lfo_2_pwm,
		exp_osc_2_key_click,
		exp_osc_2_key_track,
		exp_osc_2_lever_ctrl,
		exp_osc_balance,
		exp_vcf_freq,
		exp_vcf_reso,
		exp_vcf_env_1_amt,
		exp_vcf_press_amt,
		exp_vcf_lever_ctrl,
		exp_vcf_key_track,
		exp_vca_1_volume,
		exp_vca_1_velo_amt,
		exp_vca_2_env_2_amt,
		exp_vcf_fm_osc_1_amt,
		exp_vcf_fm_env_3_amt,
		exp_vcf_fm_press_amt,
		exp_porta_rate,
		exp_porta_velo,
		exp_porta_mode,
		exp_porta_legato,
		exp_keyboard_mode,
		exp_lfo_1_speed,
		exp_lfo_1_wave_type,
		exp_lfo_1_samp_source,
		exp_lfo_1_amp,
		exp_lfo_1_press_amt,
		exp_lfo_1_ramp_1_amt,
		exp_lfo_1_trig_mode,
		exp_lfo_1_retrig_point,
		exp_lfo_1_lag,
		exp_lfo_2_speed,
		exp_lfo_2_wave_type,
		exp_lfo_2_samp_source,
		exp_lfo_2_amp,
		exp_lfo_2_key_track_amt,
		exp_lfo_2_ramp_2_amt,
		exp_lfo_2_trig_mode,
		exp_lfo_2_retrig_point,
		exp_lfo_2_lag,
		exp_ramp_1_rate,
		exp_ramp_1_trig,
		exp_ramp_2_rate,
		exp_ramp_2_trig,
		exp_track_input,
		exp_track_point_1,
		exp_track_point_2,
		exp_track_point_3,
		exp_track_point_4,
		exp_track_point_5,
		exp_env_1_amp,
		exp_env_1_velo_amt,
		exp_env_1_trig_mode,
		exp_env_1_mode,
		exp_env_1_lfo_1_trig,
		exp_env_1_delay,
		exp_env_1_attack,
		exp_env_1_decay,
		exp_env_1_sustain,
		exp_env_1_release,
		exp_env_2_amp,
		exp_env_2_velo_amt,
		exp_env_2_trig_mode,
		exp_env_2_mode,
		exp_env_2_lfo_1_trig,
		exp_env_2_delay,
		exp_env_2_attack,
		exp_env_2_decay,
		exp_env_2_sustain,
		exp_env_2_release,
		exp_env_3_amp,
		exp_env_3_velo_amt,
		exp_env_3_trig_mode,
		exp_env_3_mode,
		exp_env_3_lfo_1_trig,
		exp_env_3_delay,
		exp_env_3_attack,
		exp_env_3_decay,
		exp_env_3_sustain,
		exp_env_3_release
	};

	constexpr std::array<const char*, 30> matrix_mod_params{
		mmod_0_src,
		mmod_0_amt,
		mmod_0_dst,
		mmod_1_src,
		mmod_1_amt,
		mmod_1_dst,
		mmod_2_src,
		mmod_2_amt,
		mmod_2_dst,
		mmod_3_src,
		mmod_3_amt,
		mmod_3_dst,
		mmod_4_src,
		mmod_4_amt,
		mmod_4_dst,
		mmod_5_src,
		mmod_5_amt,
		mmod_5_dst,
		mmod_6_src,
		mmod_6_amt,
		mmod_6_dst,
		mmod_7_src,
		mmod_7_amt,
		mmod_7_dst,
		mmod_8_src,
		mmod_8_amt,
		mmod_8_dst,
		mmod_9_src,
		mmod_9_amt,
		mmod_9_dst,
	};

}
