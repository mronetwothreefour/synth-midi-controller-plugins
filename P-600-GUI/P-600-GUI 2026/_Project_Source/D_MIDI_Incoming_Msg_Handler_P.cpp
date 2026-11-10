#include "D_MIDI_Incoming_Msg_Handler_P.h"

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

void Incoming_Msg_Handler::handle_sysex_data(const uint8* /*data*/, const int /*size*/)
{
}

void Incoming_Msg_Handler::handle_pgm_data(const uint8* /*data*/, const int /*size*/)
{
}
