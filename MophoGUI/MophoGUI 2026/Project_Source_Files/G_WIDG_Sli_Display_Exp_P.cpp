#include "G_WIDG_Sli_Display_Exp_P.h"

using Display = Slider_Display_Type;

Slider_Display_Exposed_P::Slider_Display_Exposed_P(const int param_index, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Slider_Display_Exposed_B{ param_index, hub, parent_slider }
{
	auto ctrl_type = exp_info.ctrl_type_for(param_index);
	Identifier id = ID::label_slider;
	if (ctrl_type == Ctrl_Type::knob_osc_shape)
		id = ID::label_osc_shape;
	if (ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_track_1)
		id = ID::label_seq_step;
	setComponentID(id.toString());
	setJustificationType(Justification::centred);
}

void Slider_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds().translated(0, -1));
	edit->applyFontToAllText(FONT::knob_txt_edit(scale_factor));
	switch (display_type)
	{
	case Display::bend_range:
		edit->setInputRestrictions(2, "0123456789");
		break;
	case Display::clock_tempo:
		edit->setInputRestrictions(3, "0123456789");
		break;
	case Display::lfo_freq:
		edit->setInputRestrictions(5, "abcdefgABCDEFG0123456789#:.");
		break;
	case Display::lpf_freq:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	case Display::osc_fine:
		edit->setInputRestrictions(3, "-0123456789");
		break;
	case Display::osc_pitch:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	case Display::osc_shape:
		edit->setInputRestrictions(4, "afiopqrstwAFIOPQRSTW0123456789/");
		break;
	case Display::osc_slop:
		edit->setInputRestrictions(1, "012345");
		break;
	case Display::seq_step:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#+<");
		edit->applyFontToAllText(FONT::seq_step(scale_factor));
		break;
	case Display::seq_step_track_1:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#+<.");
		edit->applyFontToAllText(FONT::seq_step(scale_factor));
		break;
	case Display::signed_8_bit:
		edit->setInputRestrictions(4, "-0123456789");
		break;
	case Display::unsigned_7_bit:
		edit->setInputRestrictions(3, "0123456789");
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_W::knob_text_editor(display_type));
	auto txt = getText().removeCharacters(" ");
	if (display_type != Display::seq_step && display_type != Display::seq_step_track_1)
		txt.removeCharacters("+");
	edit->setText(txt);
	edit->selectAll();
}

void Slider_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto choice_name{ exp_info.choice_for(param_index, choice_num, true) };
	if (display_type == Display::bend_range)
		choice_name = "+/-" + choice_name;
	if (display_type == Display::seq_step || display_type == Display::seq_step_track_1) {
		if (!parent_slider->modifying_pitch)
			choice_name = String{ choice_num };
	}
	setText(choice_name, dontSendNotification);
}

void Slider_Display_Exposed_P::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -128.0f };
	if (new_text.isNotEmpty()) {
		if (display_type == Display::osc_pitch || display_type == Display::lpf_freq)
			new_val = text_to_float_osc_pitch_and_lpf_freq(new_text);
		if (display_type == Slider_Display_Type::osc_shape)
			new_val = text_to_float_osc_shape(new_text);
		if (display_type == Display::lfo_freq)
			new_val = text_to_float_lfo_freq(new_text);
		if (display_type == Display::seq_step || display_type == Display::seq_step_track_1)
			new_val = text_to_float_seq_step(new_text);
		if (display_type == Display::bend_range || display_type == Display::clock_tempo ||
			display_type == Display::osc_fine || display_type == Display::osc_slop ||
			display_type == Display::signed_8_bit || display_type == Display::unsigned_7_bit)
			new_val = text_to_float_other(new_text);
	}
	if (new_val > -128.0f)
		param->setValueNotifyingHost(param->convertTo0to1(new_val));
	else
		set_text_to_stored_choice();
}

float Slider_Display_Exposed_P::text_to_float_osc_pitch_and_lpf_freq(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#")) {
		auto choice_count = display_type == Display::osc_pitch ? EXP::choice_count_osc_pitch : EXP::choice_count_lpf_freq;
		for (int choice_num = 0; choice_num < choice_count; ++choice_num) {
			if (exp_info.choice_for(param_index, choice_num, true).removeCharacters(" ") == txt)
				return (float)choice_num;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float Slider_Display_Exposed_P::text_to_float_osc_shape(const String& txt) {
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

float Slider_Display_Exposed_P::text_to_float_lfo_freq(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#")) {
		for (int n = EXP::first_lfo_pitched_freq_choice; n < EXP::first_lfo_synced_freq_choice; ++n) {
			if (exp_info.choice_for(param_index, n, true).removeCharacters(" ") == txt)
				return (float)n;
		}
		return -128.0f;
	}
	if (txt.contains(":")) {
		for (int n = EXP::first_lfo_synced_freq_choice; n < EXP::choice_count_lfo_freq; ++n) {
			if (exp_info.choice_for(param_index, n, true) == txt)
				return (float)n;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float Slider_Display_Exposed_P::text_to_float_seq_step(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#+")) {
		for (int n = 0; n < 126; ++n) {
			if (exp_info.choice_for(param_index, n, true) == txt)
				return (float)n;
		}
		return -128.0f;
	}
	if (txt == "<")
		return 126.0f;
	if (txt == ".")
		return 127.0f;
	return txt.getFloatValue();
}

float Slider_Display_Exposed_P::text_to_float_other(const String& txt) {
	auto f = txt.getFloatValue();
	if (display_type == Display::clock_tempo)
		f -= 30.0f;
	if (display_type == Display::osc_fine)
		f += 50.0f;
	if (display_type == Display::signed_8_bit)
		f += 127.0f;
	return f;
}
