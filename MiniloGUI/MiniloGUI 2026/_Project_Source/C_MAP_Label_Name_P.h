#pragma once

#include <string>
#include <unordered_map>

#include "C_NAME_P.h"
#include "C_ID_Main_P.h"

namespace MAP
{

	static const std::unordered_map<std::string, std::string> label_name{
		{ ID::avp_amp_mod_by_velo_amt, NAME::lbl_knb },
		{ ID::avp_fine_tune, NAME::lbl_knb },
		{ ID::avp_flex_sli_bend_neg, NAME::lbl_knb },
		{ ID::avp_flex_sli_bend_pos, NAME::lbl_knb },
		{ ID::avp_flex_sli_range, NAME::lbl_knb },
		{ ID::avp_flex_sli_target, NAME::lbl_cbx },
		{ ID::avp_level, NAME::lbl_knb },
		{ ID::avp_microtune_scale, NAME::lbl_cbx },
		{ ID::avp_porta_time, NAME::lbl_knb },
		{ ID::avp_scale_key, NAME::lbl_knb },
		{ ID::avp_transpose, NAME::lbl_knb },

		//osc
		{ ID::exp_osc_1_pitch_fine, NAME::lbl_knb },
		{ ID::exp_osc_1_shape, NAME::lbl_knb },
		{ ID::exp_osc_2_pitch_fine, NAME::lbl_knb },
		{ ID::exp_osc_2_shape, NAME::lbl_knb },
		//osc 2 x-mod
		{ ID::exp_osc_2_xmod_depth, NAME::lbl_knb  },
		{ ID::exp_osc_2_pitch_eg_int, NAME::lbl_knb },
		//mix
		{ ID::exp_mix_osc_1, NAME::lbl_knb },
		{ ID::exp_mix_osc_2, NAME::lbl_knb },
		{ ID::exp_mix_noise, NAME::lbl_knb },
		//lpf
		{ ID::exp_lpf_freq, NAME::lbl_knb },
		{ ID::exp_lpf_reso, NAME::lbl_knb },
		{ ID::exp_lpf_eg_int, NAME::lbl_knb },
		//vca env
		{ ID::exp_vca_env_attack, NAME::lbl_knb },
		{ ID::exp_vca_env_decay, NAME::lbl_knb },
		{ ID::exp_vca_env_sustain, NAME::lbl_knb },
		{ ID::exp_vca_env_release, NAME::lbl_knb },
		//env
		{ ID::exp_env_attack, NAME::lbl_knb },
		{ ID::exp_env_decay, NAME::lbl_knb },
		{ ID::exp_env_sustain, NAME::lbl_knb },
		{ ID::exp_env_release, NAME::lbl_knb },
		//lfo
		{ ID::exp_lfo_rate, NAME::lbl_knb },
		{ ID::exp_lfo_int, NAME::lbl_knb },
		//delay
		{ ID::exp_delay_hpf_freq, NAME::lbl_knb },
		{ ID::exp_delay_time, NAME::lbl_knb },
		{ ID::exp_delay_feedback, NAME::lbl_knb },
		//voice mode depth
		{ ID::exp_voice_mode_depth, NAME::lbl_knb }
	};

}
