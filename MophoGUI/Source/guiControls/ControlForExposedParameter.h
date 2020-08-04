#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../widgets/widget_ComboBoxWithExposedParamAttacher.h"
#include "../widgets/widget_KnobWithValueStringDisplay.h"
#include "../widgets/widget_KnobWithWaveShapeDisplay.h"
#include "../widgets/widget_ProgramNameCharacters.h"
#include "../widgets/widget_SequencerSteps.h"
#include "../widgets/widget_ToggleButtonWithWithExposedParamAttacher.h"



class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobWithWaveShapeDisplay> knobWithWaveShapeDisplay;
	std::unique_ptr<ToggleButtonWithWithExposedParamAttacher> toggleButton;
	std::unique_ptr<ComboBoxWithExposedParamAttacher> comboBox;
	std::unique_ptr<SequencerStepWithExposedParamAttacher> sequencerStep;
	std::unique_ptr<PgmNameCharWithExposedParamAttacher> pgmNameChar;

	ControlForExposedParameter() : 
		controlType{ ControlType::nullControl } 
	{
	}

	int sequencerTrackThisStepIsOn(uint8 param) {
		auto& info{ InfoForExposedParameters::get() };
		auto nrpn{ info.NRPNfor(param) };
		jassert(nrpn > 119 && nrpn < 184);
		return (nrpn - 104) / 16;
	}

public:
	explicit ControlForExposedParameter(uint8 param) :
		controlType{ InfoForExposedParameters::get().controlTypeFor(param) }
	{
		switch (controlType) {
		case ControlType::knobWithValueStringDisplay:
			knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(param));
			addAndMakeVisible(*knobWithValueStringDisplay);
			setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
			break;
		case ControlType::knobWithWaveShapeDisplay:
			knobWithWaveShapeDisplay.reset(new KnobWithWaveShapeDisplay(param));
			addAndMakeVisible(*knobWithWaveShapeDisplay);
			setSize(knobWithWaveShapeDisplay->getWidth(), knobWithWaveShapeDisplay->getHeight());
			break;
		case ControlType::toggleButton:
			toggleButton.reset(new ToggleButtonWithWithExposedParamAttacher(param));
			addAndMakeVisible(*toggleButton);
			toggleButton->setComponentID(ID::component_ToggleButton.toString());
			setSize(toggleButton->getWidth(), toggleButton->getHeight());
			break;
		case ControlType::comboBox:
			comboBox.reset(new ComboBoxWithExposedParamAttacher(param));
			addAndMakeVisible(*comboBox);
			setSize(comboBox->getWidth(), comboBox->getHeight());
			break;
		case ControlType::sequencerStep:
			sequencerStep.reset(new SequencerStepWithExposedParamAttacher(param, sequencerTrackThisStepIsOn(param)));
			addAndMakeVisible(*sequencerStep);
			setSize(sequencerStep->getWidth(), sequencerStep->getHeight());
			break;
		case ControlType::pgmNameChar:
			pgmNameChar.reset(new PgmNameCharWithExposedParamAttacher(param));
			addAndMakeVisible(*pgmNameChar);
			setSize(pgmNameChar->getWidth(), pgmNameChar->getHeight());
			break;
		default:
			break;
		}
	}

	~ControlForExposedParameter() {
		knobWithValueStringDisplay = nullptr;
		knobWithWaveShapeDisplay = nullptr;
		toggleButton = nullptr;
		comboBox = nullptr;
		sequencerStep = nullptr;
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const noexcept {
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

	void deleteAttachment() const noexcept {
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

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

