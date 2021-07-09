#pragma once

#include <JuceHeader.h>

#include "../widgets_ComboBox/widget_ComboBoxWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_KnobForPitchWithValueStringDisplay.h"
#include "../widgets_Slider/widget_KnobWithValueStringDisplay.h"
#include "../widgets_Slider/widget_KnobWithWaveShapeDisplay.h"
#include "../widgets_Slider/widget_ProgramNameCharWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_SequencerStepWithExposedParamAttacher.h"
#include "../widgets_ToggleButton/widget_ToggleButtonWithWithExposedParamAttacher.h"



class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobForPitchWithValueStringDisplay> knobForPitchWithValueStringDisplay;
	std::unique_ptr<KnobWithWaveShapeDisplay> knobWithWaveShapeDisplay;
	std::unique_ptr<ToggleButtonWithWithExposedParamAttacher> toggleButton;
	std::unique_ptr<ComboBoxWithExposedParamAttacher> comboBox;
	std::unique_ptr<SequencerStepWithExposedParamAttacher> sequencerStep;
	std::unique_ptr<ProgramNameCharWithExposedParamAttacher> pgmNameChar;

	ControlForExposedParameter();

public:
	ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams);

private:
	void buildKnobWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildKnobForPitchWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildKnobWithWaveShapeDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildToggleButtonControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildComboBoxControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildProgramNameCharacterControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildSequencerStepControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	int sequencerTrackThisStepIsOn(uint8 param);

public:
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const;
	void deleteAttachment() const;
	~ControlForExposedParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

