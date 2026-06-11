#include "G_WIDG_Knob_Display_Exposed_B.h"

Knob_Display_Exposed_B::Knob_Display_Exposed_B(const int param_index, Data_Hub_P* hub) :
	Data_User_P{ hub },
	param_index{ param_index },
	param{ exp_state->getParameter(exp_info.id_for(param_index).toString()) },
	display_type{ exp_info.knob_display_type_for(param_index) }
{
	param->addListener(this);
	setInterceptsMouseClicks(false, true);
	setComponentID(ID::label_knob.toString());
	onEditorShow = [this] { on_editor_show(); };
	onTextChange = [this] { on_text_change(); };
	set_text_to_stored_choice();
}

void Knob_Display_Exposed_B::handleAsyncUpdate() {
	set_text_to_stored_choice();
}

void Knob_Display_Exposed_B::parameterValueChanged(int /*param_index*/, float /*new_value*/) {
	triggerAsyncUpdate();
}

Knob_Display_Exposed_B::~Knob_Display_Exposed_B() {
	param->removeListener(this);
}
