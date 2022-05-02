#include "widget_ControlForExposedParameter.h"

#include "widget_ControlTypes.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../randomization/randomization_ParamRandomizationMethods.h"



ControlForExposedParameter::ControlForExposedParameter() :
	param{ (uint8)255 },
	exposedParams{ nullptr },
	unexposedParams{ nullptr },
	controlType{ ControlType::nullControl }
{
}

ControlForExposedParameter::ControlForExposedParameter(uint8 param, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	param{ param },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	controlType{ InfoForExposedParameters::get().controlTypeFor(param) }
{
	switch (controlType) {
	case ControlType::knobWithValueStringDisplay:
		buildKnobWithValueStringDisplayControlForExposedParam();
		break;
	case ControlType::knobForPitchWithValueStringDisplay:
		buildKnobForPitchWithValueStringDisplayControlForExposedParam();
		break;
	case ControlType::knobWithWaveShapeDisplay:
		buildKnobWithWaveShapeDisplayControlForExposedParam();
		break;
	case ControlType::toggleButton:
		buildToggleButtonControlForExposedParam();
		break;
	case ControlType::comboBox:
		buildComboBoxControlForExposedParam();
		break;
	case ControlType::voiceNameChar:
		buildVoiceNameCharacterControlForExposedParam();
		break;
	case ControlType::sequencerStep:
		buildSequencerStepControlForExposedParam();
		break;
	default:
		break;
	}
}

void ControlForExposedParameter::buildKnobWithValueStringDisplayControlForExposedParam() {
	knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(param, unexposedParams));
	addAndMakeVisible(knobWithValueStringDisplay.get());
	setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
	knobWithValueStringDisplay->addMouseListener(this, true);
}

void ControlForExposedParameter::buildKnobForPitchWithValueStringDisplayControlForExposedParam() {
	knobForPitchWithValueStringDisplay.reset(new KnobForPitchWithValueStringDisplay(param, unexposedParams));
	addAndMakeVisible(knobForPitchWithValueStringDisplay.get());
	setSize(knobForPitchWithValueStringDisplay->getWidth(), knobForPitchWithValueStringDisplay->getHeight());
	knobForPitchWithValueStringDisplay->addMouseListener(this, true);
}

void ControlForExposedParameter::buildKnobWithWaveShapeDisplayControlForExposedParam() {
	knobWithWaveShapeDisplay.reset(new KnobWithWaveShapeDisplay(param, unexposedParams));
	addAndMakeVisible(knobWithWaveShapeDisplay.get());
	setSize(knobWithWaveShapeDisplay->getWidth(), knobWithWaveShapeDisplay->getHeight());
	knobWithWaveShapeDisplay->addMouseListener(this, true);
}

void ControlForExposedParameter::buildToggleButtonControlForExposedParam() {
	toggleButton.reset(new ToggleButtonWithWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(toggleButton.get());
	toggleButton->setComponentID(ID::component_ToggleButton.toString());
	setSize(toggleButton->getWidth(), toggleButton->getHeight());
	toggleButton->addMouseListener(this, true);
}

void ControlForExposedParameter::buildComboBoxControlForExposedParam() {
	comboBox.reset(new ComboBoxWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(comboBox.get());
	setSize(comboBox->getWidth(), comboBox->getHeight());
	comboBox->addMouseListener(this, true);
}

void ControlForExposedParameter::buildVoiceNameCharacterControlForExposedParam() {
	voiceNameChar.reset(new VoiceNameCharWithExposedParamAttacher(param, unexposedParams));
	addAndMakeVisible(voiceNameChar.get());
	setSize(voiceNameChar->getWidth(), voiceNameChar->getHeight());
	voiceNameChar->addMouseListener(this, true);
}

void ControlForExposedParameter::buildSequencerStepControlForExposedParam() {
	sequencerStep.reset(new SequencerStepWithExposedParamAttacher(param, sequencerTrackThisStepIsOn(), unexposedParams));
	addAndMakeVisible(sequencerStep.get());
	setSize(sequencerStep->getWidth(), sequencerStep->getHeight());
	sequencerStep->addMouseListener(this, true);
}

int ControlForExposedParameter::sequencerTrackThisStepIsOn() {
	auto& info{ InfoForExposedParameters::get() };
	auto nrpn{ info.NRPNfor(param) };
	jassert(nrpn > 119 && nrpn < 184);
	return (nrpn - 104) / 16;
}

void ControlForExposedParameter::attachToExposedParameter() const {
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
	case ControlType::voiceNameChar:
		if (voiceNameChar != nullptr)
			voiceNameChar->attachToExposedParameter(exposedParams);
		break;
	default: break;
	}
}

void ControlForExposedParameter::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier) {
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(param).toString() };
		paramRandomizationMethods.randomizeParameter(paramID);
	}
}

void ControlForExposedParameter::deleteAttachment() const {
	if (knobWithValueStringDisplay != nullptr)
		knobWithValueStringDisplay->deleteAttachment();
	if (knobForPitchWithValueStringDisplay != nullptr)
		knobForPitchWithValueStringDisplay->deleteAttachment();
	if (knobWithWaveShapeDisplay != nullptr)
		knobWithWaveShapeDisplay->deleteAttachment();
	if (toggleButton != nullptr)
		toggleButton->deleteAttachment();
	if (comboBox != nullptr)
		comboBox->deleteAttachment();
	if (sequencerStep != nullptr)
		sequencerStep->deleteAttachment();
	if (voiceNameChar != nullptr)
		voiceNameChar->deleteAttachment();
}

ControlForExposedParameter::~ControlForExposedParameter() {
	if (knobWithValueStringDisplay != nullptr) {
		knobWithValueStringDisplay->removeMouseListener(this);
		knobWithValueStringDisplay = nullptr;
	}
	if (knobForPitchWithValueStringDisplay != nullptr) {
		knobForPitchWithValueStringDisplay->removeMouseListener(this);
		knobForPitchWithValueStringDisplay = nullptr;
	}
	if (knobWithWaveShapeDisplay != nullptr) {
		knobWithWaveShapeDisplay->removeMouseListener(this);
		knobWithWaveShapeDisplay = nullptr;
	}
	if (toggleButton != nullptr) {
		toggleButton->removeMouseListener(this);
		toggleButton = nullptr;
	}
	if (comboBox != nullptr) {
		comboBox->removeMouseListener(this);
		comboBox = nullptr;
	}
	if (sequencerStep != nullptr) {
		sequencerStep->removeMouseListener(this);
		sequencerStep = nullptr;
	}
}
