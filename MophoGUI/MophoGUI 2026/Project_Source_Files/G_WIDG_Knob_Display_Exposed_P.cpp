#include "G_WIDG_Knob_Display_Exposed_P.h"

Knob_Display_Exposed_P::Knob_Display_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Knob_Display_Exposed_B{ param_index, hub }
{
	setComponentID(ID::label_knob.toString());
	setJustificationType(Justification::centred);
	set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds().translated(0, -1));
	switch (display_type)
	{
	case ENUM::Knob_Display_Type::bend_range:
		edit->setInputRestrictions(2, "0123456789");
		break;
	case ENUM::Knob_Display_Type::clock_tempo:
		edit->setInputRestrictions(3, "0123456789");
		break;
	case ENUM::Knob_Display_Type::lfo_freq:
		edit->setInputRestrictions(5, "abcdefgABCDEFG0123456789#:.");
		break;
	case ENUM::Knob_Display_Type::lpf_freq:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	case ENUM::Knob_Display_Type::osc_fine:
		edit->setInputRestrictions(3, "-0123456789");
		break;
	case ENUM::Knob_Display_Type::osc_pitch:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	case ENUM::Knob_Display_Type::osc_shape:
		edit->setInputRestrictions(4, "afiopqrstwAFIOPQRSTW0123456789/");
		break;
	case ENUM::Knob_Display_Type::osc_slop:
		edit->setInputRestrictions(1, "012345");
		break;
	case ENUM::Knob_Display_Type::signed_8_bit:
		edit->setInputRestrictions(4, "-0123456789");
		break;
	case ENUM::Knob_Display_Type::unsigned_7_bit:
		edit->setInputRestrictions(3, "0123456789");
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_W::knob_text_editor(display_type));
	edit->setText(getText().removeCharacters(" +/"));
	edit->selectAll();
}

void Knob_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto choice_name{ exp_info.choice_for(param_index, choice_num, true).removeCharacters(" ") };
	if (display_type == Knob_Display_Type::bend_range)
		choice_name = "+/-" + choice_name;
	setText(choice_name, dontSendNotification);
}

void Knob_Display_Exposed_P::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -1.0f };
	if (new_text.isNotEmpty()) {
		if (display_type == Knob_Display_Type::lfo_freq ||
			display_type == Knob_Display_Type::lpf_freq || 
			display_type == Knob_Display_Type::osc_pitch)
		{
			if (new_text.containsAnyOf("abcdefgABCDEFG#")) {
				auto choice_count{ EXP::choice_count_osc_pitch };
				if (display_type == Knob_Display_Type::lfo_freq)
					choice_count = EXP::choice_count_lfo_freq;
				if (display_type == Knob_Display_Type::lpf_freq)
					choice_count = EXP::choice_count_lpf_freq;
				for (int choice_num = 0; choice_num < choice_count; ++choice_num) {
					if (exp_info.choice_for(param_index, choice_num, true).removeCharacters(" ") == new_text) {
						new_val = (float)choice_num;
						break;
					}
				}
			}
			else
				new_val = new_text.getFloatValue();
		}
		else {
			if (display_type == Knob_Display_Type::osc_shape) {
				if (new_text.containsAnyOf("AFIOPQRSTW/")) {
					if (new_text == "OFF")
						new_val = 0.0f;
					if (new_text == "SAW")
						new_val = 1.0f;
					if (new_text == "TRI")
						new_val = 2.0f;
					if (new_text == "S/T")
						new_val = 3.0f;
					if (new_text == "SQR")
						new_val = 54.0f;
					if (new_text.startsWith("PW"))
						new_val = new_text.fromFirstOccurrenceOf("PW", false, false).getFloatValue() + 4.0f;;
				}
				else
					new_val = new_text.getFloatValue();
			}
			else {
				new_val = new_text.getFloatValue();
				if (display_type == Knob_Display_Type::clock_tempo)
					new_val += 30.0f;
				if (display_type == Knob_Display_Type::osc_fine)
					new_val += 50.0f;
				if (display_type == Knob_Display_Type::signed_8_bit)
					new_val += 127.0f;
			}
		}
		if (new_val > -1.0f) {
			param->setValueNotifyingHost(param->convertTo0to1(new_val));
			return;
		}
	}
	set_text_to_stored_choice();
}
