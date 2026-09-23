#pragma once
#pragma once

#include <string>
#include <unordered_map>

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<std::string, std::string> label_name{
		//osc
		{ ID::exp_osc_a_pitch, NAME::lbl_knb },
		{ ID::exp_osc_a_pulse_w, NAME::lbl_knb },
		{ ID::exp_osc_b_pitch, NAME::lbl_knb },
		{ ID::exp_osc_b_fine, NAME::lbl_knb },
		{ ID::exp_osc_b_pulse_w, NAME::lbl_knb },
		{ ID::exp_mixer, NAME::lbl_knb },
		{ ID::exp_glide, NAME::lbl_knb },
		//filter
		{ ID::exp_filter_cutoff, NAME::lbl_knb },
		{ ID::exp_filter_reso, NAME::lbl_knb },
		{ ID::exp_filter_env_amt, NAME::lbl_knb },
		{ ID::exp_filter_env_attack, NAME::lbl_knb },
		{ ID::exp_filter_env_decay, NAME::lbl_knb },
		{ ID::exp_filter_env_sustain, NAME::lbl_knb },
		{ ID::exp_filter_env_release, NAME::lbl_knb },
		//amp
		{ ID::exp_amp_env_attack, NAME::lbl_knb },
		{ ID::exp_amp_env_decay, NAME::lbl_knb },
		{ ID::exp_amp_env_sustain, NAME::lbl_knb },
		{ ID::exp_amp_env_release, NAME::lbl_knb },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, NAME::lbl_knb },
		{ ID::exp_p_mod_amt_osc_b, NAME::lbl_knb },
		//lfo
		{ ID::exp_lfo_freq, NAME::lbl_knb },
		{ ID::exp_lfo_init_amt, NAME::lbl_knb },
	};

}
