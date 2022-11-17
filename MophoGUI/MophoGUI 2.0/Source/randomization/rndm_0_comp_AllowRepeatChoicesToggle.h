#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowRepeatChoicesToggle :
	public Component,
	public Value::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	Value onlyOneChoiceIsAllowedForParamAsValue;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle() = delete;

	AllowRepeatChoicesToggle(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void valueChanged(Value& value) override;
	~AllowRepeatChoicesToggle();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle)
};