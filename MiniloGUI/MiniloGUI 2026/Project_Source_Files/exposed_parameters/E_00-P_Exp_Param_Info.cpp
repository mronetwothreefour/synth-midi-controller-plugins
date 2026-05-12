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
				osc == 1 ? ID::ep_02_osc_1_pitch_fine : ID::ep_06_osc_2_pitch_fine,
				"Oscillator " + (String)osc + " Pitch Fine Tune", 
				Ctrl_Type::knob_osc_pitch_fine, Knob_Display_Type::osc_pitch_fine,
				osc == 1 ? 34 : 35, EP::choice_count_osc_pitch_fine,
				(uint16)1200, 184, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y,
				knob_diameter, knob_diameter, Describe_Exp_Param::osc_pitch_fine(osc),
				ValueTree{ ID::tree_bit_locations, {
					{ "bit_0", osc == 1 ? "byte_59__bit_0" : "byte_60__bit_0" },
					{ "bit_1", osc == 1 ? "byte_59__bit_1" : "byte_60__bit_1" },
					{ "bit_2", osc == 1 ? "byte_22__bit_0" : "byte_25__bit_0" },
					{ "bit_3", osc == 1 ? "byte_22__bit_1" : "byte_25__bit_1" },
					{ "bit_4", osc == 1 ? "byte_22__bit_2" : "byte_25__bit_2" },
					{ "bit_5", osc == 1 ? "byte_22__bit_3" : "byte_25__bit_3" },
					{ "bit_6", osc == 1 ? "byte_22__bit_4" : "byte_25__bit_4" },
					{ "bit_7", osc == 1 ? "byte_22__bit_5" : "byte_25__bit_5" },
					{ "bit_8", osc == 1 ? "byte_22__bit_6" : "byte_25__bit_6" },
					{ "bit_9", osc == 1 ? "byte_15__bit_6" : "byte_23__bit_1" },
				} }, 
				Build_Tree::choice_names_osc_pitch_fine(curt),
				Build_Tree::choice_names_osc_pitch_fine()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section
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

const uint8 Exposed_Parameter_Info::cc_num_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::ep_p_cc_num];
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::bit_count_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::tree_bit_locations);
		return (uint8)bit_locations.getNumProperties();
	}
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::byte_index_for_param_bit(const uint8 i, const uint8 b) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::tree_bit_locations);
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto byte_index{ bit_locations[bit_id].toString() };
			byte_index = byte_index.fromFirstOccurrenceOf("byte_", false, false);
			byte_index = byte_index.upToFirstOccurrenceOf("__", false, false);
			return (uint8)byte_index.getIntValue();
		}
	}
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::bit_index_for_param_bit(const uint8 i, const uint8 b) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::tree_bit_locations);
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto bit_index{ bit_locations[bit_id].toString() };
			bit_index = bit_index.fromFirstOccurrenceOf("bit_", false, false);
			return (uint8)bit_index.getIntValue();
		}
	}
	return (uint8)255;
}
