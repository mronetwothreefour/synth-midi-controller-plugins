#include "G_LAYER_Pgm_Num_And_Name_P.h"

#include "C_GET_P.h"
#include "C_ID_A.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Widget_P.h"
#include "D_BUILD_Font_For_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace LAYER;
using namespace WIDGET;

using Justify = Justification;

Pgm_Num_And_Name::Pgm_Num_And_Name(Data_Hub* hub) :
	Data_User{ hub },
	val_pgm_num{ app_p.get_param_as_value(ID::app_curr_pgm_num) },
	val_pgm_name{ app_p.get_param_as_value(ID::app_curr_pgm_name) },
	sli_pgm_num{ ID::app_curr_pgm_num, val_pgm_num, hub },
	name_edited_by_label{ false },
	init_bounds_pgm_num{ GET::init_bounds_for(ID::app_curr_pgm_num) },
	init_bounds_pgm_name{ GET::init_bounds_for(ID::app_curr_pgm_name) }
{
	setInterceptsMouseClicks(false, true);
	addAndMakeVisible(sli_pgm_num);
	val_pgm_name.addListener(this);
	lbl_pgm_name.setName(NAME::lbl_led_pgm_name);
	lbl_pgm_name.setJustificationType(Justify::centredLeft);
	lbl_pgm_name.setEditable(true);
	lbl_pgm_name.onEditorShow = [this] {
		auto edit = lbl_pgm_name.getCurrentTextEditor();
		edit->setBounds(lbl_pgm_name.getLocalBounds());
		edit->applyFontToAllText(Font_For::knob_txt_edit(scale_f));
		edit->setInputRestrictions(8, MISC::allowed_chars_pgm_name);
		edit->setTooltip(Tip_For::txt_editor_pgm_name(8));
		edit->setJustification(Justify::centredLeft);
		edit->selectAll();
	};
	lbl_pgm_name.onTextChange = [this] {
		auto new_name = lbl_pgm_name.getText().toUpperCase();
		if (new_name.isNotEmpty()) {
			name_edited_by_label = true;
			lbl_pgm_name.setText(new_name, dontSendNotification);
			app_p.set_current_pgm_name(new_name);
		}
	};
	addAndMakeVisible(lbl_pgm_name);
	valueChanged(val_pgm_name);
}

void Pgm_Num_And_Name::resized() {
	sli_pgm_num.setBounds(init_bounds_pgm_num.transformedBy(AffineTransform::scale(scale_f)));
	lbl_pgm_name.setBounds(init_bounds_pgm_name.transformedBy(AffineTransform::scale(scale_f)));
}

void Pgm_Num_And_Name::valueChanged(Value& /*value*/) {
	if (!name_edited_by_label)
		lbl_pgm_name.setText(app_p.current_pgm_name(), dontSendNotification);
	else
		name_edited_by_label = false;
}

void LAYER::Pgm_Num_And_Name::modifierKeysChanged(const Mods& mods) {
	if (mods == Mods::ctrlAltCommandModifiers && lbl_pgm_name.isMouseOver())
		lbl_pgm_name.setTooltip(Tip_For::from_SL(SL::curr_pgm_name));
	else
		lbl_pgm_name.setTooltip("");
}

Pgm_Num_And_Name::~Pgm_Num_And_Name() {
	val_pgm_name.removeListener(this);
}
