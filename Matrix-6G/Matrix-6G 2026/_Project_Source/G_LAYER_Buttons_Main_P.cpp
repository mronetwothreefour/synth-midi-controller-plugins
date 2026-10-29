#include "G_LAYER_Buttons_Main_P.h"

#include "C_GET_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Widget_P.h"
#include "D_MIDI_Msg_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace LAYER;

Buttons_Main::Buttons_Main(Data_Hub* hub) :
	Buttons_Main_A{ hub },
	btn_quick{ NAME::btn_main_quick },
	init_bounds_btn_quick{ GET::init_bounds_for(NAME::btn_main_quick) }
{
	btn_quick.onClick = [this] {
		outgoing_midi.addEvent(MIDI::Msg::quick_edit_enable(), 0);
	};
	btn_quick.addShortcut(KeyPress{ 'q', ModifierKeys::altModifier, 0 });
	btn_quick.addShortcut(KeyPress{ 'q', ModifierKeys::ctrlModifier, 0 });
	addAndMakeVisible(btn_quick);

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

	flash_btn_quick();
}

void Buttons_Main::resized() {
	btn_quick.setBounds(init_bounds_btn_quick.transformedBy(AffineTransform::scale(scale_f)));
	Buttons_Main_A::resized();
}

void Buttons_Main::flash_btn_quick() {
	Timer::callAfterDelay(500, [this] { btn_quick.setName(NAME::btn_main_quick_flash); repaint(); });
	Timer::callAfterDelay(600, [this] { btn_quick.setName(NAME::btn_main_quick); repaint(); });
	Timer::callAfterDelay(700, [this] { btn_quick.setName(NAME::btn_main_quick_flash); repaint(); });
	Timer::callAfterDelay(800, [this] { btn_quick.setName(NAME::btn_main_quick); repaint(); });
	Timer::callAfterDelay(900, [this] { btn_quick.setName(NAME::btn_main_quick_flash); repaint(); });
	Timer::callAfterDelay(1000, [this] { btn_quick.setName(NAME::btn_main_quick); repaint(); });
}

void Buttons_Main::modifierKeysChanged(const Mods& mods) {
	if (mods == Mods::ctrlAltCommandModifiers) {
		if (btn_quick.isMouseOver())
			btn_quick.setTooltip(Tip_For::from_SL(SL::btn_main_quick_tip));
	}
	else {
		btn_quick.setTooltip("");
	}
	Buttons_Main_A::modifierKeysChanged(mods);
}
