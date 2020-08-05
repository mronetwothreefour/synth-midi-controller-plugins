#include "ControlForExposedParameter.h"

#include "../helpers/helper_ControlTypes.h"



ControlForExposedParameter::ControlForExposedParameter() :
	controlType{ ControlType::nullControl }
{
}

ControlForExposedParameter::~ControlForExposedParameter() {
	knobWithValueStringDisplay = nullptr;
	knobWithWaveShapeDisplay = nullptr;
	toggleButton = nullptr;
	comboBox = nullptr;
	sequencerStep = nullptr;
}

ControlForExposedParameter::ControlForExposedParameter(uint8 param) :
	controlType{ InfoForExposedParameters::get().controlTypeFor(param) }
{
	switch (controlType) {
	case ControlType::knobWithValueStringDisplay:
		buildKnobWithValueStringDisplayControlForExposedParam(param);
		break;
	case ControlType::knobWithWaveShapeDisplay:
		buildKnobWithWaveShapeDisplayControlForExposedParam(param);
		break;
	case ControlType::toggleButton:
		buildToggleButtonControlForExposedParam(param);
		break;
	case ControlType::comboBox:
		buildComboBoxControlForExposedParam(param);
		break;
	case ControlType::pgmNameChar:
		buildProgramNameCharacterControlForExposedParam(param);
		break;
	case ControlType::sequencerStep:
		buildSequencerStepControlForExposedParam(param);
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::buildKnobWithValueStringDisplayControlForExposedParam(uint8 param) {
	knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(param));
	addAndMakeVisible(*knobWithValueStringDisplay);
	setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
}

void ControlForExposedParameter::buildKnobWithWaveShapeDisplayControlForExposedParam(uint8 param) {
	knobWithWaveShapeDisplay.reset(new KnobWithWaveShapeDisplay(param));
	addAndMakeVisible(*knobWithWaveShapeDisplay);
	setSize(knobWithWaveShapeDisplay->getWidth(), knobWithWaveShapeDisplay->getHeight());
}

void ControlForExposedParameter::buildToggleButtonControlForExposedParam(uint8 param) {
	toggleButton.reset(new ToggleButtonWithWithExposedParamAttacher(param));
	addAndMakeVisible(*toggleButton);
	toggleButton->setComponentID(ID::component_ToggleButton.toString());
	setSize(toggleButton->getWidth(), toggleButton->getHeight());
}

void ControlForExposedParameter::buildComboBoxControlForExposedParam(uint8 param) {
	comboBox.reset(new ComboBoxWithExposedParamAttacher(param));
	addAndMakeVisible(*comboBox);
	setSize(comboBox->getWidth(), comboBox->getHeight());
}

void ControlForExposedParameter::buildProgramNameCharacterControlForExposedParam(uint8 param) {
	pgmNameChar.reset(new PgmNameCharWithExposedParamAttacher(param));
	addAndMakeVisible(*pgmNameChar);
	setSize(pgmNameChar->getWidth(), pgmNameChar->getHeight());
}

void ControlForExposedParameter::buildSequencerStepControlForExposedParam(uint8 param) {
	sequencerStep.reset(new SequencerStepWithExposedParamAttacher(param, sequencerTrackThisStepIsOn(param)));
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
