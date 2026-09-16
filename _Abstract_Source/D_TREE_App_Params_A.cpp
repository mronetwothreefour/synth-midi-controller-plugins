#include "D_TREE_App_Params_A.h"

#include "C_ID_A.h"
#include "C_NAME_P.h"

using namespace TREE;

App_Params_A::App_Params_A(UndoManager* u_m) :
	tree{ NAME::state_app_tree },
	u_m{ u_m }
{
	tree.setProperty(ID::app_scale_i, 1, nullptr);
}

const int App_Params_A::scale_i() {
	return (int)tree[ID::app_scale_i];
}

void App_Params_A::set_scale_i(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 25, 200);
	tree.setProperty(ID::app_scale_i, setting_clamped, u_m);
}

void App_Params_A::set_scale_i_excluding(const int new_setting, ValueTree::Listener* l) {
	auto setting_clamped = std::clamp(new_setting, 25, 200);
	tree.setPropertyExcludingListener(l, ID::app_scale_i, setting_clamped, nullptr);
}

void App_Params_A::add_listener(ValueTree::Listener* l) {
	tree.addListener(l);
}

void App_Params_A::remove_listener(ValueTree::Listener* listener) {
	tree.removeListener(listener);
}

Value App_Params_A::get_param_as_value(const String& id) {
	return tree.getPropertyAsValue(id, u_m);
}

std::unique_ptr<XmlElement> App_Params_A::get_current_state() {
	auto state{ tree.createXml() };
	if (state)
		state->setTagName(NAME::state_app_xml);
	return state;
}

void App_Params_A::replace_state(const ValueTree& new_state) {
	if (new_state.isValid())
		tree.copyPropertiesAndChildrenFrom(new_state, nullptr);
}
