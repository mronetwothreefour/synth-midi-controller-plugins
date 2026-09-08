#pragma once

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<String, String> ctrl_name{
		//osc
		{ ID::exp_unison_track, NAME::sli_switch_2_pole },
		{ ID::exp_osc_a_pitch, NAME::sli_knob },
		{ ID::exp_osc_a_sync, NAME::sli_switch_2_pole },
		{ ID::exp_osc_a_saw, NAME::sli_switch_2_pole },
		{ ID::exp_osc_a_tri, NAME::sli_switch_2_pole },
		{ ID::exp_osc_a_pulse, NAME::sli_switch_2_pole },
		{ ID::exp_osc_a_pulse_w, NAME::sli_knob },
		{ ID::exp_osc_b_pitch, NAME::sli_knob },
		{ ID::exp_osc_b_fine, NAME::sli_knob },
		{ ID::exp_osc_b_saw, NAME::sli_switch_2_pole },
		{ ID::exp_osc_b_tri, NAME::sli_switch_2_pole },
		{ ID::exp_osc_b_pulse, NAME::sli_switch_2_pole },
		{ ID::exp_osc_b_pulse_w, NAME::sli_knob },
		{ ID::exp_mixer, NAME::sli_knob },
		{ ID::exp_glide, NAME::sli_knob },
		//filter
		{ ID::exp_filter_cutoff, NAME::sli_knob },
		{ ID::exp_filter_reso, NAME::sli_knob },
		{ ID::exp_filter_env_amt, NAME::sli_knob },
		{ ID::exp_filter_key_track, NAME::sli_switch_3_pole },
		{ ID::exp_filter_env_attack, NAME::sli_knob },
		{ ID::exp_filter_env_decay, NAME::sli_knob },
		{ ID::exp_filter_env_sustain, NAME::sli_knob },
		{ ID::exp_filter_env_release, NAME::sli_knob },
		//amp
		{ ID::exp_amp_env_attack, NAME::sli_knob },
		{ ID::exp_amp_env_decay, NAME::sli_knob },
		{ ID::exp_amp_env_sustain, NAME::sli_knob },
		{ ID::exp_amp_env_release, NAME::sli_knob },
		//poly-mod
		{ ID::exp_p_mod_amt_filter_env, NAME::sli_knob },
		{ ID::exp_p_mod_amt_osc_b, NAME::sli_knob },
		{ ID::exp_p_mod_dest_osc_a_freq, NAME::sli_switch_2_pole },
		{ ID::exp_p_mod_dest_filter, NAME::sli_switch_2_pole },
		//lfo
		{ ID::exp_lfo_freq, NAME::sli_knob },
		{ ID::exp_lfo_shape, NAME::sli_switch_2_pole },
		{ ID::exp_lfo_init_amt, NAME::sli_knob },
		{ ID::exp_lfo_dest_osc_pitch, NAME::sli_switch_2_pole },
		{ ID::exp_lfo_dest_osc_pw, NAME::sli_switch_2_pole },
		{ ID::exp_lfo_dest_filter, NAME::sli_switch_2_pole },
	};

}
