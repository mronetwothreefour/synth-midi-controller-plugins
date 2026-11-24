#include "G_LAYER_Buttons_Main_P.h"

#include "C_SL_Tip_Widget_P.h"
#include "D_MIDI_Msg_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace LAYER;

Buttons_Main::Buttons_Main(Data_Hub* hub) :
	Buttons_Main_A{ hub }
{
	btn_push.onClick = [this, hub] { outgoing_midi.addEvent(MIDI::Msg::dump_pgm_buffer(hub), 0); };
	btn_pull.onClick = [this] { outgoing_midi.addEvent(MIDI::Msg::dump_request_pgm_buffer(), 0); };
}

void Buttons_Main::resized() {
	Buttons_Main_A::resized();
}

void Buttons_Main::modifierKeysChanged(const Mods& mods) {
	Buttons_Main_A::modifierKeysChanged(mods);
}
