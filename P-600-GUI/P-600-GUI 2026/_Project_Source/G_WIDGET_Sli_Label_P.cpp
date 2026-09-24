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

Slider_Label::Slider_Label(const std::string& param_id, Data_Hub* hub,
						   Slider_Wheel_Mod* parent_slider) :
	Slider_Label_A{ param_id, hub, parent_slider }
{
	set_text_to_stored_choice();
}

void Slider_Label::editor_mods_p(TextEditor* edit) {
	edit->setJustification(Justification::centred);
	edit->setText(getText().removeCharacters(" "));
}

void Slider_Label::on_text_change() {
	auto new_text{ getText().toUpperCase() };
	auto new_val{ -1.0f };
	if (new_text.isNotEmpty()) {
		if (parent_sli->for_pitch && new_text.containsAnyOf(pitch_name_chars)) {
			for (int i = 0; i < choices_curt.size(); ++i) {
				if (choices_curt[i].removeCharacters(" ") == new_text) {
					new_val = (float)i;
					break;
				}
			}
		}
		else
			new_val = new_text.getFloatValue();
		if (new_val > -1.0f)
			parent_sli->setValue(new_val);
	}
	set_text_to_stored_choice();
}
