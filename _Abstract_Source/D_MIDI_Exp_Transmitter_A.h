#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	class Exp_Transmitter_A :
		public Value::Listener
	{
	protected: Value param_val;
	protected: MidiBuffer& outgoing_midi;

	//==============================================================================
	public: Exp_Transmitter_A(Value param_value, MidiBuffer& outgoing_midi);

	protected: virtual void transmit_change()=0;
	public: void valueChanged(Value& value) override;
	public: ~Exp_Transmitter_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exp_Transmitter_A)
	};

}
