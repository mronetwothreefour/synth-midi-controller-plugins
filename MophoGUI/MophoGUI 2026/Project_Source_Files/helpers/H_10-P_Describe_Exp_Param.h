#pragma once

#include <JuceHeader.h>

struct Describe_Exp_Param
{
	static String from_string_literal(const char8_t* sl);

	static String arpeg_mode();
	static String arpeg_on_off();

	static String bend_range();

	static String clock_division();
	static String clock_tempo();

	static String env_3_amt();
	static String env_3_repeat();
	static String env_attack(const String env_name);
	static String env_decay(const String env_name);
	static String env_delay(const String env_name);
	static String env_release(const String env_name);
	static String env_sustain(const String env_name);
	static String env_vel_amt(const String env_name);
	static String ext_in_level();

	static String glide_mode();

	static String knob_assign(const int knob_num);

	static String lfo_amt(const int lfo_num);
	static String lfo_freq(const int lfo_num);
	static String lfo_key_sync(const int lfo_num);
	static String lfo_shape(const int lfo_num);
	static String lpf_env_amt();
	static String lpf_fm_amt();
	static String lpf_freq();
	static String lpf_key_amt();
	static String lpf_reso();
	static String lpf_type();

	static String midi_breath_amt();
	static String midi_mod_wheel_amt();
	static String midi_pedal_amt();
	static String midi_pressure_amt();
	static String midi_velocity_amt();
	static String mod_amt();

	static String noise_level();
	static String note_priority();

	static String osc_fine(const int osc_num);
	static String osc_glide(const int osc_num);
	static String osc_key_track(const int osc_num);
	static String osc_mix();
	static String osc_pitch(const int osc_num);
	static String osc_shape(const int osc_num);
	static String osc_slop();
	static String osc_sub_level(const int osc_num);
	static String osc_sync();

	static String push_it_mode();
	static String push_it_pitch();
	static String push_it_velocity();

	static String seq_on_off();
	static String seq_track_dest(const int track_num);
	static String seq_track_step(const int track_num, int step_num);
	static String seq_trig_mode();

	static String vca_env_amt();
	static String vca_level();
	static String voice_name_char(const int char_num);
	static String voice_volume();
};