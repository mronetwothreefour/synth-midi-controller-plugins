#include "D_MIDI_Msg_P.h"

#include "C_MIDI_P.h"

using namespace MIDI;

MidiMessage MIDI::Msg::dump_request_global() {
	unsigned char msg[]{ id_maker, id_device, msg_type_dump_request, mode_global };
	return MidiMessage();
}

MidiMessage MIDI::Msg::dump_request_pgm(const uint8 num) {
	unsigned char msg[]{ id_maker, id_device, msg_type_dump_request, mode_pgm, num };
	return MidiMessage();
}

MidiMessage MIDI::Msg::dump_request_split(const uint8 num) {
	unsigned char msg[]{ id_maker, id_device, msg_type_dump_request, mode_split, num };
	return MidiMessage();
}

MidiMessage Msg::quick_edit_enable() {
	unsigned char msg[]{ id_maker, id_device, msg_type_quick_edit_enable };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}
