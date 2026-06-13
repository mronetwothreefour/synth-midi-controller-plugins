#include "D_TREE_Additional_Voice_P.h"

#include "C_ID_P.h"
#include "D_SUBTREE_Bit_Loc_AV_P.h"

Tree_Additional_Voice_P::Tree_Additional_Voice_P(UndoManager* u_m) :
	tree{ ID::tree_additional_voice },
	tree_bit_loc{ Subtree_Bit_Loc_AV_P::build() },
	u_m{ u_m }
{
	set_voice_mode(Voice_Mode::poly);
	set_keyboard_octave(2);
	set_slider_target(Slider_Target::pitch_bend);
	set_slider_range(200);
	set_slider_range_pitch_bend(true, 1);
	set_slider_range_pitch_bend(false, 1);
	set_lfo_sync_bpm_on(false);
	set_lfo_sync_key_on(true);
	set_lfo_sync_voice_on(true);
	set_porta_time(0);
	set_porta_mode_on(false);
	set_porta_sync_bpm_on(false);
	set_amp_mod_by_velo_amt(0);
	set_pgm_level(25);
	set_microtune_scale(Microtune_Scale::equal_temp);
	set_scale_key(12);
	set_pgm_fine_tune(50);
	set_pgm_transpose(12);
	set_current_voice_name(VOICE::init_voice_name);
}

const Voice_Mode Tree_Additional_Voice_P::voice_mode() {
	return Voice_Mode{ (int)tree[ID::avp_00_voice_mode] };
}

void Tree_Additional_Voice_P::set_voice_mode(const Voice_Mode new_setting) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_00_voice_mode, (int)new_setting, u_m);
}

const int Tree_Additional_Voice_P::keyboard_octave() {
	return (int)tree[ID::avp_01_keyboard_octave];
}

void Tree_Additional_Voice_P::set_keyboard_octave(const int new_setting) {
	if (new_setting > -1 && new_setting < 5) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_01_keyboard_octave, new_setting, u_m);
	}
}

const Slider_Target Tree_Additional_Voice_P::slider_target() {
	return Slider_Target{ (int)tree[ID::avp_02_slider_target] };
}

void Tree_Additional_Voice_P::set_slider_target(const Slider_Target new_setting) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_02_slider_target, (int)new_setting, u_m);
}

const int Tree_Additional_Voice_P::slider_range() {
	return (int)tree[ID::avp_03_slider_range];
}

void Tree_Additional_Voice_P::set_slider_range(const int new_setting) {
	if (new_setting > -1 && new_setting < 201) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_03_slider_range, new_setting, u_m);
	}
}

const int Tree_Additional_Voice_P::slider_range_pitch_bend(const bool pos_limit) {
	auto& id = pos_limit ? ID::avp_04_slider_range_pitch_bend_pos : ID::avp_05_slider_range_pitch_bend_neg;
	return (int)tree[id];
}

void Tree_Additional_Voice_P::set_slider_range_pitch_bend(const bool pos_limit, const int new_setting) {
	if (new_setting > -1 && new_setting < 12) {
		auto& id = pos_limit ? ID::avp_04_slider_range_pitch_bend_pos : ID::avp_05_slider_range_pitch_bend_neg;
		u_m->beginNewTransaction();
		tree.setProperty(id, new_setting, u_m);
	}
}

const bool Tree_Additional_Voice_P::lfo_sync_bpm_on() {
	return (bool)tree[ID::avp_06_lfo_sync_bpm_on];
}

void Tree_Additional_Voice_P::set_lfo_sync_bpm_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_06_lfo_sync_bpm_on, should_be_on, u_m);
}

const bool Tree_Additional_Voice_P::lfo_sync_key_on() {
	return (bool)tree[ID::avp_07_lfo_sync_key_on];
}

void Tree_Additional_Voice_P::set_lfo_sync_key_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_07_lfo_sync_key_on, should_be_on, u_m);
}

const bool Tree_Additional_Voice_P::lfo_sync_voice_on() {
	return (bool)tree[ID::avp_08_lfo_sync_voice_on];
}

void Tree_Additional_Voice_P::set_lfo_sync_voice_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_08_lfo_sync_voice_on, should_be_on, u_m);
}

const int Tree_Additional_Voice_P::porta_time() {
	return (int)tree[ID::avp_09_porta_time];
}

void Tree_Additional_Voice_P::set_porta_time(const int new_setting) {
	if (new_setting > -1 && new_setting < 128) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_09_porta_time, new_setting, u_m);
	}
}

const bool Tree_Additional_Voice_P::porta_mode_on() {
	return (bool)tree[ID::avp_10_porta_mode_on];
}

void Tree_Additional_Voice_P::set_porta_mode_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_10_porta_mode_on, should_be_on, u_m);
}

