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
	case ControlType::knobWithWaveShapeDisplay:
		buildKnobWithWaveShapeDisplayControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::toggleButton:
		buildToggleButtonControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::comboBox:
		buildComboBoxControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::pgmNameChar:
		buildProgramNameCharacterControlForExposedParam(param, unexposedParams);
		break;
	case ControlType::sequencerStep:
		buildSequencerStepControlForExposedParam(param, unexposedParams);
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::buildKnobWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(param, unexposedParams));
	addAndMakeVisible(*knobWithValueStringDisplay);
	setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
}

void ControlForExposedParameter::buildKnobWithWaveShapeDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	knobWithWaveShapeDisplay.reset(new KnobWithWaveShapeDisplay(param, unexposedParams));
	addAndMakeVisible(*knobWithWaveShapeDisplay);
	setSize(knobWithWaveShapeDisplay->getWidth(), knobWithWaveShapeDisplay->getHeight());
}

void ControlForExposedParameter::buildToggleButtonControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	toggleButton.reset(new ToggleButtonWithWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(*toggleButton);
	toggleButton->setComponentID(ID::component_ToggleButton.toString());
	setSize(toggleButton->getWidth(), toggleButton->getHeight());
}

void ControlForExposedParameter::buildComboBoxControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	comboBox.reset(new ComboBoxWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(*comboBox);
	setSize(comboBox->getWidth(), comboBox->getHeight());
}

void ControlForExposedParameter::buildProgramNameCharacterControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	pgmNameChar.reset(new ProgramNameCharWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(*pgmNameChar);
	setSize(pgmNameChar->getWidth(), pgmNameChar->getHeight());
}

void ControlForExposedParameter::buildSequencerStepControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams) {
	sequencerStep.reset(new SequencerStepWithExposedParamAttacher(param, sequencerTrackThisStepIsOn(param), unexposedParams));
	addAndMakeVisible(*sequencerStep);
	setSize(sequencerStep->getWidth(), sequencerStep->getHeight());
}

int ControlForExposedParameter::sequencerTrackThisStepIsOn(uint8 param) {
	auto& info{ InfoForExposedParameters::get() };
	auto nrpn{ info.NRPNfor(param) };
	jassert(nrpn > 119 && nrpn < 184);
	return (nrpn - 104) / 16;
}

void ControlForExposedParameter::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const {
	jassert(exposedParams != nullptr);
	switch (controlType)
	{
	case ControlType::knobWithValueStringDisplay:
		if (knobWithValueStringDisplay != nullptr)
			knobWithValueStringDisplay->attachToExposedParameter(exposedParams);
		break;
	case ControlType::knobWithWaveShapeDisplay:
		if (knobWithWaveShapeDisplay != nullptr)
			knobWithWaveShapeDisplay->attachToExposedParameter(exposedParams);
		break;
	case ControlType::toggleButton:
		if (toggleButton != nullptr)
			toggleButton->attachToExposedParameter(exposedParams);
		break;
	case ControlType::comboBox:
		if (comboBox != nullptr)
			comboBox->attachToExposedParameter(exposedParams);
		break;
	case ControlType::sequencerStep:
		if (sequencerStep != nullptr)
			sequencerStep->attachToExposedParameter(exposedParams);
		break;
	case ControlType::pgmNameChar:
		if (pgmNameChar != nullptr)
			pgmNameChar->attachToExposedParameter(exposedParams);
		break;
	default: break;
	}
}

void ControlForExposedParameter::deleteAttachment() const {
	if (knobWithValueStringDisplay != nullptr)
		knobWithValueStringDisplay->deleteAttachment();
	if (knobWithWaveShapeDisplay != nullptr)
		knobWithWaveShapeDisplay->deleteAttachment();
	if (toggleButton != nullptr)
		toggleButton->deleteAttachment();
	if (comboBox != nullptr)
		comboBox->deleteAttachment();
	if (sequencerStep != nullptr)
		sequencerStep->deleteAttachment();
	if (pgmNameChar != nullptr)
		pgmNameChar->deleteAttachment();
}

ControlForExposedParameter::~ControlForExposedParameter() {
	knobWithValueStringDisplay = nullptr;
	knobWithWaveShapeDisplay = nullptr;
	toggleButton = nullptr;
	comboBox = nullptr;
	sequencerStep = nullptr;
}
