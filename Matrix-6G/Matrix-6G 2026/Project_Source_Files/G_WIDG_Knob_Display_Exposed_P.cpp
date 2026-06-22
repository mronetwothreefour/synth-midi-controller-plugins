#include "G_WIDG_Knob_Display_Exposed_P.h"

Knob_Display_Exposed_P::Knob_Display_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Knob_Display_Exposed_B{ param_index, hub},
	for_osc_balance{ exp_info.ctrl_type_for(param_index) == Ctrl_Type::slider_osc_balance }
{
	setComponentID(for_osc_balance ? ID::label_linear.toString() : ID::label_led.toString());
	setJustificationType(for_osc_balance ? Justification::centred : Justification::right);
	set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	if (for_osc_balance)
		edit->setComponentID(ID::txt_editor_filled.toString());
	edit->setJustification(for_osc_balance ? Justification::centred : Justification::centredRight);
	edit->setBounds(getLocalBounds().translated(0, -1));
	switch (display_type)
	{
	case Knob_Display_Type::osc_pitch:
		edit->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	case Knob_Display_Type::signed_6_bit:
		edit->setInputRestrictions(3, "-0123456789");
		break;
	case Knob_Display_Type::signed_7_bit:
		edit->setInputRestrictions(3, "-0123456789");
		break;
	case Knob_Display_Type::unsigned_int:
		edit->setInputRestrictions(3, "0123456789");
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_W::knob_text_editor(display_type, display_type == Knob_Display_Type::signed_7_bit));
	edit->setText(getText().removeCharacters(" +"));
	edit->selectAll();
}

void Knob_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto choice_name{ exp_info.choice_for(param_index, choice_num, true) };
	setText(choice_name, dontSendNotification);
}

void Knob_Display_Exposed_P::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -64.0f };
	if (new_text.isNotEmpty()) {
		if (display_type == Knob_Display_Type::osc_pitch) {
			if (new_text.containsAnyOf("abcdefgABCDEFG#")) {
				auto choice_count{ EXP::choice_count_osc_pitch };
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
			new_val = new_text.getFloatValue();
			if (display_type == Knob_Display_Type::signed_6_bit)
				new_val += 31.0f;
			if (display_type == Knob_Display_Type::signed_7_bit)
				new_val += 63.0f;
		}
		param->setValueNotifyingHost(param->convertTo0to1(new_val));
		return;
	}
	set_text_to_stored_choice();
}
