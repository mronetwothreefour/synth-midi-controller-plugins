#include "widget_ControlForExposedParameter.h"

#include "widget_ControlTypes.h"
#include "../params/params_Identifiers.h"



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
	}
}

void ControlForExposedParameter::deleteAttachment() const {
	if (knobWithValueStringDisplay != nullptr)
		knobWithValueStringDisplay->deleteAttachment();
	if (knobForPitchWithValueStringDisplay != nullptr)
		knobForPitchWithValueStringDisplay->deleteAttachment();
}

ControlForExposedParameter::~ControlForExposedParameter() {
	knobWithValueStringDisplay = nullptr;
	knobForPitchWithValueStringDisplay = nullptr;
}
