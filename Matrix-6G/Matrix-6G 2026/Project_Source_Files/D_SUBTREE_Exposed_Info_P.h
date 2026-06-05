#pragma once

#include <JuceHeader.h>

#include "c_ENUM_p.h"
#include "c_ID_p.h"

using namespace ENUM;

struct Subtree_Exposed_Info_P
{
	static ValueTree build(Identifier id, int number, String name, 
						   Ctrl_Type ctrl, int byte_index, Range_Type range,
						   Slider_Display_Type display, int choice_count,
						   int init_choice, int ctrl_center_x, int ctrl_center_y,
						   int ctrl_w, String tip, 
						   ValueTree choices_curt,ValueTree choices)
	{
		ValueTree tree{ id,
			{
				{ ID::exp_p_number, number },
				{ ID::exp_p_name, name },
				{ ID::exp_p_ctrl_type, (int)ctrl },
				{ ID::exp_p_byte_index, byte_index },
				{ ID::exp_p_range_type, (int)range },
				{ ID::exp_p_slider_display_type, (int)display },
				{ ID::exp_p_choice_count, choice_count },
				{ ID::exp_p_init_choice, init_choice },
				{ ID::exp_p_ctrl_center_x, ctrl_center_x },
				{ ID::exp_p_ctrl_center_y, ctrl_center_y },
				{ ID::exp_p_ctrl_width, ctrl_w },
				{ ID::exp_p_tip, tip },
			},
			{ choices_curt, choices }
		};
		return tree;
	}
};