#pragma once

#include <JuceHeader.h>

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;

// Has a createLayout() function which programmatically generates
// an AudioProcessorValueTreeState::ParameterLayout
class PublicParameters
{
public:
	PublicParameters() = default;

	~PublicParameters() = default;

	// Creates a layout of the parameters which will be exposed to the host.
	// This layout is then used to initialize the AudioProcessorValueTreeState.
	ParamLayout createLayout()
	{
		ParamLayout layout;
		layout.add(std::make_unique<AudioParameterInt>("osc1Freq", "Oscillator 1 Pitch", 0, 120, 24));
		layout.add(std::make_unique<AudioParameterFloat>("dingle", "Dingle", 0.0f, 1.0f, 0.5f));
		return layout;
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};