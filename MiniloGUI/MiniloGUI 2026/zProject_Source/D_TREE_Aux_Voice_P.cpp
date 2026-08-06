#include "D_TREE_Aux_Voice_P.h"

#include "C_ID_P.h"
#include "C_VOICE_P.h"
#include "D_SUBTREE_Bit_Loc_AV_P.h"

using AVP = Aux_Voice_Param;

Tree_Aux_Voice_P::Tree_Aux_Voice_P(UndoManager* u_m) :
	tree{ ID::tree_aux_voice },
	tree_bit_loc{ Subtree_Bit_Loc_AV_P::build() },
	u_m{ u_m }
{
	tree.setProperty(String{ (int)AVP::amp_mod_by_velo_amt }, 0, nullptr);
	tree.setProperty(String{ (int)AVP::current_voice_name }, VOICE::init_voice_name, nullptr);
	tree.setProperty(String{ (int)AVP::flex_slider_bend_range_neg }, 1, nullptr);
	tree.setProperty(String{ (int)AVP::flex_slider_bend_range_pos }, 1, nullptr);
	tree.setProperty(String{ (int)AVP::flex_slider_range }, 200, nullptr);
	tree.setProperty(String{ (int)AVP::flex_slider_target }, (int)Flex_Slider_Target::pitch_bend, nullptr);
	tree.setProperty(String{ (int)AVP::keyboard_octave }, 2, nullptr);
	tree.setProperty(String{ (int)AVP::lfo_sync_bpm_on }, false, nullptr);
	tree.setProperty(String{ (int)AVP::lfo_sync_key_on }, true, nullptr);
	tree.setProperty(String{ (int)AVP::lfo_sync_voice_on }, true, nullptr);
	tree.setProperty(String{ (int)AVP::microtune_scale }, (int)Microtune_Scale::equal_temp, nullptr);
	tree.setProperty(String{ (int)AVP::pgm_fine_tune }, 50, nullptr);
	tree.setProperty(String{ (int)AVP::pgm_level }, 25, nullptr);
	tree.setProperty(String{ (int)AVP::pgm_transpose }, 12, nullptr);
	tree.setProperty(String{ (int)AVP::porta_mode_on }, false, nullptr);
	tree.setProperty(String{ (int)AVP::porta_sync_bpm_on }, false, nullptr);
	tree.setProperty(String{ (int)AVP::porta_time }, 0, nullptr);
	tree.setProperty(String{ (int)AVP::scale_key }, 12, nullptr);
	tree.setProperty(String{ (int)AVP::voice_mode }, (int)Voice_Mode::poly, nullptr);
}

const int Tree_Aux_Voice_P::amp_mod_by_velo_amt() {
	return (int)tree[String{ (int)AVP::amp_mod_by_velo_amt }];
}

void Tree_Aux_Voice_P::set_amp_mod_by_velo_amt(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 127);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::amp_mod_by_velo_amt }, setting_clamped, u_m);
}

const String Tree_Aux_Voice_P::current_voice_name() {
	return tree[String{ (int)AVP::current_voice_name }].toString();
}

void Tree_Aux_Voice_P::set_current_voice_name(const String new_setting) {
	if (new_setting.length() < VOICE::voice_name_char_count &&
		new_setting.containsOnly(VOICE::allowed_name_chars))
	{
		u_m->beginNewTransaction();
		tree.setProperty(String{ (int)AVP::current_voice_name }, new_setting, u_m);
	}
}

const int Tree_Aux_Voice_P::flex_slider_bend_range(const bool pos) {
	auto id = pos ? String{ (int)AVP::flex_slider_bend_range_pos } : 
					String{ (int)AVP::flex_slider_bend_range_neg };
	return (int)tree[id];
}

void Tree_Aux_Voice_P::set_flex_slider_bend_range(const bool pos, const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 11);
	auto id = pos ? String{ (int)AVP::flex_slider_bend_range_pos } :
					String{ (int)AVP::flex_slider_bend_range_neg };
	u_m->beginNewTransaction();
	tree.setProperty(id, setting_clamped, u_m);
}

const int Tree_Aux_Voice_P::flex_slider_range() {
	return (int)tree[String{ (int)AVP::flex_slider_range }];
}

void Tree_Aux_Voice_P::set_flex_slider_range(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 200);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::flex_slider_range }, setting_clamped, u_m);
}

const Flex_Slider_Target Tree_Aux_Voice_P::flex_slider_target() {
	auto target_int = (int)tree[String{ (int)AVP::flex_slider_target }];
	return Flex_Slider_Target{ target_int };
}

void Tree_Aux_Voice_P::set_flex_slider_target(const Flex_Slider_Target new_setting) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::flex_slider_target }, (int)new_setting, u_m);
}

const int Tree_Aux_Voice_P::keyboard_octave() {
	return (int)tree[String{ (int)AVP::keyboard_octave }];
}

void Tree_Aux_Voice_P::set_keyboard_octave(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 4);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::keyboard_octave }, setting_clamped, u_m);
}

const bool Tree_Aux_Voice_P::lfo_sync_bpm_on() {
	return (bool)tree[String{ (int)AVP::lfo_sync_bpm_on }];
}

