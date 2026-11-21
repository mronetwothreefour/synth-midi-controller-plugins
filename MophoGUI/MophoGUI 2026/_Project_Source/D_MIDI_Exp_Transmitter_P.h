#pragma once

#include "D_MIDI_Exp_Transmitter_A.h"

using namespace TREE;

namespace MIDI
{

	class Exp_Transmitter :
		public Exp_Transmitter_A
	{
	private: const int nrpn;

	//==============================================================================
	public: Exp_Transmitter(const std::string& param_id, Exp_Param* exp_param_ptr,
							MidiBuffer& outgoing_midi, App_Params& app_p);

	private: bool should_transmit(const float new_norm_val) override;
	private: void transmit_change() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exp_Transmitter)
	};

}
