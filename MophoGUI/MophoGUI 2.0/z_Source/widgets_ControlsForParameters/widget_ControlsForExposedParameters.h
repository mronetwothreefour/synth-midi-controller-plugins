#pragma once

#include <JuceHeader.h>

#include "widget_ControlForExposedParameter.h"



class ControlsForExposedParameters
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

public:
	ControlsForExposedParameters() = delete;

	explicit ControlsForExposedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void fillControlsVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

public:
	ControlForExposedParameter* controlFor(uint8 paramIndex) const;
	int paramOutOfRange() const;
	void clearControls();
	void rebuildControls(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsForExposedParameters)
};
