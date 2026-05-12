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
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_00_osc_1_pitch : ID::ep_10_osc_2_pitch, osc == 1 ? 0 : 10,
				"Oscillator " + (String)osc + " Pitch", Ctrl_Type::slider_osc_pitch,
				osc == 1 ? 1 : 6, Range_Type::unsigned_int, Slider_Display_Type::osc_pitch,
				choice_count_osc_pitch, (uint8)0, osc == 1 ? osc_col_1_x : osc_col_2_x, 
				ctrl_row_01_y, osc_ctrl_w, Describe::osc_pitch(osc),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch, curt),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch)
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_01_osc_1_type : ID::ep_11_osc_2_type, osc == 1 ? 6 : 16,
				"Oscillator " + (String)osc + " Type", Ctrl_Type::cbox,
				osc == 1 ? 5 : 10, Range_Type::unsigned_int, Slider_Display_Type::none,
				osc == 1 ? 4 : 5, osc == 1 ? 2 : 1, osc == 1 ? osc_col_1_x : osc_col_2_x,
				ctrl_row_02_y, osc_ctrl_w, Describe::osc_type(osc),
				Build_Tree::choice_names_osc_type(osc, curt),
				Build_Tree::choice_names_osc_type(osc)
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_02_osc_1_pulse_w : ID::ep_12_osc_2_pulse_w, osc == 1 ? 3 : 13,
				"Oscillator " + (String)osc + " Pulse Width", Ctrl_Type::slider,
				osc == 1 ? 3 : 8, Range_Type::unsigned_int, Slider_Display_Type::unsigned_int,
				osc == 64, osc == 1 ? 31 : 24, osc == 1 ? osc_col_1_x : osc_col_2_x,
				ctrl_row_03_y, osc_ctrl_w, Describe::osc_pulse_w(osc),
				Build_Tree::choice_names_unsigned_int(64, curt),
				Build_Tree::choice_names_unsigned_int(64)
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_03_osc_1_saw_tri : ID::ep_13_osc_2_saw_tri, osc == 1 ? 5 : 15,
				"Oscillator " + (String)osc + " Saw / Triangle Wave Blend", Ctrl_Type::slider,
				osc == 1 ? 2 : 7, Range_Type::unsigned_int, Slider_Display_Type::unsigned_int,
				osc == 64, 31, osc == 1 ? osc_col_1_x : osc_col_2_x,
				ctrl_row_04_y, osc_ctrl_w, Describe::osc_saw_tri(osc),
				Build_Tree::choice_names_unsigned_int(64, curt),
				Build_Tree::choice_names_unsigned_int(64)
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_04_osc_1_sync : ID::ep_14_osc_2_detune, osc == 1 ? 2 : 12,
				"Oscillator " + (String)osc + (osc == 1 ? " Sync" : " Detune"), 
				osc == 1 ? Ctrl_Type::cbox : Ctrl_Type::slider, osc == 1 ? 17 : 11,
				osc == 1 ? Range_Type::unsigned_int : Range_Type::signed_6_bit, 
				osc == 1 ? Slider_Display_Type::none : Slider_Display_Type::signed_6_bit_int,
				osc == 1 ? 4 : 63, osc == 1 ? 0 : 33, osc == 1 ? osc_col_1_x : osc_col_2_x,
				ctrl_row_05_y, osc_ctrl_w, 
				osc == 1 ? Describe::osc_1_sync() : Describe::osc_2_detune(),
				Build_Tree::choice_names_unsigned_int(64, curt),
				Build_Tree::choice_names_unsigned_int(64)
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_05_osc_1_lfo_1_fm : ID::ep_15_osc_2_lfo_1_fm, osc == 1 ? 1 : 11,
				"Oscillator " + (String)osc + " Frequency Mod. by LFO 1", Ctrl_Type::slider, 
				osc == 1 ? 78 : 80, Range_Type::signed_7_bit, Slider_Display_Type::signed_7_bit,
				127, 63, osc == 1 ? osc_col_1_x : osc_col_2_x, ctrl_row_06_y, osc_ctrl_w, 
				osc == 1 ? Describe::osc_1_sync() : Describe::osc_lfo_1_fm(osc),
				Build_Tree::choice_names_signed_7_bit_int(curt),
				Build_Tree::choice_names_signed_7_bit_int()
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_06_osc_1_lfo_2_pwm : ID::ep_16_osc_2_lfo_2_pwm, osc == 1 ? 4 : 14,
				"Oscillator " + (String)osc + " Pulse Width Mod. by LFO 2", Ctrl_Type::slider, 
				osc == 1 ? 79 : 81, Range_Type::signed_7_bit, Slider_Display_Type::signed_7_bit,
				127, 63, osc == 1 ? osc_col_1_x : osc_col_2_x, ctrl_row_07_y, osc_ctrl_w, 
				osc == 1 ? Describe::osc_1_sync() : Describe::osc_lfo_2_pwm(osc),
				Build_Tree::choice_names_signed_7_bit_int(curt),
				Build_Tree::choice_names_signed_7_bit_int()
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_07_osc_1_key_click : ID::ep_17_osc_2_key_click, osc == 1 ? 9 : 19,
				"Oscillator " + (String)osc + " Key Click", Ctrl_Type::cbox, 
				osc == 1 ? 14 : 16, Range_Type::unsigned_int, Slider_Display_Type::none,
				2, 0, osc == 1 ? osc_col_1_x : osc_col_2_x, ctrl_row_08_y, osc_ctrl_w, 
				Describe::osc_key_click(), Build_Tree::choice_names_off_on_matrix(curt),
				Build_Tree::choice_names_off_on_matrix()
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_08_osc_1_key_track : ID::ep_18_osc_2_key_track, osc == 1 ? 8 : 18,
				"Oscillator " + (String)osc + " Key Tracking", Ctrl_Type::cbox, 
				osc == 1 ? 13 : 15, Range_Type::unsigned_int, Slider_Display_Type::none,
				osc == 1 ? 2 : 3, osc == 1 ? 0 : 2, osc == 1 ? osc_col_1_x : osc_col_2_x, 
				ctrl_row_09_y, osc_ctrl_w, Describe::osc_key_track(osc),
				osc == 1 ? Build_Tree::choice_names_osc_1_key_track(curt) : Build_Tree::choice_names_osc_2_and_vcf_key_track(curt),
				osc == 1 ? Build_Tree::choice_names_osc_1_key_track() : Build_Tree::choice_names_osc_2_and_vcf_key_track()
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_09_osc_1_lever_ctrl : ID::ep_19_osc_2_lever_ctrl, 
				osc == 1 ? 7 : 17, "Oscillator " + (String)osc + " Lever Control", Ctrl_Type::cbox,
				osc == 1 ? 4 : 9, Range_Type::unsigned_int, Slider_Display_Type::none,
				4, 3, osc == 1 ? osc_col_1_x : osc_col_2_x, ctrl_row_10_y, osc_ctrl_w,
				Describe::osc_lever_control(osc), Build_Tree::choice_names_osc_lever_control(curt),
				Build_Tree::choice_names_osc_lever_control()
			), 
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				ID::ep_20_osc_balance, 20, "Oscillator Balance", Ctrl_Type::slider_osc_balance,
				12, Range_Type::unsigned_int, Slider_Display_Type::unsigned_int,
				64, 31, 163, ctrl_row_11_y, 126, Describe::osc_balance(),
				Build_Tree::choice_names_unsigned_int(64, curt),
				Build_Tree::choice_names_unsigned_int(64)
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

