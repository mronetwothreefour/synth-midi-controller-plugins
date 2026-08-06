#include "D_SUBTREE_Exposed_Info_P.h"

#include "C_ID_P.h"
#include "C_XYWH_P.h"

ValueTree Subtree_Exposed_Info_P::build(Exp_Param id, int number, String name,
									    Ctrl_Type ctrl, int byte_index, Range_Type range,
									    Slider_Display_Type display, int choice_count,
									    int init_choice, int ctrl_cntr_x, int ctrl_cntr_y,
									    int ctrl_w, String tip, ValueTree choices_curt,
									    ValueTree choices)
{
	ValueTree tree{ 
		String{ id },
		{
			{ ID::exp_p_number, number },
			{ ID::exp_p_name, name },
			{ ID::exp_p_ctrl_type, (int)ctrl },
			{ ID::exp_p_byte_index, byte_index },
			{ ID::exp_p_range_type, (int)range },
			{ ID::exp_p_sli_disp_type, (int)display },
			{ ID::exp_p_choice_count, choice_count },
			{ ID::exp_p_init_choice, init_choice },
			{ ID::exp_p_ctrl_cntr_x, ctrl_cntr_x },
			{ ID::exp_p_ctrl_cntr_y, ctrl_cntr_y },
			{ ID::exp_p_ctrl_w, ctrl_w },
			{ ID::exp_p_ctrl_h, XYWH::ctrl_h },
			{ ID::exp_p_tip, tip },
		},
		{ choices_curt, choices }
	};
	return tree;
}
