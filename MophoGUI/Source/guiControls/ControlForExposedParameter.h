#pragma once

#include <JuceHeader.h>

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

	ControlForExposedParameter();

public:
	~ControlForExposedParameter();
	explicit ControlForExposedParameter(uint8 param);

private:
	void buildKnobWithValueStringDisplayControlForExposedParam(uint8 param);
	void buildKnobWithWaveShapeDisplayControlForExposedParam(uint8 param);
	void buildToggleButtonControlForExposedParam(uint8 param);
	void buildComboBoxControlForExposedParam(uint8 param);
	void buildProgramNameCharacterControlForExposedParam(uint8 param);
	void buildSequencerStepControlForExposedParam(uint8 param);
	int sequencerTrackThisStepIsOn(uint8 param);

public:
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const;
	void deleteAttachment() const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

