#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"

namespace MIDI
{

	class Incoming_Msg_Handler_A :
		public Data_User
	{
	//==============================================================================
	public: explicit Incoming_Msg_Handler_A(Data_Hub* hub) :
		Data_User{ hub }
	{}

	protected: virtual MidiBuffer extract_and_handle_relevant_midi_from(const MidiBuffer& /*buf*/)=0;
	protected: virtual void handle_sysex_data(const uint8* /*data*/, const int /*size*/)=0;
	protected: virtual void handle_pgm_data(const uint8* /*data*/, const int /*size*/)=0;
	protected: virtual void handle_global_data(const uint8* /*data*/, const int /*size*/) {};

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Incoming_Msg_Handler_A)
	};

}
