#include "d_Sub_Tree_Choices_b.h"

#include "d_Convert__Int_To_Pitch_b.h"

ValueTree Sub_Tree_Choices_Base::off_on(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	tree.setProperty("choice_0", "off", nullptr);
	tree.setProperty("choice_1", "on", nullptr);
	return tree;
}

ValueTree Sub_Tree_Choices_Base::osc_pitch(uint8 choice_count, const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	for (uint8 choice = 0; choice < choice_count; ++choice) {
		String name{ Int_To_Pitch::convert(choice) };
		if (!curt)
			name << " (MIDI note " + (String)choice + ")";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Sub_Tree_Choices_Base::signed_7_bit_int(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	for (int choice = 0; choice < 128; ++choice) {
		auto name{ (choice > 63 ? "+" : "") + String{ choice - 63 } };
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Sub_Tree_Choices_Base::unsigned_int(uint16 count, const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	for (int choice = 0; choice < count; ++choice) {
		auto name{ (String)choice };
		tree.setProperty("choice_" + name, name, nullptr);
	}
	return tree;
}
