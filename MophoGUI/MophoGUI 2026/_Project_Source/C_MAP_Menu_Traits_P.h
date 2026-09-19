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

	static const unordered_map<string, tuple<bool, int, int>> menu_traits{
		// exposed osc
		{ ID::exp_glide_mode, { false, 1, 4 } },
		{ ID::exp_note_priority, { false, 1, 6 } },
		// exposed lfo
		{ ID::exp_lfo_1_shape, menu_traits_true_1_5 },
		{ ID::exp_lfo_1_dest, menu_traits_true_5_10 },
		{ ID::exp_lfo_2_shape, menu_traits_true_1_5 },
		{ ID::exp_lfo_2_dest, menu_traits_true_5_10 },
		{ ID::exp_lfo_3_shape, menu_traits_true_1_5 },
		{ ID::exp_lfo_3_dest, menu_traits_true_5_10 },
		{ ID::exp_lfo_4_shape, menu_traits_true_1_5 },
		{ ID::exp_lfo_4_dest, menu_traits_true_5_10 },
		//exposed env 3
		{ ID::exp_env_3_dest, menu_traits_true_5_10 },
		//exposed mod
		{ ID::exp_mod_1_src, menu_traits_false_2_12 },
		{ ID::exp_mod_1_dest, menu_traits_false_5_10 },
		{ ID::exp_mod_2_src, menu_traits_false_2_12 },
		{ ID::exp_mod_2_dest, menu_traits_false_5_10 },
		{ ID::exp_mod_3_src, menu_traits_false_2_12 },
		{ ID::exp_mod_3_dest, menu_traits_false_5_10 },
		{ ID::exp_mod_4_src, menu_traits_false_2_12 },
		{ ID::exp_mod_4_dest, menu_traits_false_5_10 },
		//exposed midi cc
		{ ID::exp_mod_wheel_dest, menu_traits_false_5_10 },
		{ ID::exp_press_dest, menu_traits_false_5_10 },
		{ ID::exp_breath_dest, menu_traits_false_5_10 },
		{ ID::exp_velocity_dest, menu_traits_false_5_10 },
		{ ID::exp_pedal_dest, menu_traits_false_5_10 },
		//exposed push it
		{ ID::exp_push_it_mode, { true, 1, 3 } },
		//exposed clock & arp
		{ ID::exp_clock_div, { false, 1, 13 } },
		{ ID::exp_arp_mode, { false, 1, 15 } },
		//exposed seq
		{ ID::exp_seq_trig_mode, { false, 1, 6 } },
		{ ID::exp_seq_track_1_dest, menu_traits_false_5_10 },
		{ ID::exp_seq_track_2_dest, menu_traits_false_5_10 },
		{ ID::exp_seq_track_3_dest, menu_traits_false_5_10 },
		{ ID::exp_seq_track_4_dest, menu_traits_false_5_10 },
		//exposed flex knob
		{ ID::exp_flex_knob_1, menu_traits_true_10_17 },
		{ ID::exp_flex_knob_2, menu_traits_true_10_17 },
		{ ID::exp_flex_knob_3, menu_traits_true_10_17 },
		{ ID::exp_flex_knob_4, menu_traits_true_10_17 },
	};

}