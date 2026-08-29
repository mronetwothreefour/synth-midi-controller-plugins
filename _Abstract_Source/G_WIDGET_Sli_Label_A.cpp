#include "G_WIDGET_Sli_Label_A.h"

#include "C_GET_P.h"
#include "D_BUILD_Font_For_P.h"

using namespace BUILD;
using namespace WIDGET;

using Justify = Justification;

Slider_Label_A::Slider_Label_A(const String& param_id, Data_Hub* hub,
									   Slider_Wheel_Mod* parent_slider) :
	Data_User{ hub },
	parent_slider{ parent_slider },
	editable{ true },
	choices{ parent_slider->choices },
	choices_curt{ parent_slider->choices_curt }
{
	setInterceptsMouseClicks(false, true);
	setComponentID(param_id);
	setName(GET::label_name_for(param_id));
	setJustificationType(Justify::centred);
	tip_update.tip_info = GET::tip_for(param_id);
	onEditorShow = [this] { on_editor_show(); };
	onTextChange = [this] { on_text_change(); };
	if (parent_slider)
		parent_slider->addListener(this);
}

void Slider_Label_A::resized() {
	setFont(Font_For::knob(scale_factor));
}

void Slider_Label_A::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_slider->getValue()) };
	setText(choices_curt[choice_num], dontSendNotification);
}

void Slider_Label_A::sliderValueChanged(Slider* /*slider*/) {
	set_text_to_stored_choice();
}

Slider_Label_A::~Slider_Label_A() {
	if (parent_slider)
		parent_slider->removeListener(this);
}
