#pragma once

#include <JuceHeader.h>

#include "c_ENUM_p.h"
#include "c_ID_p.h"

using namespace ENUM;

struct Subtree_Exposed_Info_P
{
public: static ValueTree build(Identifier id, String name, Ctrl_Type ctrl,
							   Knob_Display_Type display, int cc_num,
							   int choice_count, int init_choice, 
							   int ctrl_center_x, int ctrl_center_y, int ctrl_w, 
							   int ctrl_h,String tip, ValueTree bit_locations,
							   ValueTree choices_curt, ValueTree choices)
		{
			ValueTree tree{ id,
				{
					{ ID::exp_p_name, name },
					{ ID::exp_p_ctrl_type, (int)ctrl },
					{ ID::exp_p_knob_display_type, (int)display },
					{ ID::exp_p_cc_num, cc_num },
					{ ID::exp_p_choice_count, choice_count },
					{ ID::exp_p_init_choice, init_choice },
					{ ID::exp_p_ctrl_center_x, ctrl_center_x },
					{ ID::exp_p_ctrl_center_y, ctrl_center_y },
					{ ID::exp_p_ctrl_width, ctrl_w },
					{ ID::exp_p_ctrl_height, ctrl_h },
					{ ID::exp_p_tip, tip },
				},
				{ bit_locations, choices_curt, choices }
			};
			return tree;
		}
};
