#pragma once

#include <JuceHeader.h>

using ParameterLayout = AudioProcessorValueTreeState::ParameterLayout;



struct ExposedParametersLayout
{
	static ParameterLayout build();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersLayout)
};