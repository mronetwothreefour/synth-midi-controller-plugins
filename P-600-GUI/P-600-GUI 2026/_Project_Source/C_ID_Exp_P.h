#pragma once

#include <JuceHeader.h>

namespace ID
{

	static const String exp_amp_env_attack{ "exp_amp_env_attack" };
	static const String exp_amp_env_decay{ "exp_amp_env_decay" };
	static const String exp_amp_env_release{ "exp_amp_env_release" };
	static const String exp_amp_env_sustain{ "exp_amp_env_sustain" };
	static const String exp_filter_cutoff{ "exp_filter_cutoff" };
	static const String exp_filter_env_amt{ "exp_filter_env_amt" };
	static const String exp_filter_env_attack{ "exp_filter_env_attack" };
	static const String exp_filter_env_decay{ "exp_filter_env_decay" };
	static const String exp_filter_env_release{ "exp_filter_env_release" };
	static const String exp_filter_env_sustain{ "exp_filter_env_sustain" };
	static const String exp_filter_key_track{ "exp_filter_key_track" };
	static const String exp_filter_reso{ "exp_filter_reso" };
	static const String exp_glide{ "exp_glide" };
	static const String exp_lfo_dest_filter{ "exp_lfo_dest_filter" };
	static const String exp_lfo_dest_osc_pitch{ "exp_lfo_dest_osc_pitch" };
	static const String exp_lfo_dest_osc_pw{ "exp_lfo_dest_osc_pw" };
	static const String exp_lfo_freq{ "exp_lfo_freq" };
	static const String exp_lfo_init_amt{ "exp_lfo_init_amt" };
	static const String exp_lfo_shape{ "exp_lfo_shape" };
	static const String exp_mixer{ "exp_mixer" };
	static const String exp_osc_a_pitch{ "exp_osc_a_pitch" };
	static const String exp_osc_a_pulse{ "exp_osc_a_pulse" };
	static const String exp_osc_a_pulse_w{ "exp_osc_a_pulse_w" };
	static const String exp_osc_a_saw{ "exp_osc_a_saw" };
	static const String exp_osc_a_sync{ "exp_osc_a_sync" };
	static const String exp_osc_a_tri{ "exp_osc_a_tri" };
	static const String exp_osc_b_fine{ "exp_osc_b_fine" };
	static const String exp_osc_b_pitch{ "exp_osc_b_pitch" };
	static const String exp_osc_b_pulse{ "exp_osc_b_pulse" };
	static const String exp_osc_b_pulse_w{ "exp_osc_b_pulse_w" };
	static const String exp_osc_b_saw{ "exp_osc_b_saw" };
	static const String exp_osc_b_tri{ "exp_osc_b_tri" };
	static const String exp_p_mod_amt_filter_env{ "exp_p_mod_amt_filter_env" };
	static const String exp_p_mod_amt_osc_b{ "exp_p_mod_amt_osc_b" };
	static const String exp_p_mod_dest_filter{ "exp_p_mod_dest_filter" };
	static const String exp_p_mod_dest_osc_a_freq{ "exp_p_mod_dest_osc_a_freq" };
	static const String exp_unison_track{ "exp_unison_track" };

	static const StringArray exposed_id{
		exp_unison_track,
		exp_osc_a_pitch,
		exp_osc_a_sync,
		exp_osc_a_saw,
		exp_osc_a_tri,
		exp_osc_a_pulse,
		exp_osc_a_pulse_w,
		exp_osc_b_pitch,
		exp_osc_b_fine,
		exp_osc_b_saw,
		exp_osc_b_tri,
		exp_osc_b_pulse,
		exp_osc_b_pulse_w,
		exp_mixer,
		exp_glide,
		exp_filter_cutoff,
		exp_filter_reso,
		exp_filter_env_amt,
		exp_filter_key_track,
		exp_filter_env_attack,
		exp_filter_env_decay,
		exp_filter_env_sustain,
		exp_filter_env_release,
		exp_amp_env_attack,
		exp_amp_env_decay,
		exp_amp_env_sustain,
		exp_amp_env_release,
		exp_p_mod_amt_filter_env,
		exp_p_mod_amt_osc_b,
		exp_p_mod_dest_osc_a_freq,
		exp_p_mod_dest_filter,
		exp_lfo_freq,
		exp_lfo_shape,
		exp_lfo_init_amt,
		exp_lfo_dest_osc_pitch,
		exp_lfo_dest_osc_pw,
		exp_lfo_dest_filter,
	};

}
