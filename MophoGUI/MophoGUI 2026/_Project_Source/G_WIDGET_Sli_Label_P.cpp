#include "G_WIDGET_Sli_Label_P.h"

#include "C_GET_P.h"
#include "C_NAME_P.h"
#include "D_BUILD_Font_For_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace NAME;
using namespace WIDGET;

Slider_Label::Slider_Label(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider }
{
	if (getName() == lbl_voice_name_char)
		editable = false;
}

void Slider_Label::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds().translated(0, -1));
	edit->applyFontToAllText(Font_For::knob_text_editor(scale_factor));
	auto n = getName();
	if (n == lbl_bend_range)
		edit->setInputRestrictions(2, allowed_char_u_int);
	if (n == NAME::lbl_clock_tempo)
		edit->setInputRestrictions(3, allowed_char_u_int);
	if (n == NAME::lbl_lfo_freq)
		edit->setInputRestrictions(5, allowed_char_lfo_freq);
	if (n == NAME::lbl_lpf_freq)
		edit->setInputRestrictions(4, allowed_char_pitch);
	if (n == NAME::lbl_osc_fine)
		edit->setInputRestrictions(3, allowed_char_s_int);
	if (n == NAME::lbl_osc_pitch)
		edit->setInputRestrictions(4, allowed_char_pitch);
	if (n == NAME::lbl_osc_shape)
		edit->setInputRestrictions(4, allowed_char_osc_shape);
	if (n == NAME::lbl_osc_slop)
		edit->setInputRestrictions(1, allowed_char_osc_slop);
	if (n == NAME::lbl_seq_step) {
		edit->setInputRestrictions(4, allowed_char_seq_step);
		edit->applyFontToAllText(Font_For::seq_step(scale_factor));
	}
	if (n == NAME::lbl_seq_step_trk_1) {
		edit->setInputRestrictions(4, allowed_char_seq_step_trk_1);
		edit->applyFontToAllText(Font_For::seq_step(scale_factor));
	}
	if (n == NAME::lbl_s_8_bit_int)
		edit->setInputRestrictions(4, allowed_char_s_int);
	if (n == NAME::lbl_u_7_bit_int)
		edit->setInputRestrictions(3, allowed_char_u_int);
	edit->setTooltip(Tip_For::knob_text_editor(n));
	auto txt = getText().removeCharacters(" ");
	if (n != NAME::lbl_seq_step && n != NAME::lbl_seq_step_trk_1)
		txt = txt.removeCharacters("+");
	if (n == NAME::lbl_bend_range)
		txt = txt.removeCharacters("/-");
	edit->setText(txt);
	edit->selectAll();
}

void Slider_Label::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_slider->getValue()) };
	auto n = getName();
	if (n == NAME::lbl_lfo_freq)
		parent_slider->for_pitch = choice_num >= 90 && choice_num < 151;
	auto choice_name{ choices_curt[choice_num] };
	if (n == NAME::lbl_seq_step || n == NAME::lbl_seq_step_trk_1) {
		if (!parent_slider->for_pitch && choice_num < 126)
			choice_name = String{ choice_num };
	}
	setText(choice_name, dontSendNotification);
}

void Slider_Label::on_text_change() {
	auto n = getName();
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -128.0f };
	if (new_text.isNotEmpty()) {
		if (n == NAME::lbl_osc_pitch || n == NAME::lbl_lpf_freq)
			new_val = text_to_float_osc_pitch_and_lpf_freq(new_text);
		if (n == NAME::lbl_osc_shape)
			new_val = text_to_float_osc_shape(new_text);
		if (n == NAME::lbl_lfo_freq)
			new_val = text_to_float_lfo_freq(new_text);
		if (n == NAME::lbl_seq_step || n == NAME::lbl_seq_step_trk_1)
			new_val = text_to_float_seq_step(new_text);
		if (n == NAME::lbl_bend_range || n == NAME::lbl_clock_tempo || n == NAME::lbl_osc_fine ||
			n == NAME::lbl_osc_slop || n == NAME::lbl_s_8_bit_int || n == NAME::lbl_u_7_bit_int)
		{
			new_val = text_to_float(new_text);
		}
	}
	if (new_val > -128.0f)
		parent_slider->setValue(new_val);
	set_text_to_stored_choice();
}

float WIDGET::Slider_Label::text_to_float(const String& txt) {
	auto f = txt.getFloatValue();
	auto n = getName();
	if (n == NAME::lbl_clock_tempo)
		f -= 30.0f;
	if (n == NAME::lbl_osc_fine)
		f += 50.0f;
	if (n == NAME::lbl_s_8_bit_int)
		f += 127.0f;
	return f;
}

float WIDGET::Slider_Label::text_to_float_lfo_freq(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#")) {
		for (int i = 90; i < 151; ++i) {
			if (choices_curt[i].removeCharacters(" ") == txt)
				return (float)i;
		}
		return -128.0f;
	}
	if (txt.contains(":")) {
		for (int i = 151; i < choices_curt.size(); ++i) {
			if (choices_curt[i] == txt)
				return (float)i;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float WIDGET::Slider_Label::text_to_float_osc_pitch_and_lpf_freq(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#")) {
		for (int i = 0; i < choices_curt.size(); ++i) {
			if (choices_curt[i].removeCharacters(" ") ==  txt)
				return (float)i;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float WIDGET::Slider_Label::text_to_float_osc_shape(const String& txt) {
	if (txt.containsAnyOf("AFIOPQRSTW/")) {
		if (txt == "OFF")
			return 0.0f;
		if (txt == "SAW")
			return 1.0f;
		if (txt == "TRI")
			return 2.0f;
		if (txt == "S/T")
			return 3.0f;
		if (txt == "SQR")
			return 54.0f;
		if (txt.startsWith("PW"))
			return txt.fromFirstOccurrenceOf("PW", false, false).getFloatValue() + 4.0f;;
		return -128.0f;
	}
	return txt.getFloatValue();
}

float WIDGET::Slider_Label::text_to_float_seq_step(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#+")) {
		for (int i = 0; i < 126; ++i) {
			if (choices_curt[i] == txt)
				return (float)i;
		}
		return -128.0f;
	}
	if (txt == "<")
		return 126.0f;
	if (txt == ".")
		return 127.0f;
	return txt.getFloatValue();
}

