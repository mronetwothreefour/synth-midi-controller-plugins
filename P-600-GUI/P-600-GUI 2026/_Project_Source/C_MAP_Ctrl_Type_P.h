#pragma once

#include "C_ENUM_P.h"
#include "C_ID_Exp_P.h"

using namespace ENUM;

namespace MAP
{

	static const std::unordered_map<String, Ctrl> ctrl_type{
		//osc
		{ ID::exp_unison_track, Ctrl::switch_2_pole },
		{ ID::exp_osc_a_pitch, Ctrl::knob_osc_pitch },
		{ ID::exp_osc_a_sync, Ctrl::switch_2_pole },
		{ ID::exp_osc_a_saw, Ctrl::switch_2_pole },
		{ ID::exp_osc_a_tri, Ctrl::switch_2_pole },
		{ ID::exp_osc_a_pulse, Ctrl::switch_2_pole },
		{ ID::exp_osc_a_pulse_w, Ctrl::knob },
		{ ID::exp_osc_b_pitch, Ctrl::knob_osc_pitch },
		{ ID::exp_osc_b_fine, Ctrl::knob },
		{ ID::exp_osc_b_saw, Ctrl::switch_2_pole },
		{ ID::exp_osc_b_tri, Ctrl::switch_2_pole },
		{ ID::exp_osc_b_pulse, Ctrl::switch_2_pole },
		{ ID::exp_osc_b_pulse_w, Ctrl::knob },
		{ ID::exp_mixer, Ctrl::knob },
		{ ID::exp_glide, Ctrl::knob },
		//filter
		{ ID::exp_filter_cutoff, Ctrl::knob },
		{ ID::exp_filter_reso, Ctrl::knob },
		{ ID::exp_filter_env_amt, Ctrl::knob },
		{ ID::exp_filter_key_track, Ctrl::switch_3_pole },
		{ ID::exp_filter_env_attack, Ctrl::knob },
		{ ID::exp_filter_env_decay, Ctrl::knob },
		{ ID::exp_filter_env_sustain, Ctrl::knob },
		{ ID::exp_filter_env_release, Ctrl::knob },
		//amp
		{ ID::exp_amp_env_attack, Ctrl::knob },
		{ ID::exp_amp_env_decay, Ctrl::knob },
		{ ID::exp_amp_env_sustain, Ctrl::knob },
		{ ID::exp_amp_env_release, Ctrl::knob },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, Ctrl::knob },
		{ ID::exp_p_mod_amt_osc_b, Ctrl::knob },
		{ ID::exp_p_mod_dest_osc_a_freq, Ctrl::switch_2_pole },
		{ ID::exp_p_mod_dest_filter, Ctrl::switch_2_pole },
		//lfo
		{ ID::exp_lfo_freq, Ctrl::knob },
		{ ID::exp_lfo_shape, Ctrl::switch_2_pole },
		{ ID::exp_lfo_init_amt, Ctrl::knob },
		{ ID::exp_lfo_dest_osc_pitch, Ctrl::switch_2_pole },
		{ ID::exp_lfo_dest_osc_pw, Ctrl::switch_2_pole },
		{ ID::exp_lfo_dest_filter, Ctrl::switch_2_pole },
	};

}
