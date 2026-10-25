#include "D_X_G_Data_Hub_A.h"

#include "C_ID_Main_P.h"
#include "C_NAME_P.h"
#include "D_BUILD_Layout_A.h"

using namespace TREE;

Data_Hub_A::Data_Hub_A(AudioProcessor* processor) :
	undo_mngr{ new UndoManager{} },
	app_params{ undo_mngr.get() },
	exposed_param_state{ new State{ *processor, undo_mngr.get(), NAME::state_exp_tree,
									BUILD::Layout_A::exposed() } },
	scale_f{ 1.0f }
{
	for (auto& param_id : ID::exp_params) {
		auto param_val = exposed_param_state->getParameterAsValue(param_id);
		exp_transmitters.add(new MIDI::Exp_Transmitter{ param_id, param_val, outgoing_midi_buffer });
	}
}

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

MidiBuffer& Data_Hub_A::get_outgoing_midi_buffer() {
	return outgoing_midi_buffer;
}

Data_Hub_A::~Data_Hub_A() {
	outgoing_midi_buffer.clear();
	exp_transmitters.clear();
	exposed_param_state = nullptr;
	undo_mngr = nullptr;
}
