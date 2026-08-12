#include "D_X_G_Data_Hub_A.h"

#include "C_ID_A.h"
#include "D_BUILD_Exp_Param_Layout_A.h"

Data_Hub_A::Data_Hub_A(AudioProcessor* processor) :
	undo_mngr{ new UndoManager{} },
	exposed_param_state{ new State{ *processor, undo_mngr.get(), ID::tree_exp_param_state,
									Exp_Param_Layout_A::build() } },
	scale_factor{ 1.0f }
{}

UndoManager* Data_Hub_A::get_undo_mngr() {
	return undo_mngr.get();
}

State* Data_Hub_A::get_exposed_params_state() {
	return exposed_param_state.get();
}

float& Data_Hub_A::get_scale_factor() {
	return scale_factor;
}

Data_Hub_A::~Data_Hub_A() {
	exposed_param_state = nullptr;
	undo_mngr = nullptr;
}
