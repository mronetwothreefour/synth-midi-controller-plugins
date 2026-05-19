#include "H_00-P_Build_Tree.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
										Knob_Display_Type display, uint8 cc_num, 
										uint16 choice_count, uint16 init_choice,
										int ctrl_center_x, int ctrl_center_y, int ctrl_w,
										int ctrl_h, String description, ValueTree bit_locations,
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_knob_display_type, (int)display },
			{ ID::ep_p_cc_num, cc_num },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_ctrl_height, ctrl_h },
			{ ID::ep_p_description, description },
		},
		{ bit_locations, curt_choice_names, choice_names }
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_delay_routing(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "byp" : "bypass", nullptr);
	tree.setProperty("choice_1", curt ? "pre" : "pre-filter", nullptr);
	tree.setProperty("choice_2", curt ? "post" : "post-filter", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_2_pitch_eg_int(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    String postfix{ curt ? "" : " cents" };

    for (int n = 0; n < 5; ++n)
        tree.setProperty("choice_" + (String)n, "-4800" + postfix, nullptr);

    auto val{ -4800 };
    for (int n = 5; n < 357; ++n) {
        val += (n % 2 == 1 ? 13 : 12);
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    for (int n = 357; n < 477; ++n) {
        val += (n % 8 == 5 ? 4 : 3);
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    tree.setProperty("choice_477", "-23" + postfix, nullptr);
    tree.setProperty("choice_478", "-21" + postfix, nullptr);
    tree.setProperty("choice_479", "-20" + postfix, nullptr);
    tree.setProperty("choice_480", "-18" + postfix, nullptr);
    tree.setProperty("choice_481", "-17" + postfix, nullptr);
    tree.setProperty("choice_482", "-15" + postfix, nullptr);
    tree.setProperty("choice_483", "-14" + postfix, nullptr);
    tree.setProperty("choice_484", "-12" + postfix, nullptr);
    tree.setProperty("choice_485", "-10" + postfix, nullptr);
    tree.setProperty("choice_486", "-9" + postfix, nullptr);
    tree.setProperty("choice_487", "-7" + postfix, nullptr);
    tree.setProperty("choice_488", "-5" + postfix, nullptr);
    tree.setProperty("choice_489", "-4" + postfix, nullptr);
    tree.setProperty("choice_490", "-3" + postfix, nullptr);
    tree.setProperty("choice_491", "-1" + postfix, nullptr);

    for (int n = 492; n < 531; ++n)
        tree.setProperty("choice_" + (String)n, "0" + postfix, nullptr);

    tree.setProperty("choice_531", "+1" + postfix, nullptr);
    tree.setProperty("choice_532", "+2" + postfix, nullptr);
    tree.setProperty("choice_533", "+3" + postfix, nullptr);
    tree.setProperty("choice_534", "+4" + postfix, nullptr);
    tree.setProperty("choice_535", "+5" + postfix, nullptr);
    tree.setProperty("choice_536", "+7" + postfix, nullptr);
    tree.setProperty("choice_537", "+8" + postfix, nullptr);
    tree.setProperty("choice_538", "+10" + postfix, nullptr);
    tree.setProperty("choice_539", "+11" + postfix, nullptr);
    tree.setProperty("choice_540", "+13" + postfix, nullptr);
    tree.setProperty("choice_541", "+15" + postfix, nullptr);
    tree.setProperty("choice_542", "+16" + postfix, nullptr);
    tree.setProperty("choice_543", "+18" + postfix, nullptr);
    tree.setProperty("choice_544", "+19" + postfix, nullptr);
    tree.setProperty("choice_545", "+21" + postfix, nullptr);
    tree.setProperty("choice_546", "+22" + postfix, nullptr);
    tree.setProperty("choice_547", "+24" + postfix, nullptr);
    tree.setProperty("choice_548", "+25" + postfix, nullptr);

    val = 25;

    for (int n = 549; n < 669; ++n) {
        val += (n % 8 == 5 ? 4 : 3);
        tree.setProperty("choice_" + (String)n, "+" + (String)val + postfix, nullptr);
    }

    for (int n = 669; n < 1020; ++n) {
        val += (n % 2 == 1 ? 13 : 12);
        tree.setProperty("choice_" + (String)n, "+" + (String)val + postfix, nullptr);
    }

    for (int n = 1020; n < 1024; ++n)
        tree.setProperty("choice_" + (String)n, "+4800" + postfix, nullptr);

    return tree;
}

ValueTree Build_Tree::choice_names_osc_and_lfo_wave(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "sqr" : "square", nullptr);
	tree.setProperty("choice_1", curt ? "tri" : "triangle", nullptr);
	tree.setProperty("choice_2", curt ? "saw" : "sawtooth", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_osc_octave(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "16'", nullptr);
	tree.setProperty("choice_1", "8'", nullptr);
	tree.setProperty("choice_2", "4'", nullptr);
	tree.setProperty("choice_4", "2'", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_osc_pitch_fine(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    return tree;
}
