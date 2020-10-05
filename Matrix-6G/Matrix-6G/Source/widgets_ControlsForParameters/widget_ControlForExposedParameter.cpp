#include "widget_ControlForExposedParameter.h"

#include "widget_ControlTypes.h"
#include "../params/params_Identifiers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"



ControlForExposedParameter::ControlForExposedParameter() :
	controlType{ ControlType::nullControl }
{
}

ControlForExposedParameter::ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams) :
	controlType{ InfoForExposedParameters::get().controlTypeFor(param) }
{
	switch (controlType)
	{
	case ControlType::rotarySlider:
		buildRotarySliderForExposedParam(param, unexposedParams);
		break;
	case ControlType::linearSlider:
		break;
	case ControlType::pgmSlotRadioButton:
		break;
	case ControlType::comboBox:
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::buildRotarySliderForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	rotarySlider.reset(new RotarySliderWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(rotarySlider.get());
	setSize(rotarySlider->getWidth(), rotarySlider->getHeight());
}

void ControlForExposedParameter::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const {
	jassert(exposedParams != nullptr);
	switch (controlType)
	{
	case ControlType::rotarySlider:
		if (rotarySlider != nullptr)
			rotarySlider->attachToExposedParameter(exposedParams);
		break;
	case ControlType::linearSlider:
		break;
	case ControlType::pgmSlotRadioButton:
		break;
	case ControlType::comboBox:
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::deleteAttachment() const {
	if (rotarySlider != nullptr)
		rotarySlider->deleteAttachment();
}

ControlForExposedParameter::~ControlForExposedParameter() {
	rotarySlider = nullptr;
}
