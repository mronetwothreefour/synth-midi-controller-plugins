#include "D_TREE_Exposed_Info_G.h"

#include "C_EXP_P.h"
#include "C_ID_P.h"

using namespace EXP;

Tree_Exposed_Info_G::Tree_Exposed_Info_G() :
	tree{ ID::tree_exp_param_info }
{}

const ValueTree Tree_Exposed_Info_G::param(const Exp_Param id) const {
	return tree.getChildWithName(String{ id });
}

const String Tree_Exposed_Info_G::name_for(const Exp_Param id) const {
	return param(id)[ID::exp_p_name].toString();
}

const Ctrl_Type Tree_Exposed_Info_G::ctrl_type_for(const Exp_Param id) const {
	return Ctrl_Type{ (int)param(id)[ID::exp_p_ctrl_type] };
}

const Slider_Display_Type Tree_Exposed_Info_G::display_type_for(const Exp_Param id) const {
	return Slider_Display_Type{ (int)param(id)[ID::exp_p_sli_disp_type] };
}

const int Tree_Exposed_Info_G::choice_count_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_choice_count];
}

const int Tree_Exposed_Info_G::init_choice_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_init_choice];
}

Point<int> Tree_Exposed_Info_G::ctrl_center_for(const Exp_Param id) const {
	auto x = (int)param(id)[ID::exp_p_ctrl_cntr_x];
	auto y = (int)param(id)[ID::exp_p_ctrl_cntr_y];
	return Point<int>{ x, y };
}

int Tree_Exposed_Info_G::ctrl_width_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_ctrl_w];
}

int Tree_Exposed_Info_G::ctrl_height_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_ctrl_h];
}

const String Tree_Exposed_Info_G::tip_for(const Exp_Param id) const {
	return param(id)[ID::exp_p_tip].toString();
}

const String Tree_Exposed_Info_G::choice_for(const Exp_Param id, const int num, bool curt) const
{
	auto& subtree_id = curt ? ID::subtree_choices_curt : ID::subtree_choices;
	auto choices = param(id).getChildWithName(subtree_id);
	return choices["choice_" + (String)num].toString();
}

const StringArray Tree_Exposed_Info_G::choices_list_for(const Exp_Param id, bool curt) const
{
	StringArray list{};
	auto count = choice_count_for(id);
	auto& subtree_id = curt ? ID::subtree_choices_curt : ID::subtree_choices;
	auto choices = param(id).getChildWithName(subtree_id);
	for (int i = 0; i < count; ++i)
		list.add(choices["choice_" + (String)i].toString());
	return list;
}

const int Tree_Exposed_Info_G::drag_sensitivity_for(const Exp_Param id, float scale_factor) const {
	auto choice_count = choice_count_for(id);
	auto sensitivity = 175.0f * scale_factor;
	if (choice_count < 128)
		sensitivity = (80.0f + choice_count / 2.0f) * scale_factor;
	return roundToInt(sensitivity);
}

Layout Tree_Exposed_Info_G::build_param_layout() const {
	Layout layout;
	for (int i = 0; i < EXP::exp_param_count; ++i) {
		auto id{ Exp_Param(i) };
		auto name{ name_for(id) };
		auto choices_list{ choices_list_for(id) };
		auto init_choice{ init_choice_for(id) };
		layout.add(std::make_unique<AudioParameterChoice>(id, name, choices_list, init_choice));
	}
	return layout;
}

