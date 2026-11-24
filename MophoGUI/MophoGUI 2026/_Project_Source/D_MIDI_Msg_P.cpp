#include "D_MIDI_Msg_P.h"

#include "C_MIDI_P.h"
#include "D_MIDI_Raw_Data_Tools_P.h"

#include "D_X_G_Data_Hub_P.h"

using namespace MIDI;

using Data = Raw_Data_Tools;

MidiMessage MIDI::Msg::dump_global() {
	return MidiMessage();
}

MidiMessage MIDI::Msg::dump_pgm(const uint8 /*bnk*/, const uint8 /*pgm*/, Data_Hub* /*hub*/) {
	return MidiMessage();
}

MidiMessage MIDI::Msg::dump_pgm_buffer(Data_Hub* hub) {
	std::vector<uint8> msg{ id_maker, id_device, msg_type_dump_pgm_buffer };
	auto raw_pgm_data{ Data::extract_raw_data_from_current_pgm(hub) };
	for (auto byte : raw_pgm_data)
		msg.push_back(byte);
	for (auto pad_byte = raw_pgm_data.size(); pad_byte < data_size_pgm; ++pad_byte)
		msg.push_back((uint8)0);
	return MidiMessage::createSysExMessage(msg.data(), (int)msg.size());
}

MidiMessage Msg::dump_request_global() {
	unsigned char msg[]{ id_maker, id_device, msg_type_request_global };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::dump_request_pgm(const uint8 bnk, const uint8 pgm) {
	unsigned char msg[]{ id_maker, id_device, msg_type_request_pgm, bnk, pgm };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::dump_request_pgm_buffer() {
	unsigned char msg[]{ id_maker, id_device, msg_type_request_pgm_buffer };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiBuffer Msg::nrpn_param_change(const uint8 chan, const int id, const int v) {
	MidiBuffer buf;
	auto cc = cc_msg_prefix + chan;
	buf.addEvent(MidiMessage{ cc, nrpn_id_msb, id / 128 }, 0);
	buf.addEvent(MidiMessage{ cc, nrpn_id_lsb, id % 128 }, 1);
	buf.addEvent(MidiMessage{ cc, nrpn_val_msb, v / 128 }, 2);
	buf.addEvent(MidiMessage{ cc, nrpn_val_lsb, v % 128 }, 3);
	return buf;
}

