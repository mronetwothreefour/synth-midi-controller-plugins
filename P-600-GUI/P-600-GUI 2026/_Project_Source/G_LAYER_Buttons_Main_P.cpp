#include "G_LAYER_Buttons_Main_P.h"

#include "D_MIDI_Msg_P.h"

using namespace LAYER;

Buttons_Main::Buttons_Main(Data_Hub* hub) :
	Buttons_Main_A{ hub }
{
	btn_pull.onClick = [this] {
		auto pgm_num = (uint8)app_p.current_pgm_num();
		outgoing_midi.addEvent(MIDI::Msg::dump_request_pgm(pgm_num), 0);
		Timer::callAfterDelay(300, [this, pgm_num] {
			// TODO: get basic channel from global parameters
			outgoing_midi.addEvent(MidiMessage::programChange(1, pgm_num), 0);
		});
	};

	btn_push.onClick = [this] {
		//TODO: add program dump message to outgoing_midi
	};
}

void Buttons_Main::resized() {
	Buttons_Main_A::resized();
}

void Buttons_Main::modifierKeysChanged(const Mods& mods) {
	Buttons_Main_A::modifierKeysChanged(mods);
}
