#pragma once

#include "D_BUILD_Tip_For_A.h"

namespace BUILD
{

	struct Tip_For :
		public Tip_For_A
	{
		static String exp_env_amp(const int env_num);
		static String exp_env_attack(const int env_num);
		static String exp_env_decay(const int env_num);
		static String exp_env_delay(const int env_num);
		static String exp_env_lfo_1_trig(const int env_num);
		static String exp_env_mode(const int env_num);
		static String exp_env_release(const int env_num);
		static String exp_env_sustain(const int env_num);
		static String exp_env_trig_mode(const int env_num);
		static String exp_env_velo_amt(const int env_num);

		static String exp_lfo_amp(const int lfo_num);
		static String exp_lfo_lag(const int lfo_num);
		static String exp_lfo_ramp_amt(const int lfo_num);
		static String exp_lfo_retrig_point(const int lfo_num);
		static String exp_lfo_sample_source(const int lfo_num);
		static String exp_lfo_speed(const int lfo_num);
		static String exp_lfo_trig_mode(const int lfo_num);
		static String exp_lfo_wave_type(const int lfo_num);

		static String exp_osc_key_track(const int osc_num);
		static String exp_osc_lever_control(const int osc_num);
		static String exp_osc_lfo_1_fm(const int osc_num);
		static String exp_osc_lfo_2_pwm(const int osc_num);
		static String exp_osc_pitch(const int osc_num);
		static String exp_osc_pulse_w(const int osc_num);
		static String exp_osc_saw_tri(const int osc_num);
		static String exp_osc_type(const int osc_num);

		static String exp_ramp_rate(const int ramp_num);
		static String exp_ramp_trig(const int ramp_num);

		static String exp_track_point(const int point_num, int init_choice);

		static String knob_txt_editor(const String& slider_label_name, bool u_7_bit = false);
	};

}
