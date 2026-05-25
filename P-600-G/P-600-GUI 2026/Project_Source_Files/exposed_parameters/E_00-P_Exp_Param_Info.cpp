#include "E_00-P_Exp_Param_Info.h"

#include "H_10-P_Describe_Exp_Param.h"

using namespace EP;
using namespace XYWH;
using Describe = Describe_Exp_Param;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Base_Exposed_Parameter_Info{ EP::exp_param_count }
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		String o{ osc == 1 ? "A" : "B" };
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_00_osc_a_pitch : ID::ep_06_osc_b_pitch,
				"Oscillator " + o + " Frequency", Ctrl_Type::knob_osc_pitch, osc == 1 ? 8 : 6,
				osc == 1 ? 1 : 3, 6, choice_count_osc_pitch, 12, osc_col_1_x, 
				osc == 1 ? knob_row_2_y : knob_row_3_y, knob_diameter, knob_diameter, Describe::osc_pitch(o),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch, curt),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_01_osc_a_sync : ID::ep_07_osc_b_fine,
				"Oscillator " + o + (osc == 0 ? " Sync" : " Fine Tune"),
				osc == 0 ? Ctrl_Type::switch_2_pole : Ctrl_Type::knob, osc == 0 ? 30 : 9,
				osc == 0 ? 2 : 3, osc == 0 ? 1 : 7, osc == 0 ? 2 : 128, 0, osc_col_2_x,
				osc == 0 ? switch_row_1_y : knob_row_3_y, osc == 0 ? switch_w : knob_diameter,
				osc == 0 ? switch_2_pole_h : knob_diameter,
				osc == 0 ? Describe::osc_a_sync() : Describe::osc_b_fine(),
				osc == 0 ? Build_Tree::choice_names_off_on(curt) :
						   Build_Tree::choice_names_unsigned_int(128, curt),
				osc == 0 ? Build_Tree::choice_names_off_on() :
						   Build_Tree::choice_names_unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_02_osc_a_saw : ID::ep_08_osc_b_saw,
				"Oscillator " + o + " Shape: Sawtooth", Ctrl_Type::switch_2_pole, 30,
				osc == 0 ? 0 : 3, 1, 2, 0, osc_col_3_x, osc == 0 ? switch_row_1_y : switch_row_2_y,
				switch_w, switch_2_pole_h, "When on, oscillator " + o + " outputs a sawtooth wave.",
				Build_Tree::choice_names_off_on(curt), Build_Tree::choice_names_off_on()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_03_osc_a_tri : ID::ep_09_osc_b_tri,
				"Oscillator " + o + " Shape: Triangle", Ctrl_Type::switch_2_pole, osc == 0 ? 30 : 31,
				osc == 0 ? 1 : 0, 1, 2, 1, osc_col_4_x, osc == 0 ? switch_row_1_y : switch_row_2_y,
				switch_w, switch_2_pole_h, "When on, oscillator " + o + " outputs a triangle wave.",
				Build_Tree::choice_names_off_on(curt), Build_Tree::choice_names_off_on()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_04_osc_a_pulse : ID::ep_10_osc_b_pulse,
				"Oscillator " + o + " Shape: Pulse", Ctrl_Type::switch_2_pole, 28,
				osc == 0 ? 0 : 1, 1, 2, 0, osc_col_5_x, osc == 0 ? switch_row_1_y : switch_row_2_y,
				switch_w, switch_2_pole_h, "When on, oscillator " + o + " outputs a pulse wave.",
				Build_Tree::choice_names_off_on(curt), Build_Tree::choice_names_off_on()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_05_osc_a_pulse_w : ID::ep_11_osc_b_pulse_w,
				"Oscillator " + o + " Pulse Width", Ctrl_Type::knob, osc == 1 ? 0 : 26,
				osc == 1 ? 0 : 1, 7, 128, 64, osc_col_6_x, osc == 1 ? knob_row_2_y : knob_row_3_y,
				knob_diameter, knob_diameter, Describe::osc_pulse_w(o),
				Build_Tree::choice_names_unsigned_int(128, curt),
				Build_Tree::choice_names_unsigned_int(128)
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

