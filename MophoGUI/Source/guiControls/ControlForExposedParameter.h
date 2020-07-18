#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../widgets/widget_Buttons.h"
#include "../widgets/widget_ComboBoxes.h"
#include "../widgets/widget_Knobs.h"
#include "../widgets/widget_SequencerSteps.h"



class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobWithWaveShapeDisplay> knobWithWaveShapeDisplay;
	std::unique_ptr<ToggleButtonWithWithExposedParamAttacher> toggleButton;
	std::unique_ptr<ComboBoxWithExposedParamAttacher> comboBox;
	std::unique_ptr<SeqTrack1StepWithExposedParamAttacher> stepForSeqTrack1;
	std::unique_ptr<SeqTracks2_3_4StepWithExposedParamAttacher> stepForSeqTracks2_3_4;

	ControlForExposedParameter() : 
		controlType{ ControlType::nullControl } 
	{
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
		case ControlType::stepForSeqTrack1:
			stepForSeqTrack1.reset(new SeqTrack1StepWithExposedParamAttacher(param));
			addAndMakeVisible(*stepForSeqTrack1);
			setSize(stepForSeqTrack1->getWidth(), stepForSeqTrack1->getHeight());
			break;
		case ControlType::stepForSeqTracks2_3_4:
			stepForSeqTracks2_3_4.reset(new SeqTracks2_3_4StepWithExposedParamAttacher(param));
			addAndMakeVisible(*stepForSeqTracks2_3_4);
			setSize(stepForSeqTracks2_3_4->getWidth(), stepForSeqTracks2_3_4->getHeight());
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
		stepForSeqTrack1 = nullptr;
		stepForSeqTracks2_3_4 = nullptr;
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
		case ControlType::stepForSeqTrack1:
			if (stepForSeqTrack1 != nullptr)
				stepForSeqTrack1->attachToExposedParameter(exposedParams);
			break;
		case ControlType::stepForSeqTracks2_3_4:
			if (stepForSeqTracks2_3_4 != nullptr)
				stepForSeqTracks2_3_4->attachToExposedParameter(exposedParams);
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
		if (stepForSeqTrack1 != nullptr)
			stepForSeqTrack1->deleteAttachment();
		if (stepForSeqTracks2_3_4 != nullptr)
			stepForSeqTracks2_3_4->deleteAttachment();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