void Tree_Aux_Voice_P::set_lfo_sync_bpm_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::lfo_sync_bpm_on }, should_be_on, u_m);
}

const bool Tree_Aux_Voice_P::lfo_sync_key_on() {
	return (bool)tree[String{ (int)AVP::lfo_sync_key_on }];
}

void Tree_Aux_Voice_P::set_lfo_sync_key_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::lfo_sync_key_on }, should_be_on, u_m);
}

const bool Tree_Aux_Voice_P::lfo_sync_voice_on() {
	return (bool)tree[String{ (int)AVP::lfo_sync_voice_on }];
}

void Tree_Aux_Voice_P::set_lfo_sync_voice_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::lfo_sync_voice_on }, should_be_on, u_m);
}

const Microtune_Scale Tree_Aux_Voice_P::microtune_scale() {
	return Microtune_Scale{ (int)tree[String{ (int)AVP::microtune_scale }] };
}

void Tree_Aux_Voice_P::set_microtune_scale(const Microtune_Scale new_setting) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::microtune_scale }, (int)new_setting, u_m);
}

int Tree_Aux_Voice_P::microtune_scale_hardware_index(const Microtune_Scale scale) {
	if (scale < Microtune_Scale::user_scale_1)
		return (int)scale;
	else
		return (int)scale + 105;
}

const int Tree_Aux_Voice_P::pgm_fine_tune() {
	return (int)tree[String{ (int)AVP::pgm_fine_tune }];
}

void Tree_Aux_Voice_P::set_pgm_fine_tune(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 100);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::pgm_fine_tune }, setting_clamped, u_m);
}

const int Tree_Aux_Voice_P::pgm_level() {
	return (int)tree[String{ (int)AVP::pgm_level }];
}

void Tree_Aux_Voice_P::set_pgm_level(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 50);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::pgm_level }, setting_clamped, u_m);
}

const int Tree_Aux_Voice_P::pgm_transpose() {
	return (int)tree[String{ (int)AVP::pgm_transpose }];
}

void Tree_Aux_Voice_P::set_pgm_transpose(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 24);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::pgm_transpose }, setting_clamped, u_m);
}

const bool Tree_Aux_Voice_P::porta_mode_on() {
	return (bool)tree[String{ (int)AVP::porta_mode_on }];
}

void Tree_Aux_Voice_P::set_porta_mode_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::porta_mode_on }, should_be_on, u_m);
}

const bool Tree_Aux_Voice_P::porta_sync_bpm_on() {
	return (bool)tree[String{ (int)AVP::porta_sync_bpm_on }];
}

void Tree_Aux_Voice_P::set_porta_sync_bpm_on(const bool should_be_on) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::porta_sync_bpm_on }, should_be_on, u_m);
}

const int Tree_Aux_Voice_P::porta_time() {
	return (int)tree[String{ (int)AVP::porta_time }];
}

void Tree_Aux_Voice_P::set_porta_time(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 127);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::porta_time }, setting_clamped, u_m);
}

const int Tree_Aux_Voice_P::scale_key() {
	return (int)tree[String{ (int)AVP::scale_key }];
}

void Tree_Aux_Voice_P::set_scale_key(const int new_setting) {
	auto setting_clamped = std::clamp(new_setting, 0, 24);
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::scale_key }, setting_clamped, u_m);
}

const Voice_Mode Tree_Aux_Voice_P::voice_mode() {
	return Voice_Mode{ (int)tree[String{ (int)AVP::voice_mode }] };
}

void Tree_Aux_Voice_P::set_voice_mode(const Voice_Mode new_setting) {
	u_m->beginNewTransaction();
	tree.setProperty(String{ (int)AVP::voice_mode }, (int)new_setting, u_m);
}

Value Tree_Aux_Voice_P::get_param_as_value(const Aux_Voice_Param param) {
	return tree.getPropertyAsValue(String{ (int)param }, u_m);
}

const int Tree_Aux_Voice_P::byte_index_for_param_bit(const Aux_Voice_Param param, const int b) const {
	if (param != AVP::current_voice_name) {
		auto bit_locations = tree_bit_loc.getChildWithName(String{ (int)param });
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto byte_index{ bit_locations[bit_id].toString() };
			byte_index = byte_index.fromFirstOccurrenceOf("byte_", false, false);
			byte_index = byte_index.upToFirstOccurrenceOf("__", false, false);
			return byte_index.getIntValue();
		}
	}
	return -1;
}

const int Tree_Aux_Voice_P::bit_index_for_param_bit(const Aux_Voice_Param param, const int b) const {
	if (param != AVP::current_voice_name) {
		auto bit_locations = tree_bit_loc.getChildWithName(String{ (int)param });
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto bit_index{ bit_locations[bit_id].toString() };
			bit_index = bit_index.fromFirstOccurrenceOf("bit_", false, false);
			return bit_index.getIntValue();
		}
	}
	return -1;
}

std::unique_ptr<XmlElement> Tree_Aux_Voice_P::get_state() {
	auto state{ tree.createXml() };
	if (state)
		state->setTagName(ID::xml_state_aux_voice);
	return state;
}

void Tree_Aux_Voice_P::replace_state(const ValueTree& new_state) {
	if (new_state.isValid())
		tree.copyPropertiesAndChildrenFrom(new_state, nullptr);
}
