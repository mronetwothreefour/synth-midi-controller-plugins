#include "G_WIDGET_Sli_Label_P.h"

#include "C_GET_P.h"
#include "C_NAME_P.h"
#include "D_BUILD_Font_For_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace NAME;
using namespace WIDGET;

using Justify = Justification;

Slider_Label::Slider_Label(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider },
	for_osc_balance{ GET::ctrl_name_for(param_id) == slider_osc_balance }
{
	if (!for_osc_balance)
		setJustificationType(Justify::right);
	set_text_to_stored_choice();
}

void Slider_Label::on_editor_show() {
	auto edit = getCurrentTextEditor();
	if (for_osc_balance)
		edit->setName(txt_editor_filled);
	edit->setJustification(for_osc_balance ? Justify::centred : Justify::centredRight);
	edit->setBounds(getLocalBounds());
	edit->applyFontToAllText(Font_For::knob_txt_editor(scale_factor));
	auto n = getName();
	if (n == lbl_osc_pitch)
		edit->setInputRestrictions(4, allowed_char_pitch);
	if (n == lbl_s_6_bit_int)
		edit->setInputRestrictions(3, allowed_char_s_int);
	if (n == lbl_s_7_bit_int)
		edit->setInputRestrictions(3, allowed_char_s_int);
	if (n == lbl_u_int)
		edit->setInputRestrictions(3, allowed_char_u_int);
	edit->setTooltip(Tip_For::knob_txt_editor(n, n == lbl_s_7_bit_int));
	edit->setText(getText().removeCharacters(" +"));
	edit->selectAll();
}

void Slider_Label::on_text_change() {
	auto n = getName();
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -64.0f };
	if (new_text.isNotEmpty()) {
		if (n == lbl_osc_pitch) {
			if (new_text.containsAnyOf("abcdefgABCDEFG#")) {
				for (int i = 0; i < choices_curt.size(); ++i) {
					if (choices_curt[i].removeCharacters(" ") == new_text) {
						new_val = (float)i;
						break;
					}
				}
			}
			else
				new_val = new_text.getFloatValue();
		}
		else {
			new_val = new_text.getFloatValue();
			if (n == lbl_s_6_bit_int)
				new_val += 31.0f;
			if (n == lbl_s_7_bit_int)
				new_val += 63.0f;
		}
		if (new_val > -64.0f)
			parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}
