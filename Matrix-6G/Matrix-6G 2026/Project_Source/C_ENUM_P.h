#pragma once

namespace ENUM
{

	constexpr enum class Ctrl_Type {
		error = -1,
		slider,
		slider_osc_pitch,
		slider_osc_balance,
		cbox
	};

	constexpr enum Exp_Param {
		env_1_attack,
		env_1_decay,
		env_1_delay,
		env_1_release,
		env_1_sustain,
		env_2_attack,
		env_2_decay,
		env_2_delay,
		env_2_release,
		env_2_sustain,
		env_3_attack,
		env_3_decay,
		env_3_delay,
		env_3_release,
		env_3_sustain,
		keyboard_mode,
		lfo_1_amp,
		lfo_1_lag,
		lfo_1_press_amt,
		lfo_1_ramp_1_amt,
		lfo_1_retrig_point,
		lfo_1_samp_source,
		lfo_1_speed,
		lfo_1_trig_mode,
		lfo_1_wave_type,
		lfo_2_amp,
		lfo_2_key_track_amt,
		lfo_2_lag,
		lfo_2_ramp_1_amt,
		lfo_2_retrig_point,
		lfo_2_samp_source,
		lfo_2_speed,
		lfo_2_trig_mode,
		lfo_2_wave_type,
		osc_1_key_click,
		osc_1_key_track,
		osc_1_lever_ctrl,
		osc_1_lfo_1_fm,
		osc_1_lfo_2_pwm,
		osc_1_pitch,
		osc_1_pulse_w,
		osc_1_saw_tri,
		osc_1_sync,
		osc_1_type,
		osc_2_detune,
		osc_2_key_click,
		osc_2_key_track,
		osc_2_lever_ctrl,
		osc_2_lfo_1_fm,
		osc_2_lfo_2_pwm,
		osc_2_pitch,
		osc_2_pulse_w,
		osc_2_saw_tri,
		osc_2_type,
		osc_balance,
		porta_legato,
		porta_mode,
		porta_rate,
		porta_velo,
		vca_1_velo_amt,
		vca_1_volume,
		vca_2_env_2_amt,
		vcf_env_1_amt,
		vcf_fm_env_3_amt,
		vcf_fm_osc_1_amt,
		vcf_fm_press_amt,
		vcf_freq,
		vcf_key_track,
		vcf_lever_ctrl,
		vcf_press_amt,
		vcf_reso,
		ramp_1_rate,
		ramp_1_trig,
		ramp_2_rate,
		ramp_2_trig,
		track_input,
		track_point_1,
		track_point_2,
		track_point_3,
		track_point_4,
		track_point_5,
	};

	constexpr enum class Input_Choice_Type {
		mod,
		lfo,
		tracking
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		osc_pitch,
		signed_6_bit,
		signed_7_bit,
		unsigned_int
	};

	constexpr enum class Range_Type {
		error = -1,
		signed_6_bit,
		signed_7_bit,
		unsigned_int
	};

}
