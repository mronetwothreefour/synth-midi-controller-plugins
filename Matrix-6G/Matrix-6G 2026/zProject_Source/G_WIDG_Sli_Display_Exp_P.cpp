#include "G_WIDG_Sli_Display_Exp_P.h"

#include "C_EXP_P.h"
#include "C_FONT_P.h"
#include "C_ID_P.h"
#include "D_TIP_Widget_P.h"

using Display = Slider_Display_Type;

Slider_Display_Exposed_P::Slider_Display_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Slider_Display_Exposed_G{ param_id, hub, parent_slider },
	for_osc_balance{ exp_info.ctrl_type_for(param_id) == Ctrl_Type::slider_osc_balance }
{
	setComponentID(for_osc_balance ? ID::label_linear : ID::label_led);
	setJustificationType(for_osc_balance ? Justification::centred : Justification::right);
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_P::on_editor_show() {
	auto edit = getCurrentTextEditor();
	if (for_osc_balance)
		edit->setComponentID(ID::txt_editor_filled);
	edit->setJustification(for_osc_balance ? Justification::centred : Justification::centredRight);
	edit->setBounds(getLocalBounds());
	edit->applyFontToAllText(FONT::knob_txt_edit(scale_factor));
	switch (display_type)
	{
	case Display::osc_pitch:
		edit->setInputRestrictions(4, ID::allowed_char_osc_pitch);
		break;
	case Display::s_6_bit_int:
		edit->setInputRestrictions(3, ID::allowed_char_int_signed);
		break;
	case Display::s_7_bit_int:
		edit->setInputRestrictions(3, ID::allowed_char_int_signed);
		break;
	case Display::u_int:
		edit->setInputRestrictions(3, ID::allowed_char_int_unsigned);
		break;
	default:
		break;
	}
	edit->setTooltip(Tip_Widget_P::knob_text_editor(display_type, display_type == Display::s_7_bit_int));
	edit->setText(getText().removeCharacters(" +"));
	edit->selectAll();
}

void Slider_Display_Exposed_P::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -64.0f };
	if (new_text.isNotEmpty()) {
		if (display_type == Display::osc_pitch) {
			if (new_text.containsAnyOf("abcdefgABCDEFG#")) {
				auto choice_count{ EXP::choice_count_osc_pitch };
				for (int choice_num = 0; choice_num < choice_count; ++choice_num) {
					if (exp_info.choice_for(param_id, choice_num, true).removeCharacters(" ") == new_text) {
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
			if (display_type == Display::s_6_bit_int)
				new_val += 31.0f;
			if (display_type == Display::s_7_bit_int)
				new_val += 63.0f;
		}
		if (new_val > -64.0f)
			parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}
