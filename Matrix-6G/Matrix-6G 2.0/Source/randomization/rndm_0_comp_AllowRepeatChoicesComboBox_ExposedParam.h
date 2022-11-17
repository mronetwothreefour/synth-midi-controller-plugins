#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class ParamRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowRepeatChoicesComboBox_ExposedParam :
	public Component,
	public Value::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ParamRandomizationOptions* randomization;
	Value onlyOneChoiceIsAllowedForParamAsValue;
	ComboBox comboBox_AllowRepeatChoices;

public:
	AllowRepeatChoicesComboBox_ExposedParam() = delete;

	AllowRepeatChoicesComboBox_ExposedParam(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void valueChanged(Value& value) override;
	~AllowRepeatChoicesComboBox_ExposedParam();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesComboBox_ExposedParam)
};