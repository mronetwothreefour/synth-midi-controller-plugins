#pragma once

#include "D_MIDI_Incoming_Msg_Handler_A.h"

namespace MIDI
{

	class Incoming_Msg_Handler :
		public Incoming_Msg_Handler_A
	{
	//==============================================================================
	public: explicit Incoming_Msg_Handler(Data_Hub* hub);

	public: MidiBuffer extract_and_handle_relevant_midi_from(const MidiBuffer& buf) override;
	private: void handle_sysex_data(const uint8* data, const int size) override;
	private: void handle_pgm_data(const uint8* data, const int size) override;
	private: void handle_global_data(const uint8* data, const int size) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Incoming_Msg_Handler)
	};

}
