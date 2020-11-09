#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class UnexposedParametersControlsLayer :
	public Component
{
	UnexposedParameters* unexposedParams;

public:
	UnexposedParametersControlsLayer() = delete;

	explicit UnexposedParametersControlsLayer(UnexposedParameters* unexposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParametersControlsLayer)
};