#pragma once

#include <JuceHeader.h>

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;



// Builds the plugin parameters that are exposed to the plugin host
struct ExposedParametersLayoutFactory
{
	static ParamLayout build();

private:
	static StringArray buildChoicesStringArrayFor(uint8 param);
};