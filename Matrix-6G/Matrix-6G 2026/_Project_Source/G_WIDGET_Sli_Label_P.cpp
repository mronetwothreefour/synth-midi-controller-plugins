#include "G_WIDGET_Sli_Label_P.h"

#include "C_GET_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"

using namespace MISC;
using namespace NAME;
using namespace WIDGET;

using Justify = Justification;

Slider_Label::Slider_Label(const std::string& param_id, Data_Hub* hub,
						   Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider },
	for_osc_balance{ GET::ctrl_name_for(param_id) == ctr_sli_osc_bal }
{
	setJustificationType(Justify::right);
	if (for_osc_balance) {
		setAlpha(0.0f);
		onEditorHide = [this] { setAlpha(0.0f); };
	}
	set_text_to_stored_choice();
}

void WIDGET::Slider_Label::editor_mods_p(TextEditor* edit) {
	if (for_osc_balance) {
		setAlpha(1.0f);
		edit->setName(txt_edit_filled);
	}
	edit->setJustification(for_osc_balance ? Justify::centred : Justify::centredRight);
	edit->setText(getText().removeCharacters(" +"));
}

void Slider_Label::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -64.0f };
	if (new_text.isNotEmpty()) {
		if (parent_sli->for_pitch && new_text.containsAnyOf(pitch_name_chars)) {
				for (int i = 0; i < choices_curt.size(); ++i) {
					if (choices_curt[i].removeCharacters(" ") == new_text) {
						new_val = (float)i;
						break;
					}
				}
		}
		else {
			new_val = new_text.getFloatValue();
			if (choices[0] == "-31")
				new_val += 31.0f;
			if (choices[0] == "-63")
				new_val += 63.0f;
		}
		if (new_val > -64.0f)
			parent_sli->setValue(new_val);
	}
	set_text_to_stored_choice();
}
