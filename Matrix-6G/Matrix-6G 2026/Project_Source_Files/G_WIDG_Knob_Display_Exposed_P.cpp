#include "G_WIDG_Knob_Display_Exposed_P.h"

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
}

void Knob_Display_Exposed_P::on_editor_show()
{
	auto editor = getCurrentTextEditor();
	editor->setFont(FONT::knob_txt_edit(scale_factor));
	editor->setJustification(Justification::centredRight);
	switch (display_type)
	{
	case ENUM::Knob_Display_Type::osc_pitch:
		editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
		break;
	case ENUM::Knob_Display_Type::signed_6_bit_int:
		editor->setInputRestrictions(3, "-0123456789");
		break;
	case ENUM::Knob_Display_Type::signed_7_bit:
		editor->setInputRestrictions(3, "-0123456789");
		break;
	case ENUM::Knob_Display_Type::unsigned_int:
		editor->setInputRestrictions(3, "0123456789");
		break;
	default:
		break;
	}
	editor->selectAll();
}

void Knob_Display_Exposed_P::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	auto choice_name{ exp_info.choice_for(choice_num, param_index, true).removeCharacters(" +") };
	setText(choice_name, dontSendNotification);
}

void Knob_Display_Exposed_P::on_text_change_pitch()
{
}

void Knob_Display_Exposed_P::on_text_change_int()
{
}

void Knob_Display_Exposed_P::parameterValueChanged(int param_index, float new_value)
{
}

Knob_Display_Exposed_P::~Knob_Display_Exposed_P() {
	param->removeListener(this);
}
