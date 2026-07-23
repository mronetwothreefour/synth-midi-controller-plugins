#include "D_SUBTREE_Exposed_Info_P.h"

#include "C_ID_P.h"

ValueTree Subtree_Exposed_Info_P::build(Exp_Param id, String name, Ctrl_Type ctrl,
										Slider_Display_Type display, int nrpn, int choice_count,
										int init_choice, int ctrl_cntr_x, int ctrl_cntr_y,
										int ctrl_w, int ctrl_h, String tip,
										ValueTree choices_curt, ValueTree choices,
										int red_toggle_cntr_x, int red_toggle_cntr_y)
{
	ValueTree tree{ 
		String{ id },
		{
			{ ID::exp_p_name, name },
			{ ID::exp_p_ctrl_type, (int)ctrl },
			{ ID::exp_p_sli_disp_type, (int)display },
			{ ID::exp_p_nrpn, nrpn },
			{ ID::exp_p_choice_count, choice_count },
			{ ID::exp_p_init_choice, init_choice },
			{ ID::exp_p_ctrl_cntr_x, ctrl_cntr_x },
			{ ID::exp_p_ctrl_cntr_y, ctrl_cntr_y },
			{ ID::exp_p_ctrl_w, ctrl_w },
			{ ID::exp_p_ctrl_h, ctrl_h },
			{ ID::exp_p_tip, tip },
			{ ID::exp_p_red_toggle_cntr_x, red_toggle_cntr_x },
			{ ID::exp_p_red_toggle_cntr_y, red_toggle_cntr_y }
		},
		{ choices_curt, choices }
	};
	auto packed_bits_byte_index{ (id / 7) * 8 };
	tree.setProperty(ID::exp_p_packed_bits_byte_index, packed_bits_byte_index, nullptr);
	auto packed_bits_mask{ roundToInt(pow(2, id % 7)) };
	tree.setProperty(ID::exp_p_packed_bits_mask, packed_bits_mask, nullptr);
	auto byte_index{ packed_bits_byte_index + id % 7 + 1 };
	tree.setProperty(ID::exp_p_byte_index, byte_index, nullptr);
	return tree;
}
