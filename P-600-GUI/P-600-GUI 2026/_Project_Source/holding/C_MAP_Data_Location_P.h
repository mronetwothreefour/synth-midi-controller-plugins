#pragma once

#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> data_location{
		//osc
		{ ID::exp_unison_track, "1st nybble:31__1st bit:3__bit count:1" },
		{ ID::exp_osc_a_pitch, "1st nybble:8__1st bit:1__bit count:6" },
		{ ID::exp_osc_a_sync, "1st nybble:30__1st bit:2__bit count:1" },
		{ ID::exp_osc_a_saw, "1st nybble:30__1st bit:0__bit count:1" },
		{ ID::exp_osc_a_tri, "1st nybble:30__1st bit:1__bit count:1" },
		{ ID::exp_osc_a_pulse, "1st nybble:28__1st bit:0__bit count:1" },
		{ ID::exp_osc_a_pulse_w, "1st nybble:0__1st bit:0__bit count:7" },
		{ ID::exp_osc_b_pitch, "1st nybble:6__1st bit:3__bit count:6" },
		{ ID::exp_osc_b_fine, "1st nybble:9__1st bit:3__bit count:7" },
		{ ID::exp_osc_b_saw, "1st nybble:30__1st bit:3__bit count:1" },
		{ ID::exp_osc_b_tri, "1st nybble:31__1st bit:0__bit count:1" },
		{ ID::exp_osc_b_pulse, "1st nybble:28__1st bit:1__bit count:1" },
		{ ID::exp_osc_b_pulse_w, "1st nybble:26__1st bit:1__bit count:7" },
		{ ID::exp_mixer, "1st nybble:11__1st bit:2__bit count:6" },
		{ ID::exp_glide, "1st nybble:25__1st bit:1__bit count:4" },
		//filter
		{ ID::exp_filter_cutoff, "1st nybble:13__1st bit:0__bit count:7" },
		{ ID::exp_filter_reso, "1st nybble:14__1st bit:3__bit count:6" },
		{ ID::exp_filter_env_amt, "1st nybble:16__1st bit:1__bit count:4" },
		{ ID::exp_filter_key_track, "1st nybble:28__1st bit:2__bit count:2" },
		{ ID::exp_filter_env_attack, "1st nybble:20__1st bit:1__bit count:4" },
		{ ID::exp_filter_env_decay, "1st nybble:19__1st bit:1__bit count:4" },
		{ ID::exp_filter_env_sustain, "1st nybble:18__1st bit:1__bit count:4" },
		{ ID::exp_filter_env_release, "1st nybble:17__1st bit:1__bit count:4" },
		//amp
		{ ID::exp_amp_env_attack, "1st nybble:24__1st bit:1__bit count:4" },
		{ ID::exp_amp_env_decay, "1st nybble:23__1st bit:1__bit count:4" },
		{ ID::exp_amp_env_sustain, "1st nybble:22__1st bit:1__bit count:4" },
		{ ID::exp_amp_env_release, "1st nybble:21__1st bit:1__bit count:4" },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, "1st nybble:1__1st bit:3__bit count:4" },
		{ ID::exp_p_mod_amt_osc_b, "1st nybble:3__1st bit:3__bit count:7" },
		{ ID::exp_p_mod_dest_osc_a_freq, "1st nybble:31__1st bit:1__bit count:1" },
		{ ID::exp_p_mod_dest_filter, "1st nybble:31__1st bit:2__bit count:1" },
		//lfo
		{ ID::exp_lfo_freq, "1st nybble:2__1st bit:3__bit count:4" },
		{ ID::exp_lfo_shape, "1st nybble:29__1st bit:0__bit count:1" },
		{ ID::exp_lfo_init_amt, "1st nybble:5__1st bit:2__bit count:5" },
		{ ID::exp_lfo_dest_osc_pitch, "1st nybble:29__1st bit:1__bit count:1" },
		{ ID::exp_lfo_dest_osc_pw, "1st nybble:29__1st bit:2__bit count:1" },
		{ ID::exp_lfo_dest_filter, "1st nybble:29__1st bit:3__bit count:1" },
	};

}
