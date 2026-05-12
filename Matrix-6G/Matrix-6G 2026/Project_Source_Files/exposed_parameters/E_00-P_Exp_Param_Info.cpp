#include "E_00-P_Exp_Param_Info.h"

#include "H_10-P_Describe_Exp_Param.h"

using namespace EP;
using namespace XYWH;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Base_Exposed_Parameter_Info{ EP::exp_param_count }
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_00_osc_1_pitch : ID::ep_10_osc_2_pitch, osc == 1 ? 0 : 10,
				"Oscillator " + (String)osc + " Pitch", Ctrl_Type::slider_osc_pitch,
				osc == 1 ? 1 : 6, Range_Type::unsigned_int, Slider_Display_Type::osc_pitch,
				choice_count_osc_pitch, (uint8)0, osc == 1 ? osc_col_1_x : osc_col_2_x, 
				ctrl_row_01_y, osc_ctrl_w, Describe_Exp_Param::osc_pitch(osc),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch, curt),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch)
			), 
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section
}

const uint8 Exposed_Parameter_Info::number_for(uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_number];
	return (uint8)255;
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

const Range_Type Exposed_Parameter_Info::range_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Range_Type{ (int)param(i)[ID::ep_p_range_type] };
	return Range_Type::error;
}

const Slider_Display_Type Exposed_Parameter_Info::slider_display_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Slider_Display_Type{ (int)param(i)[ID::ep_p_slider_display_type] };
	return Slider_Display_Type::error;
}

