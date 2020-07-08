#pragma once

#include <JuceHeader.h>

#include "ControlForExposedParameter.h"



struct ControlsForExposedParameters
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

	ControlsForExposedParameters(ControlsForExposedParameters const&) = delete;
	ControlsForExposedParameters(ControlsForExposedParameters&&) = delete;
	ControlsForExposedParameters& operator=(ControlsForExposedParameters const&) = delete;
	ControlsForExposedParameters& operator=(ControlsForExposedParameters&&) = delete;

	static std::vector<std::unique_ptr<ControlForExposedParameter>>& get() {
		static ControlsForExposedParameters controlDatabase;
		return controlDatabase.controlsVector;
	}

private:
	ControlsForExposedParameters() {
		fillControlsVector();
	}

	~ControlsForExposedParameters() {
		controlsVector.clear();
	}

	void fillControlsVector() {
		for (uint8 param = 0; param != InfoForExposedParameters::get().numberOfExposedParameters(); ++param) {
			controlsVector.push_back(std::make_unique<ControlForExposedParameter>(param));
		}
	}
};
