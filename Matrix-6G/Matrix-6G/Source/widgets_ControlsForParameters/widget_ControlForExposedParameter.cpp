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
	case ControlType::rotarySliderForPitch:
		buildRotarySliderForExposedPitchParam(param, unexposedParams);
		break;
	case ControlType::linearSlider:
		buildLinearSliderForExposedParam(param, unexposedParams);
		break;
	case ControlType::pgmSlotRadioButton:
		break;
	case ControlType::comboBox:
		buildComboBoxControlForExposedParam(param, unexposedParams);
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::buildComboBoxControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	comboBox.reset(new ComboBoxWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(comboBox.get());
	setSize(comboBox->getWidth(), comboBox->getHeight());
}

void ControlForExposedParameter::buildLinearSliderForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	linearSlider.reset(new LinearSliderWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(linearSlider.get());
	setSize(linearSlider->getWidth(), linearSlider->getHeight());
}

void ControlForExposedParameter::buildRotarySliderForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	rotarySlider.reset(new RotarySliderWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(rotarySlider.get());
	setSize(rotarySlider->getWidth(), rotarySlider->getHeight());
}

void ControlForExposedParameter::buildRotarySliderForExposedPitchParam(uint8 param, UnexposedParameters* unexposedParams) {
	rotarySliderForPitch.reset(new RotarySliderForPitchWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(rotarySliderForPitch.get());
	setSize(rotarySliderForPitch->getWidth(), rotarySliderForPitch->getHeight());
}

void ControlForExposedParameter::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const {
	jassert(exposedParams != nullptr);
	switch (controlType)
	{
	case ControlType::rotarySlider:
		if (rotarySlider != nullptr)
			rotarySlider->attachToExposedParameter(exposedParams);
		break;
	case ControlType::rotarySliderForPitch:
		if (rotarySliderForPitch != nullptr)
			rotarySliderForPitch->attachToExposedParameter(exposedParams);
		break;
	case ControlType::linearSlider:
		if (linearSlider != nullptr)
			linearSlider->attachToExposedParameter(exposedParams);
		break;
	case ControlType::pgmSlotRadioButton:
		break;
	case ControlType::comboBox:
		if (comboBox != nullptr)
			comboBox->attachToExposedParameter(exposedParams);
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::deleteAttachment() const {
	if (comboBox != nullptr)
		comboBox->deleteAttachment();
	if (linearSlider != nullptr)
		linearSlider->deleteAttachment();
	if (rotarySlider != nullptr)
		rotarySlider->deleteAttachment();
	if (rotarySliderForPitch != nullptr)
		rotarySliderForPitch->deleteAttachment();
}

ControlForExposedParameter::~ControlForExposedParameter() {
	comboBox = nullptr;
	linearSlider = nullptr;
	rotarySlider = nullptr;
	rotarySliderForPitch = nullptr;
}
