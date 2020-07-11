#pragma once

#include <JuceHeader.h>

#include "ControlForExposedParameter.h"



class ControlsForExposedParameters
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

	ControlsForExposedParameters() {
	}

	~ControlsForExposedParameters() {
	}

	void fillControlsVector() {
		auto& info{ InfoForExposedParameters::get() };
		for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
			controlsVector.push_back(std::make_unique<ControlForExposedParameter>(param));
	}

public:
	ControlsForExposedParameters(ControlsForExposedParameters&&) = delete;
	ControlsForExposedParameters& operator=(ControlsForExposedParameters&&) = delete;

	static ControlsForExposedParameters& get() noexcept {
		static ControlsForExposedParameters controlsForExposedParameters;
		return controlsForExposedParameters;
	}

	ControlForExposedParameter* controlFor(uint8 paramIndex) const {
		return controlsVector[paramIndex].get();
	}

	int paramOutOfRange() const noexcept {
		return (int)controlsVector.size();
	}

	void clear() {
		controlsVector.clear();
	}

	void rebuildControls(){
		controlsVector.clear();
		fillControlsVector();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsForExposedParameters)
};
