#include "EP _0_Exposed_Parameter_Info.h"

#include "C_EP.h"
#include "C_ID.h"

using namespace EP;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	tree{ ID::tree_exp_param_info }
{
}

const ValueTree Exposed_Parameter_Info::param(const uint8 i) const {
	return tree.getChild(i);
}

const Identifier Exposed_Parameter_Info::id_for(const uint8 i) const {
	if (i < exp_param_count)
		return param(i).getType();
	return Identifier{};
}

const uint8 Exposed_Parameter_Info::param_num_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::param_num];
	return uint8{ 255 };
}

const String Exposed_Parameter_Info::name_for(const uint8 i) const {
	if (i < exp_param_count)
		return param(i)[ID::param_name].toString();
	return String{};
}

const Ctrl_Type Exposed_Parameter_Info::ctrl_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::param_ctrl_type] };
	return Ctrl_Type::dummy;
}

