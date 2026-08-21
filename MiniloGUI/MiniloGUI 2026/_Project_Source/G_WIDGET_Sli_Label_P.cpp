#include "G_WIDGET_Sli_Label_P.h"

#include "C_ENUM_P.h"
#include "C_GET_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"
#include "D_BUILD_Font_For_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace ENUM;
using namespace MISC;
using namespace NAME;
using namespace WIDGET;

Slider_Label::Slider_Label(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider }
{}

void Slider_Label::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setBounds(getLocalBounds());
	edit->setBounds(getLocalBounds().translated(0, -1));
	edit->applyFontToAllText(Font_For::knob_txt_editor(scale_factor));
	auto n = getName();
	if (n == lbl_lfo_rate)
		edit->setInputRestrictions(avp.lfo_sync_bpm_on() ? 2 : 4, allowed_chars_u_int);
	if (n == lbl_lpf_eg_int)
		edit->setInputRestrictions(4, allowed_chars_s_int);
	if (n == lbl_osc_2_pitch_eg_int)
		edit->setInputRestrictions(5, allowed_chars_s_int);
	if (n == lbl_osc_pitch_fine)
		edit->setInputRestrictions(5, allowed_chars_s_int);
	if (n == lbl_u_10_bit_int)
		edit->setInputRestrictions(4, allowed_chars_u_int);
	if (n == lbl_voice_mode_depth) {
		auto mode = Voice_Mode(avp.voice_mode());
		switch (mode)
		{
		case Voice_Mode::poly:
			edit->setInputRestrictions(1, allowed_chars_vmode_poly);
			break;
		case Voice_Mode::duo:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			break;
		case Voice_Mode::unison:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			break;
		case Voice_Mode::mono:
			edit->setInputRestrictions(4, allowed_chars_u_int);
			break;
		case Voice_Mode::chord:
			edit->setInputRestrictions(2, allowed_chars_u_int);
		case Voice_Mode::delay:
			edit->setInputRestrictions(4, allowed_chars_u_int);
			break;
		case Voice_Mode::arp:
			edit->setInputRestrictions(2, allowed_chars_u_int);
			break;
		case Voice_Mode::sidechain:
			edit->setInputRestrictions(4, allowed_chars_u_int);
			break;
		default:
			break;
		}
	}
	edit->setTooltip(Tip_For::knob_txt_editor(n, avp));
	edit->selectAll();
}

void Slider_Label::set_text_to_stored_choice() {
	auto v{ roundToInt(parent_slider->getValue()) };
	auto n = getName();
	String c{ choices_curt[v] };
	if (n == lbl_lfo_rate || n == lbl_voice_mode_depth) {
		if (n == lbl_lfo_rate)
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
	auto n = getName();
	if (n == lbl_lfo_rate)
		on_text_change_lfo_rate();
	if (n == lbl_lpf_eg_int || n == lbl_osc_2_pitch_eg_int || n == lbl_osc_pitch_fine)
		on_text_change_get_best_match();
	if (n == lbl_u_10_bit_int)
		on_text_change_unsigned_10_bit();
	if (n == lbl_voice_mode_depth)
		on_text_change_voice_mode_depth();
}

void Slider_Label::on_text_change_get_best_match() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto input_val{ new_text.getIntValue() };
		parent_slider->setValue(parent_slider->get_best_display_value_match(input_val));
	}
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_lfo_rate() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		if (avp.lfo_sync_bpm_on())
			new_val *= 64.0f;
		parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_unsigned_10_bit() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}

void Slider_Label::on_text_change_voice_mode_depth() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		auto mode = Voice_Mode(avp.voice_mode());
		switch (mode)
		{
		case Voice_Mode::poly: parent_slider->setValue(new_val * 114.0f); break;
		case Voice_Mode::duo: parent_slider->setValue(new_val * 20.0f); break;
		case Voice_Mode::unison: parent_slider->setValue(new_val * 20.0f); break;
		case Voice_Mode::mono: parent_slider->setValue(new_val); break;
		case Voice_Mode::chord: parent_slider->setValue(new_val * 74.0f); break;
		case Voice_Mode::delay: parent_slider->setValue(new_val * 86.0f); break;
		case Voice_Mode::arp: parent_slider->setValue(new_val * 79.0f); break;
		case Voice_Mode::sidechain: parent_slider->setValue(new_val); break;
		default: set_text_to_stored_choice(); break;
		}
	}
	set_text_to_stored_choice();
}
