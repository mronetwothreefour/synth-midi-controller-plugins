#include "D_TREE_Exposed_Info_B.h"

using namespace EXP;
Tree_Exposed_Info_B::Tree_Exposed_Info_B() :
	tree{ ID::tree_exp_param_info }
{}

const ValueTree Tree_Exposed_Info_B::param(int i) const {
	return tree.getChild(i);
}

const Identifier Tree_Exposed_Info_B::id_for(int i) const {
	if (i < exp_param_count)
		return param(i).getType();
	return {};
}

const String Tree_Exposed_Info_B::name_for(int i) const {
	if (i < exp_param_count)
		return param(i)[ID::exp_p_name].toString();
	return {};
}

const Ctrl_Type Tree_Exposed_Info_B::ctrl_type_for(const int i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::exp_p_ctrl_type] };
	return Ctrl_Type::error;
}

const Knob_Display_Type Tree_Exposed_Info_B::knob_display_type_for(const int i) const {
	if (i < exp_param_count)
		return Knob_Display_Type{ (int)param(i)[ID::exp_p_knob_display_type] };
	return Knob_Display_Type::error;
}

const int Tree_Exposed_Info_B::choice_count_for(int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_choice_count];
	return -1;
}

const int Tree_Exposed_Info_B::init_choice_for(int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_init_choice];
	return -1;
}

Point<int> Tree_Exposed_Info_B::ctrl_center_for(int i) const {
	if (i < exp_param_count) {
		auto x = (int)param(i)[ID::exp_p_ctrl_center_x];
		auto y = (int)param(i)[ID::exp_p_ctrl_center_y];
		return Point<int>{ x, y };
	}
	return {};
}

int Tree_Exposed_Info_B::ctrl_width_for(int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_ctrl_width];
	return 0;
}

int Tree_Exposed_Info_B::ctrl_height_for(int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_ctrl_height];
	return 0;
}

const String Tree_Exposed_Info_B::tip_for(int i) const {
	if (i < exp_param_count)
		return param(i)[ID::exp_p_tip].toString();
	return {};
}

const String Tree_Exposed_Info_B::choice_for(int i, const int num, bool curt) const
{
	if (i < exp_param_count && num < choice_count_for(i)) {
		auto& tree_id = curt ? ID::subtree_choices_curt : ID::subtree_choices;
		auto choices = param(i).getChildWithName(tree_id);
		return choices["choice_" + (String)num].toString();
	}
	return {};
}

const StringArray Tree_Exposed_Info_B::choices_list_for(int i, bool curt) const 
{
	StringArray list{};
	if (i < exp_param_count) {
		auto count = choice_count_for(i);
		auto& tree_id = curt ? ID::subtree_choices_curt : ID::subtree_choices;
		auto choices = param(i).getChildWithName(tree_id);
		for (int num = 0; num < count; ++num)
			list.add(choices["choice_" + (String)num].toString());
	}
	return list;
}

const int Tree_Exposed_Info_B::drag_sensitivity_for(int i, float scale_factor) const {
	if (i < exp_param_count) {
		auto sensitivity = (80.0f + choice_count_for(i) / 2.0f) * scale_factor;
		return roundToInt(sensitivity);
	}
	return -1;
}

