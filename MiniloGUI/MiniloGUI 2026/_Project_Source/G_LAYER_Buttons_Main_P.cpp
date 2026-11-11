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
		String n{ "btn_main_vmode_" + (String)i };
		vmode_buttons.add(new TextButton{ n });
		if (vmode_buttons[i]) {
			auto btn = vmode_buttons[i];
			btn->setClickingTogglesState(true);
			btn->setRadioGroupId(1);
		}
	}
}

void Buttons_Main::resized() {
	Buttons_Main_A::resized();
}

void Buttons_Main::modifierKeysChanged(const Mods& mods) {
	Buttons_Main_A::modifierKeysChanged(mods);
}
