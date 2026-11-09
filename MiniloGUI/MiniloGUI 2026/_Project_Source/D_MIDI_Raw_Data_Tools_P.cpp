#include "D_MIDI_Raw_Data_Tools_P.h"

#include "C_GET_P.h"
#include "C_MIDI_P.h"

using namespace MIDI;

const bool Raw_Data_Tools::is_relevant_sysex(const MidiMessage& msg) {
	if (msg.isSysEx()) {
		auto d = msg.getSysExData();
		// TODO: check if global MIDI channel matches second digit of d[2]
		return d[1] == id_maker && d[2] >= id_device && d[2] < id_device + 16;
	}
	return false;
}
