#pragma once

#include "../widgets_Slider/widget_KnobForPitchWithValueStringDisplay.h"
#include "../widgets_Slider/widget_KnobWithValueStringDisplay.h"



class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobForPitchWithValueStringDisplay> knobForPitchWithValueStringDisplay;

	ControlForExposedParameter();

public:
	ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams);

private:
	void buildKnobWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildKnobForPitchWithValueStringDisplayControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);

public:
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const;
	void deleteAttachment() const;
	~ControlForExposedParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};