#include "H_00-B_Build_Tree.h"

#include "H_99-B_Misc.h"

ValueTree Base_Build_Tree::choice_names_osc_pitch(uint8 choice_count, const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (uint8 choice = 0; choice < choice_count; ++choice) {
		String name{ Int_To_Pitch_Name::convert(choice) };
		if (!curt)
			name << " (MIDI Note " + String(choice) + ")";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Base_Build_Tree::choice_names_unsigned_int(uint16 count, const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (auto choice = 0; choice < count; ++choice) {
		auto name{ (String)choice };
		tree.setProperty("choice_" + name, name, nullptr);
	}
	return tree;
}
