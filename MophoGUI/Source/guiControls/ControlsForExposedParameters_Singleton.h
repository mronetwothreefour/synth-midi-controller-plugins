#pragma once

#include <JuceHeader.h>

#include "ControlForExposedParameter.h"



class ControlsForExposedParameters
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

	ControlsForExposedParameters();
	~ControlsForExposedParameters();

public:
	ControlsForExposedParameters(ControlsForExposedParameters&&) = delete;
	ControlsForExposedParameters& operator=(ControlsForExposedParameters&&) = delete;

	static ControlsForExposedParameters& get() noexcept;
	ControlForExposedParameter* controlFor(uint8 paramIndex) const;
	int paramOutOfRange() const;
	void clear();
	void rebuildControls();

private:
	void fillControlsVector();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsForExposedParameters)
};
