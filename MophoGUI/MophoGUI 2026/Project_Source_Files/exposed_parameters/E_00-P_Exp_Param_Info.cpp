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
		auto center_y = osc == 1 ? osc_row_1_center_y : osc_row_2_center_y;
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_000_osc_1_pitch : ID::ep_006_osc_2_pitch,
				"Oscillator " + (String)osc + " Pitch", Ctrl_Type::knob_pitch,
				Knob_Display_Type::osc_pitch, osc == 1 ? 0 : 5,
				choice_count_osc_pitch, 24, ctrl_col_1_x, center_y, knob_diameter, knob_diameter,
				Describe_Exp_Param::osc_pitch(osc),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch, curt),
				Build_Tree::choice_names_osc_pitch(EP::choice_count_osc_pitch)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_001_osc_1_fine_tune : ID::ep_007_osc_2_fine_tune,
				"Oscillator " + (String)osc + " Fine Tune", Ctrl_Type::knob,
				Knob_Display_Type::osc_fine, osc == 1 ? 1 : 6,
				choice_count_osc_fine, osc == 1 ? 49 : 51, ctrl_col_2_x, center_y, 
				knob_diameter, knob_diameter, Describe_Exp_Param::osc_fine(osc),
				Build_Tree::choice_names_osc_fine(curt), Build_Tree::choice_names_osc_fine()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_002_osc_1_shape : ID::ep_008_osc_2_shape,
				"Oscillator " + (String)osc + " Wave Shape", Ctrl_Type::knob_osc_shape,
				Knob_Display_Type::osc_shape, osc == 1 ? 2 : 7,
				choice_count_osc_shape, 1, ctrl_col_3_x, center_y, knob_diameter, knob_diameter,
				Describe_Exp_Param::osc_shape(osc),
				Build_Tree::choice_names_osc_shape(curt),
				Build_Tree::choice_names_osc_shape()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_003_osc_1_glide : ID::ep_009_osc_2_glide,
				"Oscillator " + (String)osc + " Glide Rate", Ctrl_Type::knob,
				Knob_Display_Type::unsigned_7_bit, osc == 1 ? 3 : 8,
				128, 0, ctrl_col_4_x, center_y, knob_diameter, knob_diameter,
				Describe_Exp_Param::osc_fine(osc),
				Build_Tree::choice_names_unsigned_int(128, curt),
				Build_Tree::choice_names_unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_004_osc_1_key_track : ID::ep_010_osc_2_key_track,
				"Oscillator " + (String)osc + " Keyboard Track On/Off", Ctrl_Type::toggle,
				Knob_Display_Type::none, osc == 1 ? 4 : 9, 2, 1, ctrl_col_6_x, 
				center_y + toggle_center_offset, toggle_diameter, toggle_diameter,
				Describe_Exp_Param::osc_key_track(osc), Build_Tree::choice_names_off_on(curt),
				Build_Tree::choice_names_off_on()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_005_osc_1_sub_level : ID::ep_011_osc_2_sub_level,
				"Sub-Oscillator " + (String)osc + " Level", Ctrl_Type::knob,
				Knob_Display_Type::unsigned_7_bit, osc == 1 ? 114 : 115, 128, 0, ctrl_col_5_x,
				center_y, knob_diameter, knob_diameter, Describe_Exp_Param::osc_sub_level(osc), 
				Build_Tree::choice_names_unsigned_int(128, curt), 
				Build_Tree::choice_names_unsigned_int(128)
			),
			-1, nullptr);
	} 

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_012_osc_sync, "Hard Oscillator Sync On / Off", Ctrl_Type::toggle,
			Knob_Display_Type::none, 10, 2, 0, 242, 22, toggle_diameter, toggle_diameter,
			Describe_Exp_Param::osc_sync(), Build_Tree::choice_names_off_on(curt),
			Build_Tree::choice_names_off_on()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_013_glide_mode, "Glide Mode", Ctrl_Type::cbox,
			Knob_Display_Type::none, 11, 4, 0, ctrl_col_10_x, 78, osc_cbox_w, cbox_h,
			Describe_Exp_Param::glide_mode(), Build_Tree::choice_names_glide_mode(curt),
			Build_Tree::choice_names_glide_mode()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_014_osc_slop, "Oscillator Slop", Ctrl_Type::knob,
			Knob_Display_Type::osc_slop, 12, 6, 2, ctrl_col_7_x, osc_row_1_center_y, 
			knob_diameter, knob_diameter, Describe_Exp_Param::osc_slop(),
			Build_Tree::choice_names_unsigned_int(6, curt), Build_Tree::choice_names_unsigned_int(6)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_015_bend_range, "Pitch Bend Range", Ctrl_Type::knob,
			Knob_Display_Type::pitch_bend, 93, choice_count_bend_range, 4, ctrl_col_9_x, osc_row_1_center_y,
			knob_diameter, knob_diameter, Describe_Exp_Param::bend_range(),
			Build_Tree::choice_names_bend_range(curt), Build_Tree::choice_names_bend_range()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_016_note_priority, "Note Priority (Key Assign)", Ctrl_Type::cbox,
			Knob_Display_Type::none, 96, 6, 4, ctrl_col_10_x, 38,
			osc_cbox_w, cbox_h, Describe_Exp_Param::note_priority(),
			Build_Tree::choice_names_note_priority(curt), Build_Tree::choice_names_note_priority()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_017_osc_mix, "Oscillator 1 & 2 Mix", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 13, 128, 64, ctrl_col_8_x, osc_row_1_center_y,
			knob_diameter, knob_diameter, Describe_Exp_Param::osc_mix(),
			Build_Tree::choice_names_unsigned_int(128, curt), Build_Tree::choice_names_unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_018_noise_level, "Noise Level", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 14, 128, 0, ctrl_col_7_x, osc_row_2_center_y,
			knob_diameter, knob_diameter, Describe_Exp_Param::noise_level(),
			Build_Tree::choice_names_unsigned_int(128, curt), Build_Tree::choice_names_unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::ep_019_ext_in_level, "External Audio Input Level", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 116, 128, 0, ctrl_col_8_x, osc_row_2_center_y,
			knob_diameter, knob_diameter, Describe_Exp_Param::ext_in_level(),
			Build_Tree::choice_names_unsigned_int(128, curt), Build_Tree::choice_names_unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end osc section
}

