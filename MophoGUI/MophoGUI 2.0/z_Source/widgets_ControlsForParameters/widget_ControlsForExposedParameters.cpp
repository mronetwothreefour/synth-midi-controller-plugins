#include "widget_ControlsForExposedParameters.h"

#include "../params/params_Constants.h"

using namespace constants;



ControlsForExposedParameters::ControlsForExposedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	fillControlsVector(exposedParams, unexposedParams);
}

void ControlsForExposedParameters::fillControlsVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	for (uint8 paramIndex = 0; paramIndex != params::numberOfExposedParams; ++paramIndex)
		controlsVector.push_back(std::make_unique<ControlForExposedParameter>(paramIndex, exposedParams, unexposedParams));
}

ControlForExposedParameter* ControlsForExposedParameters::controlFor(uint8 paramIndex) const {
	return controlsVector[paramIndex].get();
}

int ControlsForExposedParameters::paramOutOfRange() const {
	return (int)controlsVector.size();
}

void ControlsForExposedParameters::clearControls() {
	controlsVector.clear();
}

void ControlsForExposedParameters::rebuildControls(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	controlsVector.clear();
	fillControlsVector(exposedParams, unexposedParams);
}

