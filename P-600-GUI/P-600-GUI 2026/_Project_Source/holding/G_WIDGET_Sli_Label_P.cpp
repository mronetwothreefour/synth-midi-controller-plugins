#include "G_WIDGET_Sli_Label_P.h"

#include "C_GET_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"
#include "D_BUILD_Font_For_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace MISC;
using namespace NAME;
using namespace WIDGET;

Slider_Label::Slider_Label(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider }
{
	set_text_to_stored_choice();
}

void Slider_Label::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setJustification(Justification::centred);
	edit->setBounds(getLocalBounds());
	edit->applyFontToAllText(Font_For::knob_txt_editor(scale_factor));
	auto n = parent_slider->getName();
	if (n == NAME::knob_u_int_4_bit)
		edit->setInputRestrictions(2, allowed_chars_u_int);
	if (n == NAME::knob_u_int_5_bit)
		edit->setInputRestrictions(2, allowed_chars_u_int);
	if (n == NAME::knob_u_int_6_bit)
		edit->setInputRestrictions(2, allowed_chars_u_int);
	if (n == NAME::knob_u_int_7_bit)
		edit->setInputRestrictions(3, allowed_chars_u_int);
	if (n == NAME::lbl_osc_pitch)
		edit->setInputRestrictions(3, allowed_chars_pitch);
	edit->setTooltip(Tip_For::knob_txt_editor(n));
	edit->setText(getText().removeCharacters(" +"));
	edit->selectAll();
}

void Slider_Label::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -1.0f };
	if (new_text.isNotEmpty()) {
		if (parent_slider->getName() == knob_pitch) {
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
		else
			new_val = new_text.getFloatValue();
		if (new_val > -1.0f)
			parent_slider->setValue(new_val);
	}
	set_text_to_stored_choice();
}
