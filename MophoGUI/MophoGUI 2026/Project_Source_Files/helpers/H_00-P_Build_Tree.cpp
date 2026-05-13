#include "H_00-P_Build_Tree.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl, 
										Knob_Display_Type display, uint8 nrpn, 
										uint8 choice_count, uint8 init_choice,
										int ctrl_center_x, int ctrl_center_y, int ctrl_w, 
										int ctrl_h, String description, 
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_knob_display_type, (int)display },
			{ ID::ep_p_nrpn, nrpn },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_ctrl_height, ctrl_h },
			{ ID::ep_p_description, description },
		},
		{ curt_choice_names, choice_names }
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_bend_range(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0",  curt ? "0" : "No Bend", nullptr);;
	tree.setProperty("choice_1",  "+/-1"  + curt ? "" : " semitone", nullptr);
	tree.setProperty("choice_2",  "+/-2"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_3",  "+/-3"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_4",  "+/-4"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_5",  "+/-5"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_6",  "+/-6"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_7",  "+/-7"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_8",  "+/-8"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_9",  "+/-9"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_10", "+/-10" + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_11", "+/-11" + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_12", "+/-12" + curt ? "" : " semitones", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_glide_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "Fixed Rate", nullptr);;
	tree.setProperty("choice_1", "Fixed Rate Auto", nullptr);
	tree.setProperty("choice_2", "Fixed Time", nullptr);
	tree.setProperty("choice_3", "Fixed Time Auto", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_fine(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (auto choice = 0; choice < 101; ++choice) {
		if (curt) {
			auto name = (choice > EP::choice_count_osc_fine ? "+" : "") + String{ choice - 50 };
			tree.setProperty("choice_" + (String)choice, name, nullptr);
		}
		else {
			String name{ "" };
			if (choice < 49)
				name = String{ choice - 50 } + " cents";
			if (choice == 49)
				name = "-1 cent";
			if (choice == 50)
				name = "No Detune";
			if (choice == 51)
				name = "+1 cent";
			if (choice > 51)
				name = "+" + String{ choice - 50 } + " cents";
			tree.setProperty("choice_" + (String)choice, name, nullptr);
		}
	}
	return tree;
}

ValueTree Build_Tree::choice_names_osc_shape(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "Oscillator Off", nullptr);
	tree.setProperty("choice_1", curt ? "SAW" : "Sawtooth", nullptr);
	tree.setProperty("choice_2", curt ? "TRI" : "Triangle", nullptr);
	tree.setProperty("choice_3", curt ? "S/T" : "Sawtooth/Triangle Mix", nullptr);
	for (int choice = 4; choice < EP::choice_count_osc_shape; ++choice) {
		if (choice == 54)
			tree.setProperty("choice_54", curt ? "SQR" : "Square (Pulse: Width 50)", nullptr);
		else {
			auto pw = String{ choice - 4 };
			tree.setProperty("choice_" + (String)choice, curt ? "PW " + pw : 
				"Pulse: Width " + pw, nullptr);
		}
	}
	return tree;
}
