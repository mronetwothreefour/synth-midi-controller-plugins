#include "D_TREE_App_Options_P.h"

Tree_App_Options_P::Tree_App_Options_P() :
	Tree_App_Options_G{}
{
	set_show_envelope(false);
	set_show_vca_envelope(false);
}

const bool Tree_App_Options_P::show_envelope() {
	return (int)tree[String{ (int)App_Option::show_env }];
}

void Tree_App_Options_P::set_show_envelope(const bool should_show) {
	tree.setProperty(String{ (int)App_Option::show_env }, should_show, nullptr);
}

const bool Tree_App_Options_P::show_vca_envelope() {
	return (int)tree[String{ (int)App_Option::show_vca_env }];
}

void Tree_App_Options_P::set_show_vca_envelope(const bool should_show) {
	tree.setProperty(String{ (int)App_Option::show_vca_env }, should_show, nullptr);
}