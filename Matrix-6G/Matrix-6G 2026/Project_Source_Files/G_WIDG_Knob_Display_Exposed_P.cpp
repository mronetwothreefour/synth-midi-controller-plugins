#include "G_WIDG_Knob_Display_Exposed_P.h"

#include "D_TIP_Widget_P.h"

using Tip_W = Tip_Widget_P;

Knob_Display_Exposed_P::Knob_Display_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Data_User_P{ hub },
	param_index{ param_index },
	param{ exp_state->getParameter(exp_info.id_for(param_index).toString()) },
	display_type{ exp_info.knob_display_type_for(param_index) }
{
	param->addListener(this);
	setInterceptsMouseClicks(false, true);
	setComponentID(ID::label_led.toString());
	onEditorShow = [this] { on_editor_show(); };
	onTextChange = [this] { on_text_change(); };
}

void Knob_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setFont(FONT::knob_txt_edit(scale_factor));
	edit->setJustification(Justification::centredRight);
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
	edit->selectAll();
}

void Knob_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto choice_name{ exp_info.choice_for(choice_num, param_index, true).removeCharacters(" +") };
	setText(choice_name, dontSendNotification);
}

void Knob_Display_Exposed_P::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -1.0f };
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
		if (new_val > -1.0f) {
			param->setValueNotifyingHost(param->convertTo0to1(new_val));
			return;
		}
	}
	set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::handleAsyncUpdate() {
	set_text_to_stored_choice();
}

void Knob_Display_Exposed_P::parameterValueChanged(int /*param_index*/, float /*new_value*/) {
	triggerAsyncUpdate();
}

Knob_Display_Exposed_P::~Knob_Display_Exposed_P() {
	param->removeListener(this);
}
