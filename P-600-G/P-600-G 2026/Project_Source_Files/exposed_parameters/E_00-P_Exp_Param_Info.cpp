#include "E_00-P_Exp_Param_Info.h"

using namespace EP;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Base_Exposed_Parameter_Info{ EP::exp_param_count }
{
}

const Ctrl_Type Exposed_Parameter_Info::ctrl_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::ep_p_ctrl_type] };
	return Ctrl_Type::error;
}

const uint8 Exposed_Parameter_Info::first_nybble_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_first_nybble_index];
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::first_bit_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_first_bit_index];
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::bit_count_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_bit_count];
	return (uint8)255;
}

