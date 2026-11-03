#include "D_TREE_App_Params_P.h"

#include "C_ID_Main_P.h"

using namespace TREE;

App_Params::App_Params(UndoManager* u_m) :
	App_Params_A{ u_m }
{
	tree.setProperty(ID::app_auto_push_enabled, true, nullptr);
}

const bool TREE::App_Params::auto_push_enabled() {
	return (bool)tree[ID::app_auto_push_enabled];
}

void TREE::App_Params::set_auto_push_enabled(const bool is_true) {
	tree.setProperty(ID::app_auto_push_enabled, is_true, nullptr);
}
