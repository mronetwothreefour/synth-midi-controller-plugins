#include "EP _0_Exp_Param_Info_Base.h"

Exposed_Parameter_Info_Base::Exposed_Parameter_Info_Base(const uint8 exp_param_count) :
	tree{ ID::tree_exp_param_info },
	exp_param_count{ exp_param_count }
{}

const ValueTree Exposed_Parameter_Info_Base::param(const uint8 i) const {
	return tree.getChild(i);
}

const Identifier Exposed_Parameter_Info_Base::id_for(const uint8 i) const {
	if (i < exp_param_count)
		return param(i).getType();
	return Identifier{};
}

const uint8 Exposed_Parameter_Info_Base::param_num_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_num];
	return uint8{ 255 };
}

const String Exposed_Parameter_Info_Base::name_for(const uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::param_name].toString();
	return String{};
}

uint8 Exposed_Parameter_Info_Base::byte_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_byte_index];
	return uint8{ 255 };
}

uint8 Exposed_Parameter_Info_Base::choice_count_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_choice_count];
	return uint8{ 255 };
}

uint8 Exposed_Parameter_Info_Base::init_choice_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_init_choice];
	return uint8{ 255 };
}

Point<int> Exposed_Parameter_Info_Base::ctrl_center_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto x = (int)param(i)[ID::param_ctrl_center_x];
		auto y = (int)param(i)[ID::param_ctrl_center_y];
		return Point<int>{ x, y };
	}
	return Point<int>{};
}

int Exposed_Parameter_Info_Base::ctrl_width_for(const uint8 i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::param_ctrl_width];
	return 0;
}

String Exposed_Parameter_Info_Base::description_for(const uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::param_description].toString();
	return String{};
}

String Exposed_Parameter_Info_Base::choice_name_for(const uint8 i, const uint8 num, bool curt) const {
	String choice_name{};
	if (i < exp_param_count && num < choice_count_for(i)) {
		auto& tree_id = curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names;
		auto choices = param(i).getChildWithName(tree_id);
		choice_name = choices["choice_" + (String)num].toString();
	}
	return choice_name;
}


