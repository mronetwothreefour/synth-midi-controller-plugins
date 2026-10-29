#include "G_LAYER_Buttons_Main_A.h"

#include "C_GET_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Widget_A.h"
#include "C_SL_Tip_Widget_P.h"
#include "D_MIDI_Msg_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace LAYER;

LAYER::Buttons_Main_A::Buttons_Main_A(Data_Hub* hub) :
	Data_User{ hub },
	btn_push{ NAME::btn_main_push },
	btn_pull{ NAME::btn_main_pull },
	btn_undo{ NAME::btn_main_undo },
	btn_redo{ NAME::btn_main_redo },
	init_bounds_btn_push{ GET::init_bounds_for(NAME::btn_main_push) },
	init_bounds_btn_pull{ GET::init_bounds_for(NAME::btn_main_pull) },
	init_bounds_btn_undo{ GET::init_bounds_for(NAME::btn_main_undo) },
	init_bounds_btn_redo{ GET::init_bounds_for(NAME::btn_main_redo) }
{
	setInterceptsMouseClicks(false, true);

	btn_push.addShortcut(KeyPress{ 'h', Mods::altModifier, 0 });
	btn_push.addShortcut(KeyPress{ ']', Mods::ctrlModifier, 0 });
	addAndMakeVisible(btn_push);

	btn_pull.addShortcut(KeyPress{ 'l', Mods::altModifier, 0 });
	btn_pull.addShortcut(KeyPress{ '[', Mods::ctrlModifier, 0 });
	addAndMakeVisible(btn_pull);

	btn_undo.onClick = [this] { u_m->undo(); };
	btn_undo.addShortcut(KeyPress{ 'u', Mods::altModifier, 0 });
	btn_undo.addShortcut(KeyPress{ 'z', Mods::ctrlModifier, 0 });
	addAndMakeVisible(btn_undo);

	btn_redo.onClick = [this] { u_m->redo(); };
	btn_redo.addShortcut(KeyPress{ 'r', Mods::altModifier, 0 });
	btn_redo.addShortcut(KeyPress{ 'z', Mods::ctrlModifier + Mods::shiftModifier, 0 });
	addAndMakeVisible(btn_redo);
}

void LAYER::Buttons_Main_A::resized() {
	btn_push.setBounds(init_bounds_btn_push.transformedBy(AffineTransform::scale(scale_f)));
	btn_pull.setBounds(init_bounds_btn_pull.transformedBy(AffineTransform::scale(scale_f)));
	btn_undo.setBounds(init_bounds_btn_undo.transformedBy(AffineTransform::scale(scale_f)));
	btn_redo.setBounds(init_bounds_btn_redo.transformedBy(AffineTransform::scale(scale_f)));
}

void LAYER::Buttons_Main_A::modifierKeysChanged(const Mods& mods) {
	if (mods == Mods::ctrlAltCommandModifiers) {
		if (btn_push.isMouseOver())
			btn_push.setTooltip(Tip_For::from_SL(SL::btn_main_push_tip));
		if (btn_pull.isMouseOver())
			btn_pull.setTooltip(Tip_For::from_SL(SL::btn_main_pull_tip));
		if (btn_undo.isMouseOver())
			btn_undo.setTooltip(Tip_For::from_SL(SL::btn_main_undo_tip));
		if (btn_redo.isMouseOver())
			btn_redo.setTooltip(Tip_For::from_SL(SL::btn_main_redo_tip));
	}
	else {
		btn_push.setTooltip("");
		btn_pull.setTooltip("");
		btn_undo.setTooltip("");
		btn_redo.setTooltip("");
	}
}
