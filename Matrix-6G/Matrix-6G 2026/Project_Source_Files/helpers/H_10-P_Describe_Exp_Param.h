#pragma once

#include <JuceHeader.h>

struct Describe_Exp_Param
{
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
};