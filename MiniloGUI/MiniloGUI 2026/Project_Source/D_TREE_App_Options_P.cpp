#include "D_TREE_App_Options_P.h"

Tree_App_Options_P::Tree_App_Options_P() :
	Tree_App_Options_G{}
{
	set_show_eg_envelope(false);
	set_show_eg_envelope(false);
}

const bool Tree_App_Options_P::show_amp_eg_envelope() {
	return (int)tree[String{ (int)App_Option::show_amp_eg_env }];
}

void Tree_App_Options_P::set_show_amp_eg_envelope(const bool should_show) {
	tree.setProperty(String{ (int)App_Option::show_amp_eg_env }, should_show, nullptr);
}

const bool Tree_App_Options_P::show_eg_envelope() {
	return (int)tree[String{ (int)App_Option::show_eg_env }];
}

void Tree_App_Options_P::set_show_eg_envelope(const bool should_show) {
	tree.setProperty(String{ (int)App_Option::show_eg_env }, should_show, nullptr);
}
