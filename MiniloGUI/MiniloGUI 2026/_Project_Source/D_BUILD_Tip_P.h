#pragma once

#include "D_BUILD_Tip_A.h"

struct Build_Tip :
	public Build_Tip_A
{
	static String exp_delay_feedback();
	static String exp_delay_routing();
	static String exp_delay_time();
	static String exp_delay_hpf_freq();

	static String exp_env_attack(bool vca = false);
	static String exp_env_decay(bool vca = false);
	static String exp_env_release(bool vca = false);
	static String exp_env_sustain(bool vca = false);

	static String exp_lpf_key_track();

	static String exp_level_knob(const int knob_num);
	static String exp_lfo_eg_mod();
	static String exp_lfo_int();
	static String exp_lfo_rate();
	static String exp_lfo_target();
	static String exp_lfo_wave();
	static String exp_lpf_eg_int();
	static String exp_lpf_freq();
	static String exp_lpf_reso();
	static String exp_lpf_type();
	static String exp_lpf_velo_amt();

	static String exp_osc_2_pitch_eg_int();
	static String exp_osc_2_ring_mod();
	static String exp_osc_2_sync();
	static String exp_osc_2_xmod_depth();
	static String exp_osc_octave(const int osc_num);
	static String exp_osc_pitch_fine(const int osc_num);
	static String exp_osc_shape(const int osc_num);
	static String exp_osc_wave(const int osc_num);

	static String exp_voice_mode_depth();
};