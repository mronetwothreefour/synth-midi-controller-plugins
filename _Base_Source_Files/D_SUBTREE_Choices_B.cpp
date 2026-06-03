#include "D_SUBTREE_Choices_B.h"

#include "D_CONVERT_Int_To_Pitch_B.h"

ValueTree Subtree_Choices_B::off_on(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	tree.setProperty("choice_0", "off", nullptr);
	tree.setProperty("choice_1", "on", nullptr);
	return tree;
}

ValueTree Subtree_Choices_B::osc_pitch(uint8 choice_count, const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	for (uint8 choice = 0; choice < choice_count; ++choice) {
		String name{ Int_To_Pitch::convert(choice) };
		if (!curt)
			name << " (MIDI note " + (String)choice + ")";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Subtree_Choices_B::signed_7_bit_int(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	for (int choice = 0; choice < 128; ++choice) {
		auto name{ (choice > 63 ? "+" : "") + String{ choice - 63 } };
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Subtree_Choices_B::unsigned_int(uint16 count, const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	for (uint16 choice = 0; choice < count; ++choice) {
		auto name{ (String)choice };
		tree.setProperty("choice_" + name, name, nullptr);
	}
	return tree;
}
