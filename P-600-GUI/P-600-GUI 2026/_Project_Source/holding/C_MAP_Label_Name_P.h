#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> label_name{
		//osc
		{ ID::exp_osc_a_pitch, NAME::lbl_knob },
		{ ID::exp_osc_a_pulse_w, NAME::lbl_knob },
		{ ID::exp_osc_b_pitch, NAME::lbl_knob },
		{ ID::exp_osc_b_fine, NAME::lbl_knob },
		{ ID::exp_osc_b_pulse_w, NAME::lbl_knob },
		{ ID::exp_mixer, NAME::lbl_knob },
		{ ID::exp_glide, NAME::lbl_knob },
		//filter
		{ ID::exp_filter_cutoff, NAME::lbl_knob },
		{ ID::exp_filter_reso, NAME::lbl_knob },
		{ ID::exp_filter_env_amt, NAME::lbl_knob },
		{ ID::exp_filter_env_attack, NAME::lbl_knob },
		{ ID::exp_filter_env_decay, NAME::lbl_knob },
		{ ID::exp_filter_env_sustain, NAME::lbl_knob },
		{ ID::exp_filter_env_release, NAME::lbl_knob },
		//amp
		{ ID::exp_amp_env_attack, NAME::lbl_knob },
		{ ID::exp_amp_env_decay, NAME::lbl_knob },
		{ ID::exp_amp_env_sustain, NAME::lbl_knob },
		{ ID::exp_amp_env_release, NAME::lbl_knob },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, NAME::lbl_knob },
		{ ID::exp_p_mod_amt_osc_b, NAME::lbl_knob },
		//lfo
		{ ID::exp_lfo_freq, NAME::lbl_knob },
		{ ID::exp_lfo_init_amt, NAME::lbl_knob },
	};

}
