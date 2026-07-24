#include "G_WIDG_Sli_Display_Exp_P.h"

#include "C_EXP_P.h"
#include "C_FONT_P.h"
#include "C_ID_P.h"
#include "D_TIP_Widget_P.h"

using Display = Slider_Display_Type;

Slider_Display_Exposed_P::Slider_Display_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Slider_Display_Exposed_G{ param_id, hub, parent_slider }
{
	Identifier id = ID::label_slider;
	if (display_type == Display::osc_shape)
		id = ID::label_osc_shape;
	if (display_type == Display::seq_step || display_type == Display::seq_step_trk_1)
		id = ID::label_seq_step;
	if (display_type == Display::voice_name_char) {
		id = ID::label_voice_name_char;
		editable = false;
	}
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
		edit->setInputRestrictions(2, ID::allowed_char_int_unsigned);
		break;
	case Display::clock_tempo:
		edit->setInputRestrictions(3, ID::allowed_char_int_unsigned);
		break;
	case Display::lfo_freq:
		edit->setInputRestrictions(5, ID::allowed_char_lfo_freq);
		break;
	case Display::lpf_freq:
		edit->setInputRestrictions(4, ID::allowed_char_osc_pitch);
		break;
	case Display::osc_fine:
		edit->setInputRestrictions(3, ID::allowed_char_int_signed);
		break;
	case Display::osc_pitch:
		edit->setInputRestrictions(4, ID::allowed_char_osc_pitch);
		break;
	case Display::osc_shape:
		edit->setInputRestrictions(4, ID::allowed_char_osc_shape);
		break;
	case Display::osc_slop:
		edit->setInputRestrictions(1, ID::allowed_char_osc_slop);
		break;
	case Display::seq_step:
		edit->setInputRestrictions(4, ID::allowed_char_seq_step);
		edit->applyFontToAllText(FONT::seq_step(scale_factor));
		break;
	case Display::seq_step_trk_1:
		edit->setInputRestrictions(4, ID::allowed_char_seq_step_trk_1);
		edit->applyFontToAllText(FONT::seq_step(scale_factor));
		break;
	case Display::s_8_bit_int:
		edit->setInputRestrictions(4, ID::allowed_char_int_signed);
		break;
	case Display::u_7_bit_int:
		edit->setInputRestrictions(3, ID::allowed_char_int_unsigned);
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_Widget_P::knob_text_editor(display_type));
	auto txt = getText().removeCharacters(" ");
	if (display_type != Display::seq_step && display_type != Display::seq_step_trk_1)
		txt = txt.removeCharacters("+");
	if (display_type == Display::bend_range)
		txt = txt.removeCharacters("/-");
	edit->setText(txt);
	edit->selectAll();
}

void Slider_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_slider->getValue()) };
	auto choice_name{ exp_info.choice_for(param_id, choice_num) };
	tip_update.tip_value = choice_name;
	auto choice_name_curt{ exp_info.choice_for(param_id, choice_num, true) };
	if (display_type == Display::lfo_freq) {
		parent_slider->modifying_pitch = choice_num >= EXP::first_lfo_pitched_freq_choice &&
										 choice_num < EXP::first_lfo_synced_freq_choice;
	}
	if (display_type == Display::seq_step || display_type == Display::seq_step_trk_1) {
		if (!parent_slider->modifying_pitch && choice_num < 126)
			choice_name_curt = String{ choice_num };
	}
	setText(choice_name_curt, dontSendNotification);
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
		if (display_type == Display::seq_step || display_type == Display::seq_step_trk_1)
			new_val = text_to_float_seq_step(new_text);
		if (display_type == Display::bend_range || display_type == Display::clock_tempo ||
			display_type == Display::osc_fine || display_type == Display::osc_slop ||
			display_type == Display::s_8_bit_int || display_type == Display::u_7_bit_int)
			new_val = text_to_float_other(new_text);
	}
	if (new_val > -128.0f)
		parent_slider->setValue(new_val);
	set_text_to_stored_choice();
}

float Slider_Display_Exposed_P::text_to_float_osc_pitch_and_lpf_freq(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#")) {
		auto choice_count = display_type == Display::osc_pitch ? EXP::choice_count_osc_pitch : EXP::choice_count_lpf_freq;
		for (int choice_num = 0; choice_num < choice_count; ++choice_num) {
			if (exp_info.choice_for(param_id, choice_num, true).removeCharacters(" ") == txt)
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
			if (exp_info.choice_for(param_id, n, true).removeCharacters(" ") == txt)
				return (float)n;
		}
		return -128.0f;
	}
	if (txt.contains(":")) {
		for (int n = EXP::first_lfo_synced_freq_choice; n < EXP::choice_count_lfo_freq; ++n) {
			if (exp_info.choice_for(param_id, n, true) == txt)
				return (float)n;
		}
		return -128.0f;
	}
	return txt.getFloatValue();
}

float Slider_Display_Exposed_P::text_to_float_seq_step(const String& txt) {
	if (txt.containsAnyOf("abcdefgABCDEFG#+")) {
		for (int n = 0; n < 126; ++n) {
			if (exp_info.choice_for(param_id, n, true) == txt)
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
	if (display_type == Display::s_8_bit_int)
		f += 127.0f;
	return f;
}
