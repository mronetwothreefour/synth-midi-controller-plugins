#include "D_MIDI_Msg_P.h"

#include "C_MIDI_P.h"

using namespace MIDI;

MidiBuffer Msg::nrpn_param_change(const uint8 chan, const int id, const int v) {
	MidiBuffer buf;
	auto cc = cc_msg_prefix + chan;
	buf.addEvent(MidiMessage{ cc, nrpn_id_msb, id / 128 }, 0);
	buf.addEvent(MidiMessage{ cc, nrpn_id_lsb, id % 128 }, 1);
	buf.addEvent(MidiMessage{ cc, nrpn_val_msb, v / 128 }, 2);
	buf.addEvent(MidiMessage{ cc, nrpn_val_lsb, v % 128 }, 3);
	return buf;
}

MidiMessage Msg::request_global() {
	unsigned char msg[]{ id_maker, id_device, msg_type_request_global };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::request_pgm(const uint8 bank, const uint8 slot) {
	unsigned char msg[]{ id_maker, id_device, msg_type_request_pgm, bank, slot };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::request_pgm_buffer() {
	unsigned char msg[]{ id_maker, id_device, msg_type_request_pgm_buffer };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

