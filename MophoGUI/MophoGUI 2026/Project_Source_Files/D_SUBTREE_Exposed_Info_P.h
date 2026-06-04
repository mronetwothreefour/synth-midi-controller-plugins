#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"
#include "C_ID_P.h"

using namespace ENUM;

struct Subtree_Exposed_Info_P
{
	static ValueTree build(Identifier id, String name, Ctrl_Type ctrl,
						   Knob_Editor_Type editor, int nrpn, int choice_count,
						   int init_choice, int ctrl_center_x, int ctrl_center_y,
						   int ctrl_w, int ctrl_h, String tip,
						   ValueTree choices_curt, ValueTree choices,
						   int red_toggle_center_x = 0, int red_toggle_center_y = 0)
	{
		ValueTree tree{ id,
			{
				{ ID::exp_p_name, name },
				{ ID::exp_p_ctrl_type, (int)ctrl },
				{ ID::exp_p_knob_editor_type, (int)editor },
				{ ID::exp_p_nrpn, nrpn },
				{ ID::exp_p_choice_count, choice_count },
				{ ID::exp_p_init_choice, init_choice },
				{ ID::exp_p_ctrl_center_x, ctrl_center_x },
				{ ID::exp_p_ctrl_center_y, ctrl_center_y },
				{ ID::exp_p_ctrl_width, ctrl_w },
				{ ID::exp_p_ctrl_height, ctrl_h },
				{ ID::exp_p_tip, tip },
				{ ID::exp_p_red_toggle_center_x, red_toggle_center_x },
				{ ID::exp_p_red_toggle_center_y, red_toggle_center_y }
			},
			{ choices_curt, choices }
		};
		auto param_num{ id.toString().fromFirstOccurrenceOf("exp_", false, true)
									 .upToFirstOccurrenceOf("_", false, true)
									 .getIntValue() };
		if (param_num >= EXP::first_unassigned_param_num)
			param_num += EXP::unassigned_param_count;
		auto packed_bits_byte_index{ (param_num / 7) * 8 };
		tree.setProperty(ID::exp_p_packed_bits_byte_index, packed_bits_byte_index, nullptr);
		auto packed_bits_mask{ roundToInt(pow(2, param_num % 7)) };
		tree.setProperty(ID::exp_p_packed_bits_mask, packed_bits_mask, nullptr);
		auto byte_index{ packed_bits_byte_index + param_num % 7 + 1 };
		tree.setProperty(ID::exp_p_byte_index, byte_index, nullptr);
		return tree;
	}
};