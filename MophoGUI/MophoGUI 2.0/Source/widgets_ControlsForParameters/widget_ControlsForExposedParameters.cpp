#include "widget_ControlsForExposedParameters.h"



ControlsForExposedParameters::ControlsForExposedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	fillControlsVector(exposedParams, unexposedParams);
}

void ControlsForExposedParameters::fillControlsVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		controlsVector.push_back(std::make_unique<ControlForExposedParameter>(param, exposedParams, unexposedParams));
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

