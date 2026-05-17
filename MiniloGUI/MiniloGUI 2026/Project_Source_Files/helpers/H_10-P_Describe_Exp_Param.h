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
	static String lfo_eg_mod();
	static String lfo_int();
	static String lfo_rate();
	static String lfo_target();
	static String lfo_wave();
	static String lpf_eg_int();
	static String lpf_freq();
	static String lpf_reso();
	static String lpf_type();
	static String lpf_vel_amt();

	static String osc_2_pitch_eg_int();
	static String osc_2_ring_mod();
	static String osc_2_sync();
	static String osc_2_x_mod_depth();
	static String osc_octave(const int osc_num);
	static String osc_pitch_fine(const int osc_num);
	static String osc_shape(const int osc_num);
	static String osc_wave(const int osc_num);

	static String voice_mode_depth();
};