#pragma once

#include <JuceHeader.h>

class UnexposedParameters;

class SplitSlotRadioButton :
	public ToggleButton,
	public Value::Listener
{
	const uint8 slotNum;
	const String slotNumString;
	UnexposedParameters* unexposedParams;
	Value splitNameAsValue;

	SplitSlotRadioButton();

public:
	SplitSlotRadioButton(const uint8 slotNum, UnexposedParameters* unexposedParams);
	void valueChanged(Value& value) override;
	~SplitSlotRadioButton();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitSlotRadioButton)
};