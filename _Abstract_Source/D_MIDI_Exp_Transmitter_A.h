#pragma once

#include <JuceHeader.h>

#include "D_TREE_App_Params_P.h"

using namespace TREE;

namespace MIDI
{

	class Exp_Transmitter_A :
		public AudioProcessorParameter::Listener
	{
	protected: const String param_id;
	protected: AudioProcessorValueTreeState* state;
	protected: MidiBuffer& outgoing_midi;
	protected: App_Params& app_p;

	//==============================================================================
	public: Exp_Transmitter_A(const String& param_id, AudioProcessorValueTreeState* exp_state, MidiBuffer& outgoing_midi, App_Params& app_p);

	protected: virtual void transmit_change(const uint8 new_val) = 0;
	public: void parameterValueChanged(int param_index, float new_val) override;
	public: void parameterGestureChanged(int /*param_index*/, bool /*starting*/) override {}
	public: ~Exp_Transmitter_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exp_Transmitter_A)
	};

}
