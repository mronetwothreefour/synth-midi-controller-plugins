#include "D_MIDI_Msg_P.h"

#include "C_MIDI_P.h"
#include "D_MIDI_Raw_Data_Tools_P.h"

#include "D_X_G_Data_Hub_P.h"

using namespace MIDI;

using Data = Raw_Data_Tools;

MidiMessage Msg::dump_global() {
	return {};
}

MidiMessage Msg::dump_pgm(Data_Hub* hub) {
	auto pgm_num = (uint8)hub->get_app_params().current_pgm_num();
	std::vector<uint8> msg{ id_maker, id_device, msg_type_dump_pgm, pgm_num };
	auto raw_pgm_data{ Data::extract_raw_pgm_data_from_app(hub) };
	for (auto byte : raw_pgm_data)
		msg.push_back(byte);
	return MidiMessage::createSysExMessage(msg.data(), sizeof(msg));
}

MidiMessage Msg::dump_split(const uint8 /*split_num*/) {
	return {};
}

MidiMessage Msg::dump_request_global() {
	unsigned char msg[]{ id_maker, id_device, msg_type_dump_request, msg_type_dump_global };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::dump_request_pgm(const uint8 num) {
	unsigned char msg[]{ id_maker, id_device, msg_type_dump_request, msg_type_dump_pgm, num };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::dump_request_split(const uint8 num) {
	unsigned char msg[]{ id_maker, id_device, msg_type_dump_request, msg_type_dump_split, num };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::quick_edit_enable() {
	unsigned char msg[]{ id_maker, id_device, msg_type_quick_edit_enable };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}

MidiMessage Msg::quick_edit_param(const uint8 quick_num, const uint8 val) {
	unsigned char msg[]{ id_maker, id_device, msg_type_quick_edit, quick_num, val };
	return MidiMessage::createSysExMessage(msg, sizeof(msg));
}
