#include "D_MIDI_Incoming_Msg_Handler_P.h"

#include "C_MIDI_P.h"
#include "D_CONVERT_P.h"
#include "D_MIDI_Raw_Data_Tools_P.h"

using namespace MIDI;

using Data = Raw_Data_Tools;

Incoming_Msg_Handler::Incoming_Msg_Handler(Data_Hub* hub) :
	Incoming_Msg_Handler_A{ hub }
{}

MidiBuffer Incoming_Msg_Handler::extract_and_handle_relevant_midi_from(const MidiBuffer& buf) {
	MidiBuffer rtn_buf;
	for (auto event : buf) {
		auto msg = event.getMessage();
		if (Data::is_relevant_sysex(msg))
			handle_sysex_data(msg.getSysExData(), msg.getSysExDataSize());
		else rtn_buf.addEvent(msg, event.samplePosition);
	}
	return rtn_buf;
}

void Incoming_Msg_Handler::handle_sysex_data(const uint8* data, const int size) {
	auto msg_type = data[2];
	if (msg_type == msg_type_dump_pgm)
		handle_pgm_dump(data, size);
	if (msg_type == msg_type_dump_split)
		handle_split_dump(data, size);
	if (msg_type == msg_type_dump_global)
		handle_global_dump(data, size);
}

void Incoming_Msg_Handler::handle_pgm_dump(const uint8* data, const int /*size*/) {
	auto pgm_num = data[3];
	Data::apply_raw_pgm_data_to_app(pgm_num, data + 4, hub);
	if (app_p.store_incoming_pgm_dump()) {
		// TODO: storing program in bank / slot
		//std::vector<uint8> pgm_data;
		//for (int byte = 5; byte < size; ++byte)
		//	pgm_data.push_back(*(data + byte));
		//auto pgm_hex_string{ CONVERT::to_hex_string(pgm_data) };
		//auto bank{ transmitOptions->bankToStoreIn() };
		//voicesBanks->storeVoiceDataHexStringInCustomBankSlot(pgm_hex_string, bank, pgm_num);
		app_p.set_store_incoming_pgm_dump(false);
	}
}

void Incoming_Msg_Handler::handle_split_dump(const uint8* /*data*/, const int /*size*/)
{
}

void Incoming_Msg_Handler::handle_global_dump(const uint8* /*data*/, const int /*size*/)
{
}
