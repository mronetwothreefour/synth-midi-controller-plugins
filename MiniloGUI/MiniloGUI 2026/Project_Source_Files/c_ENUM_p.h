#pragma once

namespace ENUM
{

	constexpr enum class Ctrl_Type {
		error = -1,
		dummy,
		knob,
		knob_osc_pitch_fine,
		knob_osc_2_pitch_eg_int,
		knob_tempo,
		knob_voice_mode_depth,
		knob_lfo_rate,
		knob_lpf_freq,
		switch_2_pole,
		switch_3_pole,
		switch_lpf_type,
		switch_osc_octave
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		lfo_rate,
		lpf_eg_int,
		osc_2_pitch_eg_int,
		osc_pitch_fine,
		unsigned_10_bit,
		voice_mode_depth
	};

	constexpr enum class Microtune_Scale {
		equal_temp = 0,
		pure_major,
		pure_minor,
		pythagorean,
		werckmeister,
		kirnberger,
		slendro,
		pelog,
		ionian,
		dorian,
		aeolian,
		major_penta,
		minor_penta,
		reverse,
		afx_1,
		afx_2,
		afx_3,
		afx_4,
		afx_5,
		afx_6,
		dc_1,
		dc_2,
		dc_3,
		user_scale_1,
		user_scale_2,
		user_scale_3,
		user_scale_4,
		user_scale_5,
		user_scale_6,
		user_octave_1,
		user_octave_2,
		user_octave_3,
		user_octave_4,
		user_octave_5,
		user_octave_6
	};

	constexpr enum class Slider_Target {
		pitch_bend = 0,
		gate_time,
		osc_1_pitch,
		osc_1_shape,
		osc_2_pitch,
		osc_2_shape,
		osc_2_x_mod_depth,
		osc_2_pitch_eg_int,
		level_osc_1,
		level_osc_2,
		level_noise,
		lpf_cutoff,
		lpf_reso,
		lpf_eg_int,
		vca_env_attack,
		vca_env_decay,
		vca_env_sustain,
		vca_env_release,
		env_attack,
		env_decay,
		env_sustain,
		env_release,
		lfo_rate,
		lfo_int,
		delay_hpf_freq,
		delay_time,
		delay_feedback,
		porta_time,
		voice_mode_depth
	};

	constexpr enum class Voice_Mode {
		poly = 0,
		duo,
		unison,
		mono,
		chord,
		delay,
		arp,
		sidechain
	};

}
