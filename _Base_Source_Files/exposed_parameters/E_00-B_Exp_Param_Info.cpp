#include "E_00-B_Exp_Param_Info.h"

Base_Exposed_Parameter_Info::Base_Exposed_Parameter_Info(const uint8 exp_param_count) :
	tree{ ID::tree_exp_param_info },
	exp_param_count{ exp_param_count }
{}

const ValueTree Base_Exposed_Parameter_Info::param(uint8 i) const {
	return tree.getChild(i);
}

const Identifier Base_Exposed_Parameter_Info::id_for(uint8 i) const {
	if (i < exp_param_count)
		return param(i).getType();
	return Identifier{};
}

const uint8 Base_Exposed_Parameter_Info::param_num_for(uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_num];
	return uint8{ 255 };
}

const String Base_Exposed_Parameter_Info::name_for(uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::param_name].toString();
	return String{};
}

const uint8 Base_Exposed_Parameter_Info::choice_count_for(uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_choice_count];
	return uint8{ 255 };
}

const uint8 Base_Exposed_Parameter_Info::init_choice_for(uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_init_choice];
	return uint8{ 255 };
}

Point<int> Base_Exposed_Parameter_Info::ctrl_center_for(uint8 i) const {
	if (i < exp_param_count) {
		auto x = (int)param(i)[ID::param_ctrl_center_x];
		auto y = (int)param(i)[ID::param_ctrl_center_y];
		return Point<int>{ x, y };
	}
	return Point<int>{};
}

int Base_Exposed_Parameter_Info::ctrl_width_for(uint8 i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::param_ctrl_width];
	return 0;
}

const String Base_Exposed_Parameter_Info::description_for(uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::param_description].toString();
	return String{};
}

const String Base_Exposed_Parameter_Info::choice_name_for(
						uint8 i, const uint8 num, bool curt) const 
{
	String choice_name{};
	if (i < exp_param_count && num < choice_count_for(i)) {
		auto& tree_id = curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names;
		auto choices = param(i).getChildWithName(tree_id);
		choice_name = choices["choice_" + (String)num].toString();
	}
	return choice_name;
}

const StringArray Base_Exposed_Parameter_Info::choice_name_list_for(
						uint8 i, bool curt) const 
{
	StringArray list{};
	if (i < exp_param_count) {
		auto count = choice_count_for(i);
		auto& tree_id = curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names;
		auto choices = param(i).getChildWithName(tree_id);
		for (int num = 0; num < count; ++num)
			list.add(choices["choice_" + (String)num].toString());
	}
	return list;
}

const int Base_Exposed_Parameter_Info::drag_sensitivity_for(uint8 i, float scale_factor) const {
	if (i < exp_param_count) {
		auto sensitivity = (80.0f + choice_count_for(i) / 2.0f) * scale_factor;
		return roundToInt(sensitivity);
	}
	return -1;
}


