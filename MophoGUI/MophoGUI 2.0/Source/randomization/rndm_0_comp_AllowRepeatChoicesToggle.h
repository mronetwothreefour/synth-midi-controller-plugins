#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class UnexposedParameters;

class AllowRepeatChoicesToggle :
	public Component,
	public Value::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	Value onlyOneChoiceIsAllowedValue;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle() = delete;

	AllowRepeatChoicesToggle(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void valueChanged(Value& value) override;
	~AllowRepeatChoicesToggle();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle)
};