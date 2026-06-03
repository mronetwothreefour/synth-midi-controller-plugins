#include "D_TREE_Exposed_Info_B.h"

Tree_Exposed_Info_B::Tree_Exposed_Info_B(const uint8 exp_param_count) :
	tree{ ID::tree_exp_param_info },
	exp_param_count{ exp_param_count }
{}

const ValueTree Tree_Exposed_Info_B::param(uint8 i) const {
	return tree.getChild(i);
}

const Identifier Tree_Exposed_Info_B::id_for(uint8 i) const {
	if (i < exp_param_count)
		return param(i).getType();
	return {};
}

const String Tree_Exposed_Info_B::name_for(uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::exp_p_name].toString();
	return {};
}

const int Tree_Exposed_Info_B::choice_count_for(uint8 i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_choice_count];
	return -1;
}

const int Tree_Exposed_Info_B::init_choice_for(uint8 i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_init_choice];
	return -1;
}

Point<int> Tree_Exposed_Info_B::ctrl_center_for(uint8 i) const {
	if (i < exp_param_count) {
		auto x = (int)param(i)[ID::exp_p_ctrl_center_x];
		auto y = (int)param(i)[ID::exp_p_ctrl_center_y];
		return Point<int>{ x, y };
	}
	return {};
}

int Tree_Exposed_Info_B::ctrl_width_for(uint8 i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_ctrl_width];
	return 0;
}

int Tree_Exposed_Info_B::ctrl_height_for(uint8 i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_ctrl_height];
	return 0;
}

const String Tree_Exposed_Info_B::tip_for(uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::exp_p_tip].toString();
	return {};
}

const String Tree_Exposed_Info_B::choice_for(
						uint8 i, const int num, bool curt) const
{
	if (i < exp_param_count && num < choice_count_for(i)) {
		auto& tree_id = curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices;
		auto choices = param(i).getChildWithName(tree_id);
		return choices["choice_" + (String)num].toString();
	}
	return {};
}

const StringArray Tree_Exposed_Info_B::choices_list_for(
						uint8 i, bool curt) const 
{
	StringArray list{};
	if (i < exp_param_count) {
		auto count = choice_count_for(i);
		auto& tree_id = curt ? ID::sub_tree_choices_curt : ID::sub_tree_choices;
		auto choices = param(i).getChildWithName(tree_id);
		for (int num = 0; num < count; ++num)
			list.add(choices["choice_" + (String)num].toString());
	}
	return list;
}

const int Tree_Exposed_Info_B::drag_sensitivity_for(uint8 i, float scale_factor) const {
	if (i < exp_param_count) {
		auto sensitivity = (80.0f + choice_count_for(i) / 2.0f) * scale_factor;
		return roundToInt(sensitivity);
	}
	return -1;
}

