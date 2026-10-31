#pragma once

#include "D_MIDI_Exp_Transmitter_A.h"

using namespace TREE;

namespace MIDI
{

	class Exp_Transmitter :
		public Exp_Transmitter_A
	{
	//==============================================================================
	public: Exp_Transmitter(const std::string& param_id, Value param_value, 
							MidiBuffer& outgoing_midi, App_Params& app_p);

	private: void transmit_change() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exp_Transmitter)
	};

}
