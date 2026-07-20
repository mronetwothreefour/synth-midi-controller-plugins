#include "D_SUBTREE_Choices_G.h"

#include "C_ID_G.h"
#include "D_CONVERT_Int_To_Pitch_G.h"

ValueTree Subtree_Choices_G::off_on(const bool curt) {
	ValueTree tree{ curt ? ID::subtree_choices_curt : ID::subtree_choices };
	tree.setProperty("choice_0", "off", nullptr);
	tree.setProperty("choice_1", "on", nullptr);
	return tree;
}

ValueTree Subtree_Choices_G::osc_pitch(int choice_count, const bool curt) {
	ValueTree tree{ curt ? ID::subtree_choices_curt : ID::subtree_choices };
	for (int choice = 0; choice < choice_count; ++choice) {
		String name{ Int_To_Pitch_G::convert(choice) };
		if (!curt)
			name << " (MIDI note " + (String)choice + ")";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Subtree_Choices_G::signed_7_bit_int(const bool curt) {
	ValueTree tree{ curt ? ID::subtree_choices_curt : ID::subtree_choices };
	for (int choice = 0; choice < 128; ++choice) {
		auto name{ (choice > 63 ? "+" : "") + String{ choice - 63 } };
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Subtree_Choices_G::unsigned_int(int count, const bool curt) {
	ValueTree tree{ curt ? ID::subtree_choices_curt : ID::subtree_choices };
	for (int choice = 0; choice < count; ++choice) {
		auto name{ (String)choice };
		tree.setProperty("choice_" + name, name, nullptr);
	}
	return tree;
}
