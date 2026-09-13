#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_NAME_P.h"

using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<bool, int, int>> menu_traits{
		//exposed osc
		{ ID::exp_osc_1_type, { false, 1, 4 } },
		{ ID::exp_osc_1_sync, { false, 1, 4 } },
		{ ID::exp_osc_1_key_click, { false, 1, 2 } },
		{ ID::exp_osc_1_key_track, { false, 1, 2 } },
		{ ID::exp_osc_1_lever_ctrl, { false, 1, 4 } },
		{ ID::exp_osc_1_type, { false, 1, 5 } },
		{ ID::exp_osc_2_key_click, { false, 1, 2 } },
		{ ID::exp_osc_2_key_track, { false, 1, 3 } },
		{ ID::exp_osc_2_lever_ctrl, { false, 1, 4 } },
		//exposed vcf
		{ ID::exp_vcf_lever_ctrl, { false, 1, 4 } },
		{ ID::exp_vcf_key_track, { false, 1, 3 } },
		//exposed porta & keyboard mode
		{ ID::exp_porta_mode, { false, 1, 3 } },
		{ ID::exp_porta_legato, { false, 1, 2 } },
		{ ID::exp_keyboard_mode, { false, 1, 4 } },
		//exposed lfo
		{ ID::exp_lfo_1_wave_type, { false, 1, 7 } },
		{ ID::exp_lfo_1_samp_source, { false, 3, 7 } },
		{ ID::exp_lfo_1_trig_mode, { false, 1, 4 } },
		{ ID::exp_lfo_1_lag, { false, 1, 2 } },
		{ ID::exp_lfo_2_wave_type, { false, 1, 7 } },
		{ ID::exp_lfo_2_samp_source, { false, 3, 7 } },
		{ ID::exp_lfo_2_trig_mode, { false, 1, 4 } },
		{ ID::exp_lfo_2_lag, { false, 1, 2 } },
		//exposed ramp
		{ ID::exp_ramp_1_trig, { false, 1, 4 } },
		{ ID::exp_ramp_2_trig, { false, 1, 4 } },
		//exposed tracking
		{ ID::exp_track_input, { false, 3, 7 } },
		//exposed env
		{ ID::exp_env_1_trig_mode, { true, 1, 8 } },
		{ ID::exp_env_1_mode, { true, 1, 4 } },
		{ ID::exp_env_1_lfo_1_trig, { true, 1, 3 } },
		{ ID::exp_env_2_trig_mode, { true, 1, 8 } },
		{ ID::exp_env_2_mode, { true, 1, 4 } },
		{ ID::exp_env_2_lfo_1_trig, { true, 1, 3 } },
		{ ID::exp_env_3_trig_mode, { true, 1, 8 } },
		{ ID::exp_env_3_mode, { true, 1, 4 } },
		{ ID::exp_env_3_lfo_1_trig, { true, 1, 3 } },

		{ ID::mmod_0_src, { false, 3, 7 } },
		{ ID::mmod_0_dst, { false, 3, 11 } },
		{ ID::mmod_1_src, { false, 3, 7 } },
		{ ID::mmod_1_dst, { false, 3, 11 } },
		{ ID::mmod_2_src, { false, 3, 7 } },
		{ ID::mmod_2_dst, { false, 3, 11 } },
		{ ID::mmod_3_src, { false, 3, 7 } },
		{ ID::mmod_3_dst, { false, 3, 11 } },
		{ ID::mmod_4_src, { false, 3, 7 } },
		{ ID::mmod_4_dst, { false, 3, 11 } },
		{ ID::mmod_5_src, { false, 3, 7 } },
		{ ID::mmod_5_dst, { false, 3, 11 } },
		{ ID::mmod_6_src, { false, 3, 7 } },
		{ ID::mmod_6_dst, { false, 3, 11 } },
		{ ID::mmod_7_src, { false, 3, 7 } },
		{ ID::mmod_7_dst, { false, 3, 11 } },
		{ ID::mmod_8_src, { false, 3, 7 } },
		{ ID::mmod_8_dst, { false, 3, 11 } },
		{ ID::mmod_9_src, { false, 3, 7 } },
		{ ID::mmod_9_dst, { false, 3, 11 } },
	};

}