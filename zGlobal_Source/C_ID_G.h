#pragma once

#include <JuceHeader.h>

namespace ID
{

	static const String allowed_char_int_signed{ "-0123456789" };
	static const String allowed_char_int_unsigned{ "0123456789" };
	static const String allowed_char_osc_pitch{ "abcdefgABCDEFG0123456789#" };

	// exposed parameter properties
	static const String exp_p_choice_count{ "exp_p_choice_count" };
	static const String exp_p_ctrl_cntr_x{ "exp_p_ctrl_cntr_x" };
	static const String exp_p_ctrl_cntr_y{ "exp_p_ctrl_cntr_y" };
	static const String exp_p_ctrl_h{ "exp_p_ctrl_h" };
	static const String exp_p_ctrl_type{ "exp_p_ctrl_type" };
	static const String exp_p_ctrl_w{ "exp_p_ctrl_w" };
	static const String exp_p_tip{ "exp_p_tip" };
	static const String exp_p_init_choice{ "exp_p_init_choice" };
	static const String exp_p_sli_disp_type{ "exp_p_sli_disp_type" };
	static const String exp_p_name{ "exp_p_name" };

	static const String label_cbox{ "label_cbox" };
	static const String label_browser{ "label_browser" };
	static const String label_slider{ "label_slider" };

	static const String subtree_choices{ "subtree_choices" };
	static const String subtree_choices_curt{ "subtree_choices_curt" };

	static const String tree_app_options{ "tree_app_options" };
	static const String tree_exp_param_info{ "tree_exp_param_info" };
	static const String tree_exp_param_state{ "tree_exp_param_state" };

	static const String txt_editor_filled{ "txt_editor_filled" };

	static const String xml_att_scale_factor{ "xml_att_scale_factor" };
	static const String xml_state_exposed{ "xml_state_exposed" };
	static const String xml_state_plugin{ "xml_state_plugin" };
	static const String xml_state_plugin_specific{ "xml_state_plugin_specific" };

}