#include "D_X_G_Data_Hub_A.h"

#include "C_NAME_P.h"
#include "D_BUILD_Layout_A.h"

using namespace TREE;

Data_Hub_A::Data_Hub_A(AudioProcessor* processor) :
	undo_mngr{ new UndoManager{} },
	app_params{ undo_mngr.get() },
	exposed_param_state{ new State{ *processor, undo_mngr.get(), NAME::state_exp_tree,
									BUILD::Layout_A::exposed() } },
	scale_f{ 1.0f }
{}

App_Params& Data_Hub_A::get_app_params() {
	return app_params;
}

State* Data_Hub_A::get_exposed_params_state() {
	return exposed_param_state.get();
}

float& Data_Hub_A::get_scale_f() {
	return scale_f;
}

UndoManager* Data_Hub_A::get_undo_mngr() {
	return undo_mngr.get();
}

Data_Hub_A::~Data_Hub_A() {
	exposed_param_state = nullptr;
	undo_mngr = nullptr;
}
