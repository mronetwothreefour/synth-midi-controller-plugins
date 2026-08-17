#pragma once

#include "D_BUILD_Tip_A.h"

namespace BUILD
{

	struct Tip :
		public Tip_A
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

		static String exp_keyboard_mode();

		static String exp_lfo_1_pressure_amt();
		static String exp_lfo_2_key_track_amt();
		static String exp_lfo_amp(const int lfo_num);
		static String exp_lfo_lag(const int lfo_num);
		static String exp_lfo_ramp_amt(const int lfo_num);
		static String exp_lfo_retrig_point(const int lfo_num);
		static String exp_lfo_sample_source(const int lfo_num);
		static String exp_lfo_speed(const int lfo_num);
		static String exp_lfo_trig_mode(const int lfo_num);
		static String exp_lfo_wave_type(const int lfo_num);

		static String exp_osc_1_sync();
		static String exp_osc_2_detune();
		static String exp_osc_balance();
		static String exp_osc_key_click();
		static String exp_osc_key_track(const int osc_num);
		static String exp_osc_lever_control(const int osc_num);
		static String exp_osc_lfo_1_fm(const int osc_num);
		static String exp_osc_lfo_2_pwm(const int osc_num);
		static String exp_osc_pitch(const int osc_num);
		static String exp_osc_pulse_w(const int osc_num);
		static String exp_osc_saw_tri(const int osc_num);
		static String exp_osc_type(const int osc_num);

		static String exp_porta_legato();
		static String exp_porta_mode();
		static String exp_porta_rate();
		static String exp_porta_velo();

		static String exp_ramp_rate(const int ramp_num);
		static String exp_ramp_trig(const int ramp_num);

		static String exp_track_input();
		static String exp_track_point(const int point_num, int init_choice);

		static String exp_vca_1_velo_amt();
		static String exp_vca_1_volume();
		static String exp_vca_2_env_2_amt();

		static String exp_vcf_env_1_amt();
		static String exp_vcf_fm_env_3_amt();
		static String exp_vcf_fm_osc_1_amt();
		static String exp_vcf_fm_press_amt();
		static String exp_vcf_freq();
		static String exp_vcf_key_track();
		static String exp_vcf_lever_ctrl();
		static String exp_vcf_press_amt();
		static String exp_vcf_reso();

		static String knob_txt_editor(const String& slider_label_name, bool u_7_bit = false);
	};

}
