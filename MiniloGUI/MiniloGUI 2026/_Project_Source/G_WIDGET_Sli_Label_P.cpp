#include "G_WIDGET_Sli_Label_P.h"

#include "C_ENUM_P.h"
#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace ENUM;
using namespace MISC;
using namespace WIDGET;

Slider_Label::Slider_Label(const std::string& param_id, Data_Hub* hub,
						   Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider }
{}

void Slider_Label::editor_mods_p(TextEditor* edit) {
	auto id = parent_sli->getComponentID();
	if (id == ID::exp_lfo_rate) {
		auto synced = avp.lfo_sync_bpm_on();
		edit->setInputRestrictions(synced ? 2 : 4, allowed_chars_u_int);
		auto tip = synced ? Tip_For::from_SL(SL::knob_txt_edit_lfo_synced_tip) :
							Tip_For::from_SL(SL::knob_txt_edit_lfo_unsynced_tip);
		edit->setTooltip(tip);
	}
	if (id == ID::exp_voice_mode_depth) {
		auto mode = Voice_Mode(avp.voice_mode());
		switch (mode)
		{
		case Voice_Mode::poly:
			edit->setInputRestrictions(1, allowed_chars_vmode_poly);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_0_tip));
			break;
		case Voice_Mode::duo:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_1_2_tip));
			break;
		case Voice_Mode::unison:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_1_2_tip));
			break;
		case Voice_Mode::mono:
			edit->setInputRestrictions(4, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_3_tip));
			break;
		case Voice_Mode::chord:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_4_tip));
			break;
		case Voice_Mode::delay:
			edit->setInputRestrictions(4, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_5_tip));
			break;
		case Voice_Mode::arp:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_6_tip));
			break;
		case Voice_Mode::sidechain:
			edit->setInputRestrictions(4, allowed_chars_u_int);
			edit->setTooltip(Tip_For::from_SL(SL::knob_txt_edit_voice_mode_7_tip));
			break;
		default:
			break;
		}
	}
	edit->setText(getText().removeCharacters(" +%"));
}

void Slider_Label::set_text_to_stored_choice() {
	auto v{ roundToInt(parent_sli->getValue()) };
	auto id = parent_sli->getComponentID();
	String c{ choices_curt[v] };
	if (id == ID::exp_lfo_rate || id == ID::exp_voice_mode_depth) {
		if (id == ID::exp_lfo_rate)
			c = avp.lfo_sync_bpm_on() ? c.fromFirstOccurrenceOf("|", false, false) :
										c.upToFirstOccurrenceOf("|", false, false);
		else {
			auto m = String{ avp.voice_mode() + 1 } + ":";
			if (m == "2:" || m == "3:")
				m = "2&3:";
			c = c.fromFirstOccurrenceOf(m, false, false).upToFirstOccurrenceOf("|", false, false);
		}
	}
	setText(c, dontSendNotification);
}

void Slider_Label::on_text_change() {
	auto id = parent_sli->getComponentID();
	if (id == ID::exp_lfo_rate) {
		on_text_change_lfo_rate();
		return;
	}
	if (id.endsWith("_eg_int") || id.endsWith("_pitch_fine")) {
		on_text_change_get_best_match();
		return;
	}
	if (id == ID::avp_scale_key) {
		on_text_change_scale_key();
		return;
	}
	if (id == ID::exp_voice_mode_depth) {
		on_text_change_voice_mode_depth();
		return;
	}
	on_text_change_integer();
}

void Slider_Label::on_text_change_get_best_match() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto input_val{ new_text.getIntValue() };
		parent_sli->setValue(parent_sli->get_best_display_value_match(input_val));
	}
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_integer() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		parent_sli->setValue(new_val);
	}
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_lfo_rate() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		if (avp.lfo_sync_bpm_on())
			new_val *= 64.0f;
		parent_sli->setValue(new_val);
	}
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_scale_key() {
	auto new_text{ getText() };
	if (new_text.containsAnyOf(pitch_name_chars)) {
		for (int i = 0; i < choices_curt.size(); ++i) {
			if (choices_curt[i].removeCharacters(" ") == new_text)
				parent_sli->setValue((float)i);
		}
	}
	else
		parent_sli->setValue(new_text.getFloatValue());
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_voice_mode_depth() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		auto mode = Voice_Mode(avp.voice_mode());
		switch (mode)
		{
		case Voice_Mode::poly: parent_sli->setValue(new_val * 114.0f); break;
		case Voice_Mode::duo: parent_sli->setValue(new_val * 20.0f); break;
		case Voice_Mode::unison: parent_sli->setValue(new_val * 20.0f); break;
		case Voice_Mode::mono: parent_sli->setValue(new_val); break;
		case Voice_Mode::chord: parent_sli->setValue(new_val * 74.0f); break;
		case Voice_Mode::delay: parent_sli->setValue(new_val * 86.0f); break;
		case Voice_Mode::arp: parent_sli->setValue(new_val * 79.0f); break;
		case Voice_Mode::sidechain: parent_sli->setValue(new_val); break;
		default: set_text_to_stored_choice(); break;
		}
	}
	set_text_to_stored_choice();
}
