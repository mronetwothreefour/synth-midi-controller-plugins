#include "D_MIDI_Msg_P.h"

#include "C_MIDI_P.h"

using namespace MIDI;

MidiMessage MIDI::Msg::dump_request_pgm(const uint8 num) {
	unsigned char msg[]{ id_maker, msg_type_request_pgm, num };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}
