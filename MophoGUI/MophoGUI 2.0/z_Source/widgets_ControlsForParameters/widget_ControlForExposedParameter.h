#pragma once

#include <JuceHeader.h>

#include "../widgets_ComboBox/widget_ComboBoxWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_KnobForPitchWithValueStringDisplay.h"
#include "../widgets_Slider/widget_KnobWithValueStringDisplay.h"
#include "../widgets_Slider/widget_KnobWithWaveShapeDisplay.h"
#include "../widgets_Slider/widget_VoiceNameCharWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_SequencerStepWithExposedParamAttacher.h"
#include "../widgets_ToggleButton/widget_ToggleButtonWithWithExposedParamAttacher.h"



class UnexposedParameters;

class ControlForExposedParameter : public Component
{
	uint8 param;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobForPitchWithValueStringDisplay> knobForPitchWithValueStringDisplay;
	std::unique_ptr<KnobWithWaveShapeDisplay> knobWithWaveShapeDisplay;
	std::unique_ptr<ToggleButtonWithWithExposedParamAttacher> toggleButton;
	std::unique_ptr<ComboBoxWithExposedParamAttacher> comboBox;
	std::unique_ptr<SequencerStepWithExposedParamAttacher> sequencerStep;
	std::unique_ptr<VoiceNameCharWithExposedParamAttacher> voiceNameChar;

	ControlForExposedParameter();

public:
	ControlForExposedParameter(uint8 param, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void buildKnobWithValueStringDisplayControlForExposedParam();
	void buildKnobForPitchWithValueStringDisplayControlForExposedParam();
	void buildKnobWithWaveShapeDisplayControlForExposedParam();
	void buildToggleButtonControlForExposedParam();
	void buildComboBoxControlForExposedParam();
	void buildVoiceNameCharacterControlForExposedParam();
	void buildSequencerStepControlForExposedParam();
	int sequencerTrackThisStepIsOn();

public:
	void attachToExposedParameter() const;
	void mouseDown(const MouseEvent& event) override;
	void deleteAttachment() const;
	~ControlForExposedParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

