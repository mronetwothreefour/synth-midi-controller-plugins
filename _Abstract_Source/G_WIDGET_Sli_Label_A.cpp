#include "G_WIDGET_Sli_Label_A.h"

#include "C_GET_P.h"
#include "D_BUILD_Font_For_P.h"

using namespace BUILD;
using namespace WIDGET;

using Justify = Justification;

Slider_Label_A::Slider_Label_A(const std::string& param_id, Data_Hub* hub,
							   Slider_Wheel_Mod* parent_slider) :
	Data_User{ hub },
	parent_sli{ parent_slider },
	editable{ true },
	editor_allowed_chars{ GET::editor_allowed_chars_for(param_id) },
	editor_char_limit{ GET::editor_char_limit_for(param_id) },
	editor_tip{ GET::editor_tip_for(param_id) },
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
	if (parent_sli)
		parent_sli->addListener(this);
}

void Slider_Label_A::resized() {
	setFont(Font_For::knob(scale_factor()));
}

void Slider_Label_A::on_editor_show() {
	auto edit = getCurrentTextEditor();
	edit->setBounds(getLocalBounds());
	edit->applyFontToAllText(Font_For::knob_txt_editor(scale_factor()));
	auto n = getName();
	edit->setInputRestrictions(editor_char_limit, editor_allowed_chars);
	edit->setTooltip(editor_tip);
	editor_mods_p(edit);
	edit->selectAll();
}

void Slider_Label_A::set_text_to_stored_choice() {
	auto choice_num{ roundToInt(parent_sli->getValue()) };
	setText(choices_curt[choice_num], dontSendNotification);
}

void Slider_Label_A::sliderValueChanged(Slider* /*slider*/) {
	set_text_to_stored_choice();
}

Slider_Label_A::~Slider_Label_A() {
	if (parent_sli)
		parent_sli->removeListener(this);
}
