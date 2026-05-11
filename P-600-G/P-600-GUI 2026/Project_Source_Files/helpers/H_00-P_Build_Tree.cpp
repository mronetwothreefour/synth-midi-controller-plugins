#include "H_00-P_Build_Tree.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl, 
										uint8 first_nybble_index, uint8 first_bit_index, 
										uint8 bit_count, uint8 choice_count, 
										uint8 init_choice, int ctrl_center_x,
										int ctrl_center_y, int ctrl_w, int ctrl_h, 
										String description, int choice_menu_col_count, 
										int choice_menu_col_w, int choice_menu_row_count, 
										int choice_menu_x, int choice_menu_y, 
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_first_nybble_index, first_nybble_index },
			{ ID::ep_p_first_bit_index, first_bit_index },
			{ ID::ep_p_bit_count, bit_count },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_ctrl_width, ctrl_h },
			{ ID::ep_p_description, description },
			{ ID::ep_p_choice_menu_col_count, choice_menu_col_count },
			{ ID::ep_p_choice_menu_col_width, choice_menu_col_w },
			{ ID::ep_p_choice_menu_row_count, choice_menu_row_count },
			{ ID::ep_p_choice_menu_x, choice_menu_x },
			{ ID::ep_p_choice_menu_x, choice_menu_y }
		},
		{ curt_choice_names, choice_names }
	};
	return tree_ep;
}
