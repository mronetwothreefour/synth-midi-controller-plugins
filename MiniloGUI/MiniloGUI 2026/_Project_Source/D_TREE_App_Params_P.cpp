#include "D_TREE_App_Params_P.h"

#include "C_ID_Main_P.h"

using namespace TREE;

App_Params::App_Params(UndoManager* u_m) :
	App_Params_A{ u_m }
{
	set_show_envelope(false);
	set_show_vca_envelope(false);
}

const bool TREE::App_Params::show_envelope() {
	return (int)tree[ID::app_show_env];
}

void TREE::App_Params::set_show_envelope(const bool should_show) {
	tree.setProperty(ID::app_show_env, should_show, nullptr);
}

const bool TREE::App_Params::show_vca_envelope() {
	return (int)tree[ID::app_show_vca_env];
}

void TREE::App_Params::set_show_vca_envelope(const bool should_show) {
	tree.setProperty(ID::app_show_vca_env, should_show, nullptr);
}
