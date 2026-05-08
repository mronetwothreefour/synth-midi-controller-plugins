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
			byte_index = byte_index.upToFirstOccurrenceOf("/", false, false);
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
