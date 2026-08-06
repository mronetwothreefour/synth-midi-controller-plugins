#pragma once

namespace ENUM
{

	constexpr enum class App_Option {
		scale_percentage
	};

	constexpr enum class Ctrl_Type {
		error = -1,
		knob,
		knob_osc_pitch,
		switch_2_pole,
		switch_3_pole
	};

	constexpr enum Exp_Param {
		amp_env_attack,
		amp_env_decay,
		amp_env_release,
		amp_env_sustain,
		filter_cutoff,
		filter_env_amt,
		filter_env_attack,
		filter_env_decay,
		filter_env_release,
		filter_env_sustain,
		filter_key_track,
		filter_reso,
		glide,
		lfo_dest_filter,
		lfo_dest_osc_pitch,
		lfo_dest_osc_pw,
		lfo_freq,
		lfo_init_amt,
		lfo_shape,
		mixer,
		osc_a_pitch,
		osc_a_pulse,
		osc_a_pulse_w,
		osc_a_saw,
		osc_a_sync,
		osc_a_tri,
		osc_b_fine,
		osc_b_pitch,
		osc_b_pulse,
		osc_b_pulse_w,
		osc_b_saw,
		osc_b_tri,
		p_mod_amt_filter_env,
		p_mod_amt_osc_b,
		p_mod_dest_filter,
		p_mod_dest_osc_a_freq,
		unison_track
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		int_4_bit,
		int_5_bit,
		int_6_bit,
		int_7_bit,
		osc_pitch
	};

}
