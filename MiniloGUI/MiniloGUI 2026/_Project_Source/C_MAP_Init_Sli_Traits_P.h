#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_Misc_P.h"

using namespace MISC;
using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<bool, int, int, bool, int>> init_slider_traits{
		{ ID::avp_amp_mod_by_velo_amt, init_sli_traits_u_7_bit },
		{ ID::avp_fine_tune, { false, 5, 10, false, 50 } },
		{ ID::avp_flex_sli_bend_neg, init_sli_traits_flex_sli_bend },
		{ ID::avp_flex_sli_bend_pos, init_sli_traits_flex_sli_bend },
		{ ID::avp_flex_sli_range, { false, 5, 10, false, 100 } },
		{ ID::avp_level, { false, 5, 10, false, 25 } },
		{ ID::avp_porta_time, { false, 5, 10, false, -1 } },
		{ ID::avp_scale_key, { false, 12, 12, false, 0 } },
		{ ID::avp_transpose, { false, 12, 12, false, 12 } },

		{ ID::exp_osc_1_pitch_fine, init_sli_traits_osc_pitch_fine },
		{ ID::exp_osc_1_shape, init_sli_traits_u_10_bit },
		{ ID::exp_osc_2_pitch_fine, init_sli_traits_osc_pitch_fine },
		{ ID::exp_osc_2_shape, init_sli_traits_u_10_bit },
		{ ID::exp_osc_2_xmod_depth, init_sli_traits_u_10_bit },
		{ ID::exp_osc_2_pitch_eg_int, { true, 25, 100, true, 0 } },
		{ ID::exp_mix_osc_1, init_sli_traits_u_10_bit },
		{ ID::exp_mix_osc_2, init_sli_traits_u_10_bit },
		{ ID::exp_mix_noise, init_sli_traits_u_10_bit },
		{ ID::exp_lpf_freq, init_sli_traits_u_10_bit },
		{ ID::exp_lpf_reso, init_sli_traits_u_10_bit },
		{ ID::exp_lpf_eg_int, { true, 5, 10, false, 0 } },
		{ ID::exp_vca_env_attack, init_sli_traits_u_10_bit },
		{ ID::exp_vca_env_decay, init_sli_traits_u_10_bit },
		{ ID::exp_vca_env_sustain, init_sli_traits_u_10_bit },
		{ ID::exp_vca_env_release, init_sli_traits_u_10_bit },
		{ ID::exp_env_attack, init_sli_traits_u_10_bit },
		{ ID::exp_env_decay, init_sli_traits_u_10_bit },
		{ ID::exp_env_sustain, init_sli_traits_u_10_bit },
		{ ID::exp_env_release, init_sli_traits_u_10_bit },
		{ ID::exp_lfo_int, init_sli_traits_u_10_bit },
		{ ID::exp_delay_hpf_freq, init_sli_traits_u_10_bit },
		{ ID::exp_delay_time, init_sli_traits_u_10_bit },
		{ ID::exp_delay_feedback, init_sli_traits_u_10_bit },
	};

}