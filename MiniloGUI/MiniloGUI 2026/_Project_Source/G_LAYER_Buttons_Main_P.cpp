#include "G_LAYER_Buttons_Main_P.h"

#include "C_GET_P.h"
#include "C_SL_Tip_Widget_P.h"
#include "D_MIDI_Msg_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace LAYER;

Buttons_Main::Buttons_Main(Data_Hub* hub) :
	Buttons_Main_A{ hub }
{
	btn_pull.onClick = [this] { outgoing_midi.addEvent(MIDI::Msg::request_pgm_buffer(), 0); };

	btn_push.onClick = [this] {
		//TODO: add program buffer dump message to outgoing_midi
	};

	for (int i = 0; i < 8; ++i) {
		auto id = String{ "avp_voice_mode_btn_" + (String)i }.toStdString();
		vmode_buttons.add(new TextButton{ id });
		if (vmode_buttons[i]) {
			auto btn = vmode_buttons[i];
			btn->setComponentID(id);
			btn->setName(GET::ctrl_name_for(id));
			btn->setClickingTogglesState(true);
			btn->setToggleState(avp.voice_mode() == i, dontSendNotification);
			btn->setRadioGroupId(1);
			btn->onClick = [this, i] { avp.set_voice_mode(i); };
			addAndMakeVisible(btn);
			vmode_init_bounds.add(GET::init_bounds_for(id));
		}
	}
}

void Buttons_Main::resized() {
	for (int i = 0; i < 8; ++i) {
		auto* btn = vmode_buttons[i];
		if (btn)
			btn->setBounds(vmode_init_bounds[i].transformedBy(AffineTransform::scale(scale_f)));
	}
	Buttons_Main_A::resized();
}

void Buttons_Main::modifierKeysChanged(const Mods& mods) {
	for (int i = 0; i < 8; ++i) {
		auto* btn = vmode_buttons[i];
		if (btn)
			btn->setTooltip(btn->isMouseOver() ? GET::tip_for(btn->getComponentID().toStdString()) : "");
	}
	Buttons_Main_A::modifierKeysChanged(mods);
}

LAYER::Buttons_Main::~Buttons_Main() {
	vmode_buttons.clear();
	vmode_init_bounds.clear();
}
