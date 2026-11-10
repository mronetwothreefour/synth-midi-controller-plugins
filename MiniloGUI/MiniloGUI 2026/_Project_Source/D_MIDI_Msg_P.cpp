#include "D_MIDI_Msg_P.h"

#include "C_MIDI_P.h"

using namespace MIDI;

// TODO: add current midi channel to device ID
MidiMessage MIDI::Msg::request_global() {
	unsigned char msg[]{ id_maker, id_device, 0, 1, 44, msg_type_request_global };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage MIDI::Msg::request_pgm(const uint8 bank, const uint8 slot) {
	unsigned char msg[]{ id_maker, id_device, 0, 1, 44, msg_type_request_pgm, bank, slot };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage MIDI::Msg::request_pgm_buffer() {
	unsigned char msg[]{ id_maker, id_device, 0, 1, 44, msg_type_request_pgm_buffer };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

