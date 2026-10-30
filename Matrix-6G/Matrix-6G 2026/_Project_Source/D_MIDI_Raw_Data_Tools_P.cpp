#include "D_MIDI_Raw_Data_Tools_P.h"

#include "C_MIDI_P.h"

using namespace MIDI;

const bool Raw_Data_Tools::is_relevant_sysex(const MidiMessage& msg) {
	if (msg.isSysEx()) {
		auto d = msg.getSysExData();
		return d[1] == id_maker && d[2] == id_device;
	}
	return false;
}
