#pragma once

#include <JuceHeader.h>

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;



struct ExposedParametersLayoutFactory
{
	static ParamLayout build();

private:
	static StringArray buildChoicesStringArrayFor(uint8 param);
};