#include "G_WIDG_Sli_Display_Exp_B.h"

Slider_Display_Exposed_B::Slider_Display_Exposed_B(const int param_index, Data_Hub_P* hub,
												   Slider_Wheel_Mod_P* parent_slider) :
	Data_User_P{ hub },
	param_index{ param_index },
	param{ exp_state->getParameter(exp_info.id_for(param_index).toString()) },
	display_type{ exp_info.display_type_for(param_index) },
	parent_slider{ parent_slider }
{
	param->addListener(this);
	setInterceptsMouseClicks(false, true);
	setComponentID(ID::label_slider.toString());
	tip_update.tip_info = exp_info.tip_for(param_index);
	onEditorShow = [this] { on_editor_show(); };
	onTextChange = [this] { on_text_change(); };
}

void Slider_Display_Exposed_B::resized() {
	setFont(FONT::knob(scale_factor));
}

void Slider_Display_Exposed_B::handleAsyncUpdate() {
	set_text_to_stored_choice();
}

void Slider_Display_Exposed_B::parameterValueChanged(int /*param_index*/, float /*new_value*/) {
	triggerAsyncUpdate();
}

Slider_Display_Exposed_B::~Slider_Display_Exposed_B() {
	param->removeListener(this);
}
