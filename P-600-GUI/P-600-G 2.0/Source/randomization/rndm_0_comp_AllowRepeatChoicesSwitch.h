#pragma once

#include <JuceHeader.h>

#include "..\gui\gui_comp_JuceSlidersWithMouseMods.h"

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowRepeatChoicesSwitch :
	public Component,
	public Value::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	Value onlyOneChoiceIsAllowedForParamAsValue;
	LinearSliderWithMouseWheelMoveOverride switch_AllowRepeatChoices;

public:
	AllowRepeatChoicesSwitch() = delete;

	AllowRepeatChoicesSwitch(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void valueChanged(Value& value) override;
	~AllowRepeatChoicesSwitch();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesSwitch)
};