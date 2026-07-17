#pragma once

#include <JuceHeader.h>

class UnexposedParameters;

class VoiceSlotRadioButton :
	public ToggleButton,
	public Value::Listener
{
	const uint8 slotNum;
	const String slotNumString;
	UnexposedParameters* unexposedParams;
	Value voiceDataAsValue;

	VoiceSlotRadioButton();

public:
	VoiceSlotRadioButton(const uint8 slotNum, UnexposedParameters* unexposedParams);
	void valueChanged(Value& value) override;
	~VoiceSlotRadioButton();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlotRadioButton)
};