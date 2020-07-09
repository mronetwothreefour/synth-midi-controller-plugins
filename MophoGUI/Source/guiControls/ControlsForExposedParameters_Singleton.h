#pragma once

#include <JuceHeader.h>

#include "ControlForExposedParameter.h"



class ControlsForExposedParameters
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

	ControlsForExposedParameters() {
		fillControlsVector();
	}

	~ControlsForExposedParameters() {
		controlsVector.clear();
	}

	void fillControlsVector() {
		auto& info{ InfoForExposedParameters::get() };
		for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
			controlsVector.push_back(std::make_unique<ControlForExposedParameter>(param));
	}

public:
	ControlsForExposedParameters(ControlsForExposedParameters&&) = delete;
	ControlsForExposedParameters& operator=(ControlsForExposedParameters&&) = delete;

	static ControlsForExposedParameters& get() {
		static ControlsForExposedParameters controlsForExposedParameters;
		return controlsForExposedParameters;
	}

	ControlForExposedParameter* controlFor(uint8 paramIndex) {
		return controlsVector[paramIndex].get();
	}

	int paramOutOfRange() {
		return (int)controlsVector.size();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsForExposedParameters)
};
