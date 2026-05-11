#include "H_00-P_Build_Tree.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
										Knob_Display_Type display, uint8 cc_num, 
										uint16 choice_count, uint16 init_choice,
										int ctrl_center_x, int ctrl_center_y, int ctrl_w,
										int ctrl_h, String description, ValueTree bit_locations,
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_knob_display_type, (int)display },
			{ ID::ep_p_cc_num, cc_num },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_ctrl_height, ctrl_h },
			{ ID::ep_p_description, description },
		},
		{ bit_locations, curt_choice_names, choice_names }
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_osc_pitch_fine(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (int choice = 0; choice < EP::choice_count_osc_pitch_fine; ++choice) {
		auto name{ (choice > 1200 ? "+" : "") + String{ choice - 1200 } };
		name += !curt ? " cents" : "";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}