const Identifier Exposed_Parameter_Info::id_for(Track track, Step step) const {
	if (step != Step::all) {
		auto param_num{ 
			EP::param_index_seq_track_1_step_1 + ((int)track - 1) * 16 + ((int)step - 1) 
		};
		auto exp_param_id{ "ep_" + String{ param_num } };
		exp_param_id << "_Seq_Track_" << String{ (int)track };
		exp_param_id << "_Step_" << String{ (int)step };
		return exp_param_id;
	}
	return {};
}

const Ctrl_Type Exposed_Parameter_Info::ctrl_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::ep_p_ctrl_type] };
	return Ctrl_Type::error;
}

const Knob_Display_Type Exposed_Parameter_Info::knob_display_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Knob_Display_Type{ (int)param(i)[ID::ep_p_knob_display_type] };
	return Knob_Display_Type::error;
}

const uint8 Exposed_Parameter_Info::nrpn_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_nrpn];
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::param_index_for(const uint8 nrpn) const {
	for (uint8 i = 0; i < exp_param_count; ++i) {
		if (nrpn_for(i) == nrpn)
			return i;
	}
	return (uint8)255;
}

Point<int> Exposed_Parameter_Info::red_toggle_center_for(uint8 i) const {
	if (i < exp_param_count && ctrl_type_for(i) == Ctrl_Type::toggle) {
		auto x = (int)param(i)[ID::ep_p_red_toggle_center_x];
		auto y = (int)param(i)[ID::ep_p_red_toggle_center_y];
		return Point<int>{ x, y };
	}
	return {};
}

const uint16 Exposed_Parameter_Info::packed_bits_byte_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint16)(int)param(i)[ID::ep_p_packed_bits_byte_index];
	return (uint16)65535;
}

const uint8 Exposed_Parameter_Info::packed_bits_mask_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_packed_bits_mask];
	return (uint8)255;
}

const uint16 Exposed_Parameter_Info::byte_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint16)(int)param(i)[ID::ep_p_byte_index];
	return (uint16)65535;
}

const Track Exposed_Parameter_Info::seq_track_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto first_track_index = EP::param_index_seq_track_1_step_1;
		if (i >= first_track_index)
			return Track{ ((i - first_track_index) / 16) + 1 };
		return Track::none;
	}
	return Track::error;
}

const Step Exposed_Parameter_Info::seq_track_step_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto first_track_index = EP::param_index_seq_track_1_step_1;
		if (i >= first_track_index)
			return Step{ ((i - first_track_index) % 16) + 1 };
		return Step::none;
	}
	return Step::error;
}

const Choice_Menu_Type Exposed_Parameter_Info::choice_menu_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Choice_Menu_Type{ (int)param(i)[ID::ep_p_choice_menu_type] };
	return Choice_Menu_Type::error;
}
