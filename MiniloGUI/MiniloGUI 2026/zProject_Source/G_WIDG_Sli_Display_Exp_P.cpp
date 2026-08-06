#include "G_WIDG_Sli_Display_Exp_P.h"

#include "C_FONT_P.h"
#include "C_ID_P.h"
#include "D_TIP_Widget_P.h"

Slider_Display_Exposed_P::Slider_Display_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Slider_Display_Exposed_G{ param_id, hub, parent_slider }
{}

void Slider_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds().translated(0, -1));
	edit->applyFontToAllText(FONT::knob_txt_edit(scale_factor));
	switch (display_type)
	{
	case Slider_Display_Type::lfo_rate:
		edit->setInputRestrictions(avp.lfo_sync_bpm_on() ? 2 : 4, ID::allowed_char_int_unsigned);
		break;
	case Slider_Display_Type::lpf_eg_int:
		edit->setInputRestrictions(4, ID::allowed_char_int_signed);
		break;
	case Slider_Display_Type::osc_2_pitch_eg_int:
		edit->setInputRestrictions(5, ID::allowed_char_int_signed);
		break;
	case Slider_Display_Type::osc_pitch_fine:
		edit->setInputRestrictions(5, ID::allowed_char_int_signed);
		break;
	case Slider_Display_Type::u_10_bit_int:
		edit->setInputRestrictions(4, ID::allowed_char_int_unsigned);
		break;
	case Slider_Display_Type::voice_mode_depth:
		switch (avp.voice_mode())
		{
		case Voice_Mode::poly:
			edit->setInputRestrictions(1, ID::allowed_char_voice_mode_poly);
			break;
		case Voice_Mode::duo:
			edit->setInputRestrictions(2, ID::allowed_char_int_unsigned);
			break;
		case Voice_Mode::unison:
			edit->setInputRestrictions(2, ID::allowed_char_int_unsigned);
			break;
		case Voice_Mode::mono:
			edit->setInputRestrictions(4, ID::allowed_char_int_unsigned);
			break;
		case Voice_Mode::chord:
			edit->setInputRestrictions(2, ID::allowed_char_int_unsigned);
			break;
		case Voice_Mode::delay:
			edit->setInputRestrictions(4, ID::allowed_char_int_unsigned);
			break;
		case Voice_Mode::arp:
			edit->setInputRestrictions(2, ID::allowed_char_int_unsigned);
			break;
		case Voice_Mode::sidechain:
			edit->setInputRestrictions(4, ID::allowed_char_int_unsigned);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_Widget_P::knob_text_editor(display_type, avp));
	edit->selectAll();
}

void Slider_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_slider->getValue()) };
	auto ctrl_type = exp_info.ctrl_type_for(param_id);
	String name{};
	if (ctrl_type == Ctrl_Type::knob_lfo_rate || ctrl_type == Ctrl_Type::knob_voice_mode_depth) {
		if (ctrl_type == Ctrl_Type::knob_lfo_rate)
			name = exp_info.choice_for_lfo_rate(avp.lfo_sync_bpm_on(), choice_num, true);
		else
			name = exp_info.choice_for_voice_mode(avp.voice_mode(), choice_num, true);
	}
	else
		name = exp_info.choice_for(param_id, choice_num, true);
	setText(name, dontSendNotification);
}

void Slider_Display_Exposed_P::on_text_change() {
	switch (display_type)
	{
	case ENUM::Slider_Display_Type::lfo_rate:
		on_text_change_lfo_rate();
		break;
	case ENUM::Slider_Display_Type::lpf_eg_int:
		on_text_change_get_best_match();
		break;
	case ENUM::Slider_Display_Type::osc_2_pitch_eg_int:
		on_text_change_get_best_match();
		break;
	case ENUM::Slider_Display_Type::osc_pitch_fine:
		on_text_change_get_best_match();
		break;
	case ENUM::Slider_Display_Type::u_10_bit_int:
		on_text_change_unsigned_10_bit();
		break;
	case ENUM::Slider_Display_Type::voice_mode_depth:
		on_text_change_voice_mode_depth();
		break;
	default:
		setText("error", dontSendNotification);
		break;
	}
}

void Slider_Display_Exposed_P::on_text_change_get_best_match() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto input_val{ new_text.getIntValue() };
		parent_slider->setValue(parent_slider->get_best_display_value_match(input_val));
	}
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_P::on_text_change_lfo_rate() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		if (avp.lfo_sync_bpm_on())
			new_val *= 64.0f;
		parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_P::on_text_change_unsigned_10_bit() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_P::on_text_change_voice_mode_depth() {
	auto new_text{ getText() };
	if (new_text.isNotEmpty()) {
		auto new_val{ new_text.getFloatValue() };
		switch (avp.voice_mode())
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
