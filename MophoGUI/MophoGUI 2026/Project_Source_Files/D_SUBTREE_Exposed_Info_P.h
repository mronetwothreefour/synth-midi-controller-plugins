#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"
#include "C_ID_P.h"

using namespace ENUM;

struct Subtree_Exposed_Info_P
{
	static ValueTree build(Identifier id, String name, Ctrl_Type ctrl,
						   Knob_Display_Type display, int nrpn, int choice_count,
						   int init_choice, int ctrl_center_x, int ctrl_center_y,
						   int ctrl_w, int ctrl_h, String tip,
						   ValueTree choices_curt, ValueTree choices,
						   int red_toggle_center_x = 0, int red_toggle_center_y = 0)
	{
		ValueTree tree_ep{ id,
			{
				{ ID::exp_p_name, name },
				{ ID::exp_p_ctrl_type, (int)ctrl },
				{ ID::exp_p_knob_display_type, (int)display },
				{ ID::exp_p_nrpn, nrpn },
				{ ID::exp_p_choice_count, choice_count },
				{ ID::exp_p_init_choice, init_choice },
				{ ID::exp_p_ctrl_center_x, ctrl_center_x },
				{ ID::exp_p_ctrl_center_y, ctrl_center_y },
				{ ID::exp_p_ctrl_width, ctrl_w },
				{ ID::exp_p_ctrl_height, ctrl_h },
				{ ID::exp_p_tip, tip },
				{ ID::exp_p_red_toggle_center_x, red_toggle_center_x },
				{ ID::exp_p_red_toggle_center_y, red_toggle_center_y }
			},
			{ choices_curt, choices }
		};
		return tree_ep;
	}
};