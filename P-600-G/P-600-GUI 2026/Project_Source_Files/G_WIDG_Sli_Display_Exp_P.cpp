#include "G_WIDG_Sli_Display_Exp_P.h"

Slider_Display_Exposed_P::Slider_Display_Exposed_P(const int param_index, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Slider_Display_Exposed_B{ param_index, hub, parent_slider }
{
	setComponentID(ID::label_slider.toString());
	setJustificationType(Justification::centred);
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds().translated(0, -1));
	edit->applyFontToAllText(FONT::knob_txt_edit(scale_factor));
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
		edit->setInputRestrictions(4, "abcdefgABCDEFG01234#");
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_W::knob_text_editor(display_type));
	edit->setText(getText().removeCharacters(" "));
	edit->selectAll();
}

void Slider_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_slider->getValue()) };
	auto choice_name{ exp_info.choice_for(param_index, choice_num, true) };
	setText(choice_name, dontSendNotification);
}

void Slider_Display_Exposed_P::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -1.0f };
	if (new_text.isNotEmpty()) {
		if (display_type == Slider_Display_Type::osc_pitch) {
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
		}
		else
			new_val = new_text.getFloatValue();
		if (new_val > -1.0f)
			parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}
