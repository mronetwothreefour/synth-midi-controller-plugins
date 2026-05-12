#include "H_00-P_Build_Tree.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, uint8 number, String name, 
										Ctrl_Type ctrl, uint8 byte_index, Range_Type range, 
										Slider_Display_Type display, uint8 choice_count, 
										uint8 init_choice, int ctrl_center_x, 
										int ctrl_center_y, int ctrl_w, String description, 
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
		}, 
		{ curt_choice_names, choice_names } 
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_off_on_matrix(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "Off", nullptr);
	tree.setProperty("choice_1", curt ? "ON" : "On", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_1_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "KEYBD" : "Normal Key Tracking", nullptr);
	tree.setProperty("choice_1", curt ? "PORTA" : "Key Tracking With Portamento", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_2_and_vcf_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "Key Tracking Is Off", nullptr);
	tree.setProperty("choice_1", curt ? "PORTA" : "Key Tracking With Portamento", nullptr);
	tree.setProperty("choice_2", curt ? "KEYBD" : "Normal Key Tracking", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_lever_control(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "Off", nullptr);
	tree.setProperty("choice_1", curt ? "BEND" : "Pitch Bend By Lever 1", nullptr);
	tree.setProperty("choice_2", curt ? "VIB" : "Vibrato By Lever 2", nullptr);
	tree.setProperty("choice_3", curt ? "BOTH" : "Modulated By Both Levers", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_type(int o, const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "Off", nullptr);
	tree.setProperty("choice_1", curt ? "PULSE" : "Pulse", nullptr);
	tree.setProperty("choice_2", curt ? "WAVE" : "Wave (Saw/Triangle)", nullptr);
	tree.setProperty("choice_3", curt ? "BOTH" : "Both", nullptr);
	if (o == 2)
		tree.setProperty("choice_4", curt ? "NOISE" : "Noise", nullptr);
	return tree;
}

