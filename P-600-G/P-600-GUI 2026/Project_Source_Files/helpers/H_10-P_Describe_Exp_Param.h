#pragma once

#include <JuceHeader.h>

struct Describe_Exp_Param
{
	static String env_attack(bool filter_env = false);
	static String env_decay(bool filter_env = false);
	static String env_release(bool filter_env = false);
	static String env_sustain(bool filter_env = false);

	static String filter_cutoff();
	static String filter_env_amt();
	static String filter_key_track();
	static String filter_reso();

	static String glide();

	static String lfo_dest_filter();
	static String lfo_dest_osc_pitch();
	static String lfo_dest_osc_pulse_w();
	static String lfo_freq();
	static String lfo_init_amt();
	static String lfo_shape();

	static String mixer();

	static String osc_pitch(const int osc_num);
	static String osc_pulse_w(const int osc_num);
	static String osc_a_sync();
	static String osc_b_fine();

	static String poly_mod_dest_filter_freq();
	static String poly_mod_dest_osc_a_pitch();
	static String poly_mod_src_filter_env_amt();
	static String poly_mod_src_osc_b_amt();

	static String unisonTrack();
};