#include "E_00-P_Exp_Param_Info.h"

using namespace EP;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Base_Exposed_Parameter_Info{ EP::exp_param_count }
{
}

const uint8 Exposed_Parameter_Info::byte_index_for(uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_byte_index];
	return (uint8)255;
}

const Ctrl_Type Exposed_Parameter_Info::ctrl_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::ep_p_ctrl_type] };
	return Ctrl_Type::error;
}

const Slider_Display_Type Exposed_Parameter_Info::slider_display_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Slider_Display_Type{ (int)param(i)[ID::ep_p_slider_display_type] };
	return Slider_Display_Type::error;
}

