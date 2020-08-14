#pragma once

#include <JuceHeader.h>

#include "widget_ControlForExposedParameter.h"



class ControlsForExposedParameters
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

public:
	explicit ControlsForExposedParameters(UnexposedParameters* unexposedParams);

private:
	void fillControlsVector(UnexposedParameters* unexposedParams);

public:
	ControlForExposedParameter* controlFor(uint8 paramIndex) const;
	int paramOutOfRange() const;
	void clearControls();
	void rebuildControls(UnexposedParameters* unexposedParams);
	~ControlsForExposedParameters();


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsForExposedParameters)
};
