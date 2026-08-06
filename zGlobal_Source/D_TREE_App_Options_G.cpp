#include "D_TREE_App_Options_G.h"

#include "C_ID_P.h"

Tree_App_Options_G::Tree_App_Options_G() :
	tree{ ID::tree_app_options }
{
	set_scale_percentage(100);
}

const int Tree_App_Options_G::scale_percentage() {
	return (int)tree[String{ (int)App_Option::scale_percentage }];
}

void Tree_App_Options_G::set_scale_percentage(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 25, 200);
	tree.setProperty(String{ (int)App_Option::scale_percentage }, setting_clamped, nullptr);
}

void Tree_App_Options_G::set_scale_percentage_excluding(const int new_setting,
														ValueTree::Listener* listener)
{
	auto setting_clamped = std::clamp(new_setting, 25, 200);
	auto id = String{ (int)App_Option::scale_percentage };
	tree.setPropertyExcludingListener(listener, id, setting_clamped, nullptr);
}

void Tree_App_Options_G::add_listener(ValueTree::Listener* listener) {
	tree.addListener(listener);
}

void Tree_App_Options_G::remove_listener(ValueTree::Listener* listener) {
	tree.removeListener(listener);
}

Value Tree_App_Options_G::get_option_as_value(App_Option option) {
	return tree.getPropertyAsValue(String{ (int)option }, nullptr);
}


