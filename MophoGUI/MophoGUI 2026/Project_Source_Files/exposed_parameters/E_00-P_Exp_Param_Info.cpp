#include "E_00-P_Exp_Param_Info.h"

#include "H_10-P_Describe_Exp_Param.h"

using namespace EP;
using namespace XYWH;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Base_Exposed_Parameter_Info{ EP::exp_param_count }
{
	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::ep_000_osc_1_pitch : ID::ep_006_osc_2_pitch,
				"Oscillator " + (String)osc + " Pitch", Ctrl_Type::knob_pitch,
				Knob_Display_Type::osc_pitch, osc == 1 ? (uint8)0 : (uint8)5,
				choice_count_osc_pitch, (uint8)24, ctrl_col_1_x,
				osc == 1 ? osc_row_1_center_y : osc_row_2_center_y, knob_diameter, knob_diameter,
				Describe_Exp_Param::osc_pitch(osc), Choice_Menu_Type::standard,
				choice_menu_col_count_pitch, choice_menu_col_w_pitch, choice_menu_row_count_pitch, 
				0, ctrl_col_1_x + choice_menu_offset_knob, 
				osc == 1 ? osc_row_1_knob_top_y : osc_row_2_knob_top_y,
				Build_Tree::choice_names_osc_pitch(true, EP::choice_count_osc_pitch),
				Build_Tree::choice_names_osc_pitch(false, EP::choice_count_osc_pitch)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section
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
