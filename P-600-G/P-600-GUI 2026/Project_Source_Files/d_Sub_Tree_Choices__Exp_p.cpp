#include "d_Sub_Tree_Choices__Exp_p.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl, 
										int first_nybble_index, int first_bit_index, 
										int bit_count, int choice_count, 
										int init_choice, int ctrl_center_x,
										int ctrl_center_y, int ctrl_w, int ctrl_h, 
										String tip, ValueTree curt_choice_names,
										ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::exp_p_name, name },
			{ ID::exp_p_ctrl_type, (int)ctrl },
			{ ID::exp_p_first_nybble_index, first_nybble_index },
			{ ID::exp_p_first_bit_index, first_bit_index },
			{ ID::exp_p_bit_count, bit_count },
			{ ID::exp_p_choice_count, choice_count },
			{ ID::exp_p_init_choice, init_choice },
			{ ID::exp_p_ctrl_center_x, ctrl_center_x },
			{ ID::exp_p_ctrl_center_y, ctrl_center_y },
			{ ID::exp_p_ctrl_width, ctrl_w },
			{ ID::exp_p_ctrl_width, ctrl_h },
			{ ID::exp_p_tip, tip },
		},
		{ curt_choice_names, choice_names }
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_filter_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	tree.setProperty("choice_0", "off", nullptr);
	tree.setProperty("choice_1", "1/2", nullptr);
	tree.setProperty("choice_2", "full", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lfo_shape(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	tree.setProperty("choice_0", "square", nullptr);
	tree.setProperty("choice_1", "triangle", nullptr);
	return tree;
}
