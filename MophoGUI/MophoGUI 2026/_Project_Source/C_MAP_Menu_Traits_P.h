#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"

using namespace MISC;
using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<bool, int, int, bool>> menu_traits{
		// exposed osc
		{ ID::exp_glide_mode, { false, 1, 4, false } },
		{ ID::exp_note_priority, { false, 1, 6, false } },
		// exposed lfo
		{ ID::exp_lfo_1_shape, menu_above_1x5 },
		{ ID::exp_lfo_1_dest, menu_above_3x16 },
		{ ID::exp_lfo_2_shape, menu_above_1x5 },
		{ ID::exp_lfo_2_dest, menu_above_3x16 },
		{ ID::exp_lfo_3_shape, menu_above_1x5 },
		{ ID::exp_lfo_3_dest, menu_above_3x16 },
		{ ID::exp_lfo_4_shape, menu_above_1x5 },
		{ ID::exp_lfo_4_dest, menu_above_3x16 },
		//exposed env 3
		{ ID::exp_env_3_dest, menu_above_3x16 },
		//exposed mod
		{ ID::exp_mod_1_src, menu_below_2x12 },
		{ ID::exp_mod_1_dest, menu_below_3x16 },
		{ ID::exp_mod_2_src, menu_below_2x12 },
		{ ID::exp_mod_2_dest, menu_below_3x16 },
		{ ID::exp_mod_3_src, menu_below_2x12 },
		{ ID::exp_mod_3_dest, menu_below_3x16 },
		{ ID::exp_mod_4_src, menu_below_2x12 },
		{ ID::exp_mod_4_dest, menu_above_3x16 },
		//exposed midi cc
		{ ID::exp_mod_wheel_dest, menu_below_3x16 },
		{ ID::exp_press_dest, menu_below_3x16 },
		{ ID::exp_breath_dest, menu_below_3x16 },
		{ ID::exp_velocity_dest, menu_below_3x16 },
		{ ID::exp_pedal_dest, menu_above_3x16 },
		//exposed push it
		{ ID::exp_push_it_mode, { true, 1, 3, false } },
		//exposed clock & arp
		{ ID::exp_clock_div, { false, 1, 13, false } },
		{ ID::exp_arp_mode, { false, 1, 15, false } },
		//exposed seq
		{ ID::exp_seq_trig_mode, { false, 1, 6, false } },
		{ ID::exp_seq_track_1_dest, menu_below_3x16_to_left },
		{ ID::exp_seq_track_2_dest, menu_below_3x16_to_left },
		{ ID::exp_seq_track_3_dest, menu_below_3x16_to_left },
		{ ID::exp_seq_track_4_dest, menu_above_3x16_to_left },
		//exposed flex knob
		{ ID::exp_flex_knob_1, menu_above_5x34_to_left },
		{ ID::exp_flex_knob_2, menu_above_5x34_to_left },
		{ ID::exp_flex_knob_3, menu_above_5x34_to_left },
		{ ID::exp_flex_knob_4, menu_above_5x34_to_left },
	};

}