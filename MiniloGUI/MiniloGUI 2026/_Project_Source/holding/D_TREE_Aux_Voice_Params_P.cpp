#include "D_TREE_Aux_Voice_Params_P.h"

#include "C_ENUM_P.h"
#include "C_GET_P.h"
#include "C_ID_Main_P.h"

using namespace ENUM;
using namespace TREE;

Aux_Voice_Params::Aux_Voice_Params(UndoManager* u_m) :
	tree{ ID::tree_aux_voice },
	u_m{ u_m }
{
	for (auto& id : ID::aux_voice_params) {
		auto init_choice = GET::init_choice_for(id);
		tree.setProperty(id, init_choice == -1 ? "Init Program" : (String)init_choice, nullptr);
	}
}

const int TREE::Aux_Voice_Params::amp_mod_by_velo_amt() {
	return (int)tree[ID::avp_amp_mod_by_velo_amt];
}

void TREE::Aux_Voice_Params::set_amp_mod_by_velo_amt(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_amp_mod_by_velo_amt, std::clamp(s, 0, 127), u_m);
}

const int TREE::Aux_Voice_Params::fine_tune() {
	return (int)tree[ID::avp_fine_tune];
}

void TREE::Aux_Voice_Params::set_fine_tune(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_fine_tune, std::clamp(s, 0, 100), u_m);
}

const int TREE::Aux_Voice_Params::flex_sli_bend_limit(const bool pos) {
	return (int)tree[pos ? ID::avp_flex_sli_bend_pos : ID::avp_flex_sli_bend_neg];
}

void TREE::Aux_Voice_Params::set_flex_sli_bend_limit(const bool pos, const int s) {
	auto& id = pos ? ID::avp_flex_sli_bend_pos : ID::avp_flex_sli_bend_neg;
	u_m->beginNewTransaction();
	tree.setProperty(id, std::clamp(s, 0, 11), u_m);
}

const int TREE::Aux_Voice_Params::flex_sli_range() {
	return (int)tree[ID::avp_flex_sli_range];
}

void TREE::Aux_Voice_Params::set_flex_sli_range(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_flex_sli_range, std::clamp(s, 0, 200), u_m);
}

const int TREE::Aux_Voice_Params::flex_sli_target() {
	return (int)tree[ID::avp_flex_sli_target];
}

void TREE::Aux_Voice_Params::set_flex_sli_target(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_flex_sli_target, std::clamp(s, 0, 28), u_m);
}

const int TREE::Aux_Voice_Params::keyboard_octave() {
	return (int)tree[ID::avp_keyboard_octave];
}

void TREE::Aux_Voice_Params::set_keyboard_octave(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_keyboard_octave, std::clamp(s, 0, 4), u_m);
}

const int TREE::Aux_Voice_Params::level() {
	return (int)tree[ID::avp_level];
}

void TREE::Aux_Voice_Params::set_level(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_level, std::clamp(s, 0, 50), u_m);
}

const bool TREE::Aux_Voice_Params::lfo_sync_bpm_on() {
	return (bool)tree[ID::avp_lfo_sync_bpm_on];
}

void TREE::Aux_Voice_Params::set_lfo_sync_bpm_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_lfo_sync_bpm_on, should_be_on, u_m);
}

const bool TREE::Aux_Voice_Params::lfo_sync_key_on() {
	return (bool)tree[ID::avp_lfo_sync_key_on];
}

void TREE::Aux_Voice_Params::set_lfo_sync_key_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_lfo_sync_key_on, should_be_on, u_m);
}

const bool TREE::Aux_Voice_Params::lfo_sync_voice_on() {
	return (bool)tree[ID::avp_lfo_sync_voice_on];
}

void TREE::Aux_Voice_Params::set_lfo_sync_voice_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_lfo_sync_voice_on, should_be_on, u_m);
}

const int TREE::Aux_Voice_Params::microtune_scale() {
	return (int)tree[ID::avp_microtune_scale];
}

void TREE::Aux_Voice_Params::set_microtune_scale(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_microtune_scale, std::clamp(s, 0, 34), u_m);
}

int TREE::Aux_Voice_Params::microtune_scale_hardware_index(const int scale) {
	return scale < (int)Microtune_Scale::user_scale_1 ? (int)scale : (int)scale + 105;
}

const String TREE::Aux_Voice_Params::name() {
	return tree[ID::avp_name].toString();
}

void TREE::Aux_Voice_Params::set_name(const String& s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_name, s, u_m);
}

const int TREE::Aux_Voice_Params::transpose() {
	return (int)tree[ID::avp_transpose];
}

void TREE::Aux_Voice_Params::set_transpose(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_transpose, std::clamp(s, 0, 24), u_m);
}

const bool TREE::Aux_Voice_Params::porta_mode_on() {
	return (bool)tree[ID::avp_porta_mode_on];
}

void TREE::Aux_Voice_Params::set_porta_mode_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_porta_mode_on, should_be_on, u_m);
}

const bool TREE::Aux_Voice_Params::porta_sync_bpm_on() {
	return (bool)tree[ID::avp_porta_sync_bpm_on];
}

void TREE::Aux_Voice_Params::set_porta_sync_bpm_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_porta_sync_bpm_on, should_be_on, u_m);
}

const int TREE::Aux_Voice_Params::porta_time() {
	return (int)tree[ID::avp_porta_time];
}

void TREE::Aux_Voice_Params::set_porta_time(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_porta_time, std::clamp(s, 0, 127), u_m);
}

const int TREE::Aux_Voice_Params::scale_key() {
	return (int)tree[ID::avp_scale_key];
}

void TREE::Aux_Voice_Params::set_scale_key(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_scale_key, std::clamp(s, 0, 24), u_m);
}

const int TREE::Aux_Voice_Params::voice_mode() {
	return (int)tree[ID::avp_voice_mode];
}

void TREE::Aux_Voice_Params::set_voice_mode(const int s) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_voice_mode, std::clamp(s, 0, 7), u_m);
}

Value TREE::Aux_Voice_Params::get_param_as_value(const String& id) {
	return tree.getPropertyAsValue(id, u_m);
}

std::unique_ptr<XmlElement> TREE::Aux_Voice_Params::get_current_state() {
	auto state{ tree.createXml() };
	if (state)
		state->setTagName(ID::xml_state_aux_voice);
	return state;
}

void TREE::Aux_Voice_Params::replace_state(const ValueTree& new_state) {
	if (new_state.isValid())
		tree.copyPropertiesAndChildrenFrom(new_state, nullptr);
}
