#include "G_WIDGET_Sli_Label_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"

using namespace MISC;
using namespace NAME;
using namespace WIDGET;

Slider_Label::Slider_Label(const std::string& param_id, Data_Hub* hub,
						   Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider }
{
	if (getName() == lbl_name_char)
		editable = false;
}

void Slider_Label::editor_mods_p(TextEditor* edit) {
	edit->setJustification(Justification::centred);
	auto id = getComponentID();
	auto txt = getText().removeCharacters(" ");
	if (!id.contains("_step_"))
		txt = txt.removeCharacters("+");
	if (id == ID::exp_bend_range)
		txt = txt.removeCharacters("/-");
	edit->setText(txt);
}

void Slider_Label::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_sli->getValue()) };
	auto id = getComponentID();
	if (id.contains("_lfo_") && id.endsWith("_freq"))
		parent_sli->for_pitch = choice_num >= lfo_1st_pitch_freq && choice_num < lfo_1st_sync_freq;
	auto choice_name{ choices_curt[choice_num] };
	if (id.contains("_step_")) {
		if (!parent_sli->for_pitch && choice_num < 126)
			choice_name = String{ choice_num };
	}
	setText(choice_name, dontSendNotification);
}

void Slider_Label::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -128.0f };
	if (new_text.isNotEmpty()) {
		auto id = getComponentID();
		auto basic_int = true;
		if (id == ID::exp_osc_1_pitch || id == ID::exp_osc_2_pitch || id == ID::exp_lpf_freq) {
			new_val = text_to_float_osc_pitch_and_lpf_freq(new_text);
			basic_int = false;
		}
		if (id == ID::exp_osc_1_shape || id == ID::exp_osc_2_shape) {
			new_val = text_to_float_osc_shape(new_text);
			basic_int = false;
		}
		if (id.contains("_lfo_") && id.endsWith("_freq")) {
			new_val = text_to_float_lfo_freq(new_text);
			basic_int = false;
		}
		if (id.contains("_step_")) {
			new_val = text_to_float_seq_step(new_text);
			basic_int = false;
		}
		if (basic_int) {
			new_val = text_to_float(new_text);
		}
	}
	if (new_val > -128.0f)
		parent_sli->setValue(new_val);
	set_text_to_stored_choice();
}

float Slider_Label::text_to_float(const String& txt) {
	auto f = txt.getFloatValue();
	if (choices[0] == "30")
		f -= 30.0f;
	if (choices[0] == "-50")
		f += 50.0f;
	if (choices[0] == "-127")
		f += 127.0f;
	return f;
}

float Slider_Label::text_to_float_lfo_freq(const String& txt) {
	if (txt.containsAnyOf(pitch_name_chars)) {
		for (int i = lfo_1st_pitch_freq; i < lfo_1st_sync_freq; ++i) {
			if (choices_curt[i].removeCharacters(" ") == txt)
				return (float)i;
		}
		return -128.0f;
	}
	if (txt.contains(":")) {
		for (int i = lfo_1st_sync_freq; i < choices_curt.size(); ++i) {
			if (choices_curt[i] == txt)
				return (float)i;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float Slider_Label::text_to_float_osc_pitch_and_lpf_freq(const String& txt) {
	if (txt.containsAnyOf(pitch_name_chars)) {
		for (int i = 0; i < choices_curt.size(); ++i) {
			if (choices_curt[i].removeCharacters(" ") ==  txt)
				return (float)i;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float Slider_Label::text_to_float_osc_shape(const String& txt) {
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

float Slider_Label::text_to_float_seq_step(const String& txt) {
	if (txt.containsAnyOf(pitch_name_chars)) {
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

