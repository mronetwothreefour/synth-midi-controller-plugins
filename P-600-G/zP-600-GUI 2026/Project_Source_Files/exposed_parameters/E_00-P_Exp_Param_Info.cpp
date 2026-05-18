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
		String osc_letter{ osc == 1 ? "A" : "B" };
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_00_osc_1_pitch : ID::ep_06_osc_2_pitch,
				"Oscillator " + osc_letter + " Frequency", Ctrl_Type::knob_osc_pitch,
				osc == 1 ? 8 : 6, osc == 1 ? 1 : 3, 6,
				choice_count_osc_pitch, (uint8)12, osc_col_1_x,
				osc == 1 ? knob_row_1_y : knob_row_2_y, knob_diameter, knob_diameter, 
				Describe_Exp_Param::osc_pitch(osc),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch, curt),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section
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

