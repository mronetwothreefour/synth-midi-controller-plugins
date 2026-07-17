#include "D_X_G_Data_Hub_B.h"

#include "C_EXP_P.h"
#include "C_ID_B.h"
#include "D_LAYOUT_Exposed_B.h"

Data_Hub_B::Data_Hub_B(AudioProcessor* processor) :
	undo_mngr{ new UndoManager{} },
	exposed_state{ new State{ *processor, undo_mngr.get(), ID::tree_exp_param_state,
				   Layout_Exposed_B::build(exposed_info) } },
	scale_factor{ 1.0f }
{
}

const Tree_Exposed_Info_P& Data_Hub_B::get_exposed_info() {
	return exposed_info;
}

UndoManager* Data_Hub_B::get_undo_mngr() {
	return undo_mngr.get();
}

State* Data_Hub_B::get_exposed_state() {
	return exposed_state.get();
}

float& Data_Hub_B::get_scale_factor() {
	return scale_factor;
}

Data_Hub_B::~Data_Hub_B() {
	exposed_state = nullptr;
	undo_mngr = nullptr;
}
