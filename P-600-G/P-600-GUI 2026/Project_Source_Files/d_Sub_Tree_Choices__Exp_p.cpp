#include "d_Sub_Tree_Choices__Exp_p.h"

ValueTree Sub_Tree_Choices_Exposed::filter_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	tree.setProperty("choice_0", "off", nullptr);
	tree.setProperty("choice_1", "1/2", nullptr);
	tree.setProperty("choice_2", "full", nullptr);
	return tree;
}

ValueTree Sub_Tree_Choices_Exposed::lfo_shape(const bool curt) {
	ValueTree tree{ curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices };
	tree.setProperty("choice_0", "square", nullptr);
	tree.setProperty("choice_1", "triangle", nullptr);
	return tree;
}
