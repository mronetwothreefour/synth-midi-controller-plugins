#include "widget_ControlsForExposedParameters.h"



ControlsForExposedParameters::ControlsForExposedParameters(UnexposedParameters* unexposedParams) {
	fillControlsVector(unexposedParams);
}

void ControlsForExposedParameters::fillControlsVector(UnexposedParameters* unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		controlsVector.push_back(std::make_unique<ControlForExposedParameter>(param, unexposedParams));
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

void ControlsForExposedParameters::rebuildControls(UnexposedParameters* unexposedParams) {
	controlsVector.clear();
	fillControlsVector(unexposedParams);
}
