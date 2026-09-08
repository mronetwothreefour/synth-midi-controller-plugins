#include "D_TREE_Matrix_Mod_Params_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"

using namespace TREE;

Matrix_Mod_Params::Matrix_Mod_Params(UndoManager* u_m) :
	tree{ ID::tree_matrix_mod },
	u_m{ u_m }
{
	for (auto& id : ID::matrix_mod_params) {
		auto init_choice = GET::init_choice_for(id);
		tree.setProperty(id, init_choice, nullptr);
	}
}

const int Matrix_Mod_Params::current_setting_for(const String& id) {
	return (int)tree[id];
}

void Matrix_Mod_Params::set_param(const String& id, const int s) {
	u_m->beginNewTransaction();
	auto max = id.contains("amt") ? 127 : id.contains("dst") ? 32 : 20;
	tree.setProperty(id, std::clamp(s, 0, max), u_m);
}

Value Matrix_Mod_Params::get_param_as_value(const String& id) {
	return tree.getPropertyAsValue(id, u_m);
}

std::unique_ptr<XmlElement> Matrix_Mod_Params::get_current_state() {
	auto state{ tree.createXml() };
	if (state)
		state->setTagName(ID::xml_state_matrix_mod);
	return state;
}

void Matrix_Mod_Params::replace_state(const ValueTree& new_state) {
	if (new_state.isValid())
		tree.copyPropertiesAndChildrenFrom(new_state, nullptr);
}
