#include "D_SUBTREE_Choices_Exp_P.h"

ValueTree Subtree_Choices_Exp_P::filter_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::subtree_choices_curt : ID::subtree_choices };
	tree.setProperty("choice_0", "off", nullptr);
	tree.setProperty("choice_1", "1/2", nullptr);
	tree.setProperty("choice_2", "full", nullptr);
	return tree;
}

ValueTree Subtree_Choices_Exp_P::lfo_shape(const bool curt) {
	ValueTree tree{ curt ? ID::subtree_choices_curt : ID::subtree_choices };
	tree.setProperty("choice_0", "square", nullptr);
	tree.setProperty("choice_1", "triangle", nullptr);
	return tree;
}
