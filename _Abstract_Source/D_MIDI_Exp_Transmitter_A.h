#pragma once

#include <JuceHeader.h>

#include "D_TREE_App_Params_P.h"

using namespace TREE;

using Exp_Param = RangedAudioParameter;

namespace MIDI
{

	class Exp_Transmitter_A :
		public AudioProcessorParameter::Listener,
		public AsyncUpdater
	{
	protected: Exp_Param* param_ptr;
	protected: MidiBuffer& outgoing_midi;
	protected: App_Params& app_p;
	protected: const NormalisableRange<float> norm_range;
	protected: float last_norm_val;
	protected: float last_choice;
	protected: float max_choice_threshold;
	protected: float min_choice_threshold;

	//==============================================================================
	public: Exp_Transmitter_A(Exp_Param* exp_param_ptr, MidiBuffer& outgoing_midi,
							  App_Params& app_p);

	protected: virtual void transmit_change() = 0;
	public: void parameterValueChanged(int param_index, float new_norm_val) override;
	public: void parameterGestureChanged(int /*param_index*/, bool /*starting*/) override {}
	public: void handleAsyncUpdate() override;
	public: ~Exp_Transmitter_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exp_Transmitter_A)
	};

}
