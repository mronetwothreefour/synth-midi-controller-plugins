#pragma once

#include <JuceHeader.h>

struct Describe_Exp_Param
{
	static String env_amp(const String env_num);
	static String env_attack(const String env_num);
	static String env_decay(const String env_num);
	static String env_delay(const String env_num);
	static String env_lfo_1_trig(const String env_num);
	static String env_mode(const String env_num);
	static String env_release(const String env_num);
	static String env_sustain(const String env_num);
	static String env_trig_mode(const String env_num);
	static String env_velo_amt(const String env_num);

	static String keyboard_mode();

	static String lfo_1_pressure_amt();
	static String lfo_2_key_track_amt();
	static String lfo_amp(const int lfo_num);
	static String lfo_lag(const int lfo_num);
	static String lfo_ramp_amt(const int lfo_num);
	static String lfo_retrig_point(const int lfo_num);
	static String lfo_sample_source(const int lfo_num);
	static String lfo_speed(const int lfo_num);
	static String lfo_trig_mode(const int lfo_num);
	static String lfo_wave_type(const int lfo_num);

	static String osc_1_sync();
	static String osc_2_detune();
	static String osc_balance();
	static String osc_key_click();
	static String osc_key_track(const int osc_num);
	static String osc_lever_control(const int osc_num);
	static String osc_lfo_1_fm(const int osc_num);
	static String osc_lfo_2_pwm(const int osc_num);
	static String osc_pitch(const int osc_num);
	static String osc_pulse_w(const int osc_num);
	static String osc_saw_tri(const int osc_num);
	static String osc_type(const int osc_num);

	static String porta_legato();
	static String porta_mode();
	static String porta_rate();
	static String porta_velo();

	static String ramp_rate(const int ramp_num);
	static String ramp_trig(const int ramp_num);

	static String track_input();
	static String track_point(const int point_num, int init_choice);

	static String vca_1_velo_amt();
	static String vca_1_volume();
	static String vca_2_env_2_amt();

	static String vcf_env_1_amt();
	static String vcf_fm_env_3_amt();
	static String vcf_fm_osc_1_amt();
	static String vcf_fm_pressure_amt();
	static String vcf_freq();
	static String vcf_key_track();
	static String vcf_lever_ctrl();
	static String vcf_pressure_amt();
	static String vcf_reso();
};