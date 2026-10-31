#pragma once

#include <JuceHeader.h>

#include "D_TREE_App_Params_P.h"

using namespace TREE;

namespace MIDI
{

	class Exp_Transmitter_A :
		public Value::Listener
	{
	protected: Value param_val;
	protected: MidiBuffer& outgoing_midi;
	protected: App_Params& app_p;

	//==============================================================================
	public: Exp_Transmitter_A(Value param_value, MidiBuffer& outgoing_midi, App_Params& app_p);

	protected: virtual void transmit_change()=0;
	public: void valueChanged(Value& value) override;
	public: ~Exp_Transmitter_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exp_Transmitter_A)
	};

}
