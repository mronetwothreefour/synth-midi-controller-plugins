#include "G_WIDG_Sli_Display_Exp_G.h"

#include "C_FONT_P.h"
#include "C_ID_P.h"

Slider_Display_Exposed_G::Slider_Display_Exposed_G(const Exp_Param param_id, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Data_User_P{ hub },
	param_id{ param_id },
	display_type{ exp_info.display_type_for(param_id) },
	parent_slider{ parent_slider },
	editable{ true }
{
	setInterceptsMouseClicks(false, true);
	setComponentID(ID::label_slider);
	tip_update.tip_info = exp_info.tip_for(param_id);
	onEditorShow = [this] { on_editor_show(); };
	onTextChange = [this] { on_text_change(); };
	if (parent_slider)
		parent_slider->addListener(this);
}

void Slider_Display_Exposed_G::resized() {
	setFont(FONT::knob(scale_factor));
}

void Slider_Display_Exposed_G::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_slider->getValue()) };
	auto choice_name{ exp_info.choice_for(param_id, choice_num, true) };
	setText(choice_name, dontSendNotification);
}

void Slider_Display_Exposed_G::sliderValueChanged(Slider* /*slider*/) {
	set_text_to_stored_choice();
}

Slider_Display_Exposed_G::~Slider_Display_Exposed_G() {
	if (parent_slider)
		parent_slider->removeListener(this);
}

