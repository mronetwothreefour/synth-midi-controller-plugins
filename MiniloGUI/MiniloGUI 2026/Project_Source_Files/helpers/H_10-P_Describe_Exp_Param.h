#pragma once

#include <JuceHeader.h>

struct Describe_Exp_Param
{
	static String from_string_literal(const char8_t* sl);

	static String delay_feedback();
	static String delay_routing();
	static String delay_time();
	static String delay_hpf_freq();

	static String env_attack(bool vca = false);
	static String env_decay(bool vca = false);
	static String env_release(bool vca = false);
	static String env_sustain(bool vca = false);

	static String key_track();

	static String level_knob(const int knob_num);

	static String osc_octave(const int osc_num);
	static String osc_pitch_fine(const int osc_num);
	static String osc_shape(const int osc_num);
	static String osc_wave(const int osc_num);
};