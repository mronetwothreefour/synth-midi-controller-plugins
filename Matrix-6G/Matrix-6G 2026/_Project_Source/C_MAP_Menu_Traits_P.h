#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_MISC_P.h"

using namespace MISC;
using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<bool, int, int>> menu_traits{
		//exposed osc
		{ ID::exp_osc_1_type, menu_below_1x4 },
		{ ID::exp_osc_1_sync, menu_below_1x4 },
		{ ID::exp_osc_1_key_click, menu_below_1x2 },
		{ ID::exp_osc_1_key_track, menu_below_1x2 },
		{ ID::exp_osc_1_lever_ctrl, menu_below_1x4 },
		{ ID::exp_osc_2_type, { false, 1, 5 } },
		{ ID::exp_osc_2_key_click, menu_below_1x2 },
		{ ID::exp_osc_2_key_track, menu_below1x3 },
		{ ID::exp_osc_2_lever_ctrl, menu_below_1x4 },
		//exposed vcf
		{ ID::exp_vcf_lever_ctrl, menu_below_1x4 },
		{ ID::exp_vcf_key_track, menu_below1x3 },
		//exposed porta & keyboard mode
		{ ID::exp_porta_mode, menu_below1x3 },
		{ ID::exp_porta_legato, menu_below_1x2 },
		{ ID::exp_keyboard_mode, menu_below_1x4 },
		//exposed lfo
		{ ID::exp_lfo_1_wave_type, menu_below_1x7 },
		{ ID::exp_lfo_1_samp_source, menu_below_3x7 },
		{ ID::exp_lfo_1_trig_mode, menu_below_1x4 },
		{ ID::exp_lfo_1_lag, menu_below_1x2 },
		{ ID::exp_lfo_2_wave_type, menu_below_1x7 },
		{ ID::exp_lfo_2_samp_source, menu_below_3x7 },
		{ ID::exp_lfo_2_trig_mode, menu_below_1x4 },
		{ ID::exp_lfo_2_lag, menu_below_1x2 },
		//exposed ramp
		{ ID::exp_ramp_1_trig, menu_below_1x4 },
		{ ID::exp_ramp_2_trig, menu_below_1x4 },
		//exposed tracking
		{ ID::exp_track_input, menu_below_3x7 },
		//exposed env
		{ ID::exp_env_1_trig_mode, menu_above_1x8 },
		{ ID::exp_env_1_mode, menu_above_1x4 },
		{ ID::exp_env_1_lfo_1_trig, menu_above_1x3 },
		{ ID::exp_env_2_trig_mode, menu_above_1x8 },
		{ ID::exp_env_2_mode, menu_above_1x4 },
		{ ID::exp_env_2_lfo_1_trig, menu_above_1x3 },
		{ ID::exp_env_3_trig_mode, menu_above_1x8 },
		{ ID::exp_env_3_mode, menu_above_1x4 },
		{ ID::exp_env_3_lfo_1_trig, menu_above_1x3 },

		{ ID::mmod_0_src, menu_below_3x7 },
		{ ID::mmod_0_dst, menu_below_3x11 },
		{ ID::mmod_1_src, menu_below_3x7 },
		{ ID::mmod_1_dst, menu_below_3x11 },
		{ ID::mmod_2_src, menu_below_3x7 },
		{ ID::mmod_2_dst, menu_below_3x11 },
		{ ID::mmod_3_src, menu_below_3x7 },
		{ ID::mmod_3_dst, menu_below_3x11 },
		{ ID::mmod_4_src, menu_below_3x7 },
		{ ID::mmod_4_dst, menu_below_3x11 },
		{ ID::mmod_5_src, menu_below_3x7 },
		{ ID::mmod_5_dst, menu_below_3x11 },
		{ ID::mmod_6_src, menu_below_3x7 },
		{ ID::mmod_6_dst, menu_below_3x11 },
		{ ID::mmod_7_src, menu_below_3x7 },
		{ ID::mmod_7_dst, menu_below_3x11 },
		{ ID::mmod_8_src, menu_below_3x7 },
		{ ID::mmod_8_dst, menu_below_3x11 },
		{ ID::mmod_9_src, menu_below_3x7 },
		{ ID::mmod_9_dst, menu_below_3x11 },
	};

}