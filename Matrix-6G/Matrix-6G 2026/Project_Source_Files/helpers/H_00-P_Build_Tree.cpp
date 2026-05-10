#include "H_00-P_Build_Tree.h"

#include "H_99-B_Misc.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, uint8 number, String name, 
										Ctrl_Type ctrl, uint8 byte_index, Range_Type range, 
										Slider_Display_Type display, uint8 choice_count, 
										uint8 init_choice, int ctrl_center_x, 
										int ctrl_center_y, int ctrl_w, String description, 
										int choice_menu_col_count, int choice_menu_col_w, 
										int choice_menu_row_count, int choice_menu_first_row, 
										int choice_menu_x, int choice_menu_y, 
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id, 
		{
			{ ID::ep_p_number, number },
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_byte_index, byte_index },
			{ ID::ep_p_range_type, (int)range },
			{ ID::ep_p_slider_display_type, (int)display },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_description, description },
			{ ID::ep_p_choice_menu_col_count, choice_menu_col_count },
			{ ID::ep_p_choice_menu_col_width, choice_menu_col_w },
			{ ID::ep_p_choice_menu_row_count, choice_menu_row_count },
			{ ID::ep_p_choice_menu_first_row, choice_menu_first_row },
			{ ID::ep_p_choice_menu_x, choice_menu_x },
			{ ID::ep_p_choice_menu_x, choice_menu_y }
		}, 
		{ curt_choice_names, choice_names } 
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_osc_pitch(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (auto choice = (uint8)0; choice < EP::choice_count_osc_pitch; ++choice) {
		String name{ Int_To_Pitch_Name::convert(choice) };
		if (!curt)
			name << " (MIDI Note " + String(choice) + ")";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}
