#include "widget_ControlForExposedParameter.h"

#include "widget_ControlTypes.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



ControlForExposedParameter::ControlForExposedParameter() :
	controlType{ ControlType::nullControl }
{
}

ControlForExposedParameter::ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams) :
	controlType{ InfoForExposedParameters::get().controlTypeFor(param) }
{
	switch (controlType) {
	case ControlType::knobWithValueStringDisplay:
		buildKnobWithValueStringDisplayControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::knobForPitchWithValueStringDisplay:
		buildKnobForPitchWithValueStringDisplayControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::twoPoleSwitch:
		buildTwoPoleSwitchControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::threePoleSwitch:
		buildThreePoleSwitchControlForExposedParam(param, unexposedParams);
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::buildKnobWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(param, unexposedParams));
	addAndMakeVisible(knobWithValueStringDisplay.get());
	setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
}

void ControlForExposedParameter::buildKnobForPitchWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	knobForPitchWithValueStringDisplay.reset(new KnobForPitchWithValueStringDisplay(param, unexposedParams));
	addAndMakeVisible(knobForPitchWithValueStringDisplay.get());
	setSize(knobForPitchWithValueStringDisplay->getWidth(), knobForPitchWithValueStringDisplay->getHeight());
}

void ControlForExposedParameter::buildTwoPoleSwitchControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	twoPoleSwitchWithExposedParamAttacher.reset(new SwitchSliderWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(twoPoleSwitchWithExposedParamAttacher.get());
	setSize(GUI::switches_w, GUI::switchTwoPole_h);
}

void ControlForExposedParameter::buildThreePoleSwitchControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	threePoleSwitchWithExposedParamAttacher.reset(new SwitchSliderWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(threePoleSwitchWithExposedParamAttacher.get());
	setSize(GUI::switches_w, GUI::switchThreePole_h);
}

void ControlForExposedParameter::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const {
	jassert(exposedParams != nullptr);
	switch (controlType)
	{
	case ControlType::knobWithValueStringDisplay:
		if (knobWithValueStringDisplay != nullptr)
			knobWithValueStringDisplay->attachToExposedParameter(exposedParams);
		break;
	case ControlType::knobForPitchWithValueStringDisplay:
		if (knobForPitchWithValueStringDisplay != nullptr)
			knobForPitchWithValueStringDisplay->attachToExposedParameter(exposedParams);
		break;
	case ControlType::twoPoleSwitch:
		if (twoPoleSwitchWithExposedParamAttacher != nullptr)
			twoPoleSwitchWithExposedParamAttacher->attachToExposedParameter(exposedParams);
		break;
	case ControlType::threePoleSwitch:
		if (threePoleSwitchWithExposedParamAttacher != nullptr)
			threePoleSwitchWithExposedParamAttacher->attachToExposedParameter(exposedParams);
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::deleteAttachment() const {
	if (knobWithValueStringDisplay != nullptr)
		knobWithValueStringDisplay->deleteAttachment();
	if (knobForPitchWithValueStringDisplay != nullptr)
		knobForPitchWithValueStringDisplay->deleteAttachment();
	if (twoPoleSwitchWithExposedParamAttacher != nullptr)
		twoPoleSwitchWithExposedParamAttacher->deleteAttachment();
	if (threePoleSwitchWithExposedParamAttacher != nullptr)
		threePoleSwitchWithExposedParamAttacher->deleteAttachment();
}

ControlForExposedParameter::~ControlForExposedParameter() {
	knobWithValueStringDisplay = nullptr;
	knobForPitchWithValueStringDisplay = nullptr;
	twoPoleSwitchWithExposedParamAttacher = nullptr;
	threePoleSwitchWithExposedParamAttacher = nullptr;
}
