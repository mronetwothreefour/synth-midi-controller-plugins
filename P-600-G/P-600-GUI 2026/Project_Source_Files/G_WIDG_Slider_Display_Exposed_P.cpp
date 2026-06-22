#include "G_WIDG_Slider_Display_Exposed_P.h"

Slider_Display_Exposed_P::Slider_Display_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Slider_Display_Exposed_B{ param_index, hub }
{
	setComponentID(ID::label_knob.toString());
	setJustificationType(Justification::centred);
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds().translated(0, -1));
	switch (display_type)
	{
	case Slider_Display_Type::int_4_bit:
		edit->setInputRestrictions(2, "0123456789");
		break;
	case Slider_Display_Type::int_5_bit:
		edit->setInputRestrictions(2, "0123456789");
		break;
	case Slider_Display_Type::int_6_bit:
		edit->setInputRestrictions(2, "0123456789");
		break;
	case Slider_Display_Type::int_7_bit:
		edit->setInputRestrictions(3, "0123456789");
		break;
	case Slider_Display_Type::osc_pitch:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_W::knob_text_editor(display_type));
	edit->setText(getText().removeCharacters(" "));
	edit->selectAll();
}

void Slider_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto choice_name{ exp_info.choice_for(param_index, choice_num, true) };
	setText(choice_name, dontSendNotification);
}

void Slider_Display_Exposed_P::on_text_change() {
	if (display_type == Slider_Display_Type::osc_pitch) {
		auto new_text{ getText().toUpperCase() };
		auto new_val{ -1.0f };
		if (new_text.isNotEmpty()) {
			if (new_text.containsAnyOf("abcdefgABCDEFG#")) {
				for (int choice_num = 0; choice_num < EXP::choice_count_osc_pitch; ++choice_num) {
					if (exp_info.choice_for(param_index, choice_num, true).removeCharacters(" ") == new_text) {
						new_val = (float)choice_num;
						break;
					}
				}
			}
			else
				new_val = new_text.getFloatValue();
			if (new_val > -1.0f) {
				param->setValueNotifyingHost(param->convertTo0to1(new_val));
				return;
			}
		}
		set_text_to_stored_choice();
	}
}