const bool Tree_Additional_Voice_P::porta_sync_bpm_on() {
	return (bool)tree[ID::avp_11_porta_sync_bpm_on];
}

void Tree_Additional_Voice_P::set_porta_sync_bpm_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_11_porta_sync_bpm_on, should_be_on, u_m);
}

const int Tree_Additional_Voice_P::amp_mod_by_velo_amt() {
	return (int)tree[ID::avp_12_amp_mod_by_velo_amt];
}

void Tree_Additional_Voice_P::set_amp_mod_by_velo_amt(const int new_setting) {
	if (new_setting > -1 && new_setting < 128) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_12_amp_mod_by_velo_amt, new_setting, u_m);
	}
}

const int Tree_Additional_Voice_P::pgm_level() {
	return (int)tree[ID::avp_13_pgm_level];
}

void Tree_Additional_Voice_P::set_pgm_level(const int new_setting) {
	if (new_setting > -1 && new_setting < 51) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_13_pgm_level, new_setting, u_m);
	}
}

const Microtune_Scale Tree_Additional_Voice_P::microtune_scale() {
	return Microtune_Scale{ (int)tree[ID::avp_14_microtune_scale] };
}

void Tree_Additional_Voice_P::set_microtune_scale(const Microtune_Scale new_setting) {
	u_m->beginNewTransaction();
	tree.setProperty(ID::avp_14_microtune_scale, (int)new_setting, u_m);
}

int Tree_Additional_Voice_P::microtune_scale_hardware_index(const Microtune_Scale scale) {
	if (scale < Microtune_Scale::user_scale_1)
		return (int)scale;
	else
		return (int)scale + 105;
}

const int Tree_Additional_Voice_P::scale_key() {
	return (int)tree[ID::avp_15_scale_key];
}

void Tree_Additional_Voice_P::set_scale_key(const int new_setting) {
	if (new_setting > -1 && new_setting < 25) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_15_scale_key, new_setting, u_m);
	}
}

const int Tree_Additional_Voice_P::pgm_fine_tune() {
	return (int)tree[ID::avp_16_pgm_fine_tune];
}

void Tree_Additional_Voice_P::set_pgm_fine_tune(const int new_setting) {
	if (new_setting > -1 && new_setting < 101) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_16_pgm_fine_tune, new_setting, u_m);
	}
}

const int Tree_Additional_Voice_P::pgm_transpose() {
	return (int)tree[ID::avp_17_pgm_transpose];
}

void Tree_Additional_Voice_P::set_pgm_transpose(const int new_setting) {
	if (new_setting > -1 && new_setting < 25) {
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_17_pgm_transpose, new_setting, u_m);
	}
}

const String Tree_Additional_Voice_P::current_voice_name() {
	return tree[ID::avp_current_voice_name].toString();
}

void Tree_Additional_Voice_P::set_current_voice_name(const String new_setting) {
	if (new_setting.length() < VOICE::voice_name_char_count &&
		new_setting.containsOnly(VOICE::allowed_name_chars))
	{
		u_m->beginNewTransaction();
		tree.setProperty(ID::avp_current_voice_name, new_setting, u_m);
	}
}

Value Tree_Additional_Voice_P::get_param_as_value(const Identifier param_id) {
	return tree.getPropertyAsValue(param_id, u_m);
}

const int Tree_Additional_Voice_P::byte_index_for_param_bit(const Identifier id, const int b) const {
	auto bit_locations = tree_bit_loc.getChildWithName(id);
	if (b < bit_locations.getNumProperties()) {
		Identifier bit_id{ "bit_" + (String)b };
		auto byte_index{ bit_locations[bit_id].toString() };
		byte_index = byte_index.fromFirstOccurrenceOf("byte_", false, false);
		byte_index = byte_index.upToFirstOccurrenceOf("__", false, false);
		return byte_index.getIntValue();
	}
	return -1;
}

const int Tree_Additional_Voice_P::bit_index_for_param_bit(const Identifier id, const int b) const {
	auto bit_locations = tree_bit_loc.getChildWithName(id);
	if (b < bit_locations.getNumProperties()) {
		Identifier bit_id{ "bit_" + (String)b };
		auto bit_index{ bit_locations[bit_id].toString() };
		bit_index = bit_index.fromFirstOccurrenceOf("bit_", false, false);
		return bit_index.getIntValue();
	}
	return -1;
}

std::unique_ptr<XmlElement> Tree_Additional_Voice_P::get_state() {
	auto state{ tree.createXml() };
	if (state)
		state->setTagName(ID::xml_state_additional_voice);
	return state;
}

void Tree_Additional_Voice_P::replace_state(const ValueTree& new_state) {
	if (new_state.isValid())
		tree.copyPropertiesAndChildrenFrom(new_state, nullptr);
}
