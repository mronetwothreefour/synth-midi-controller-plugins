#include "ControlsForExposedParameters_Singleton.h"



ControlsForExposedParameters::ControlsForExposedParameters() {
}

ControlsForExposedParameters::~ControlsForExposedParameters() {
}

ControlsForExposedParameters& ControlsForExposedParameters::get() noexcept {
	static ControlsForExposedParameters controlsForExposedParameters;
	return controlsForExposedParameters;
}

ControlForExposedParameter* ControlsForExposedParameters::controlFor(uint8 paramIndex) const {
	return controlsVector[paramIndex].get();
}

int ControlsForExposedParameters::paramOutOfRange() const {
	return (int)controlsVector.size();
}

void ControlsForExposedParameters::clear() {
	controlsVector.clear();
}

void ControlsForExposedParameters::rebuildControls() {
	controlsVector.clear();
	fillControlsVector();
}

void ControlsForExposedParameters::fillControlsVector() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		controlsVector.push_back(std::make_unique<ControlForExposedParameter>(param));
}