#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"
#include "C_ID_P.h"

using namespace ENUM;

struct Subtree_Exposed_Info_P
{
public: static ValueTree build(Exp_Param id, String name, Ctrl_Type ctrl,
							   Slider_Display_Type display, int cc_num,
							   int choice_count, int init_choice, 
							   int ctrl_cntr_x, int ctrl_cntr_y, int ctrl_w, 
							   int ctrl_h,String tip, ValueTree bit_locations,
							   ValueTree choices_curt, ValueTree choices)
		{
			ValueTree tree{ ID::subtree_exp_param_ + String{ id },
				{
					{ ID::exp_p_id, (int)id },
					{ ID::exp_p_name, name },
					{ ID::exp_p_ctrl_type, (int)ctrl },
					{ ID::exp_p_sli_disp_type, (int)display },
					{ ID::exp_p_cc_num, cc_num },
					{ ID::exp_p_choice_count, choice_count },
					{ ID::exp_p_init_choice, init_choice },
					{ ID::exp_p_ctrl_cntr_x, ctrl_cntr_x },
					{ ID::exp_p_ctrl_cntr_y, ctrl_cntr_y },
					{ ID::exp_p_ctrl_w, ctrl_w },
					{ ID::exp_p_ctrl_h, ctrl_h },
					{ ID::exp_p_tip, tip },
				},
				{ bit_locations, choices_curt, choices }
			};
			return tree;
		}
};
