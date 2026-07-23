#include "D_X_G_Data_Hub_G.h"

#include "C_EXP_P.h"
#include "C_ID_G.h"

Data_Hub_G::Data_Hub_G(AudioProcessor* processor) :
	undo_mngr{ new UndoManager{} },
	exposed_state{ new State{ *processor, undo_mngr.get(), ID::tree_exp_param_state,
							  exposed_info.build_param_layout() }},
	scale_factor{ 1.0f }
{
}

const Tree_Exposed_Info_P& Data_Hub_G::get_exposed_info() {
	return exposed_info;
}

UndoManager* Data_Hub_G::get_undo_mngr() {
	return undo_mngr.get();
}

State* Data_Hub_G::get_exposed_state() {
	return exposed_state.get();
}

float& Data_Hub_G::get_scale_factor() {
	return scale_factor;
}

Data_Hub_G::~Data_Hub_G() {
	exposed_state = nullptr;
	undo_mngr = nullptr;
}
