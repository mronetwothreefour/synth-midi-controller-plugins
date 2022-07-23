#pragma once

#include <JuceHeader.h>
#include "../constants/constants_Enum.h"

using namespace MophoConstants;

class UnexposedParameters;

class VoiceSlotRadioButton :
	public ToggleButton,
	public Value::Listener
{
	const VoicesBank bank;
	const uint8 slotNum;
	const String slotNumString;
	UnexposedParameters* unexposedParams;
	Value voiceNameValue;

	VoiceSlotRadioButton();

public:
	VoiceSlotRadioButton(const VoicesBank bank, const uint8 slotNum, UnexposedParameters* unexposedParams);
	void valueChanged(Value& value) override;
	~VoiceSlotRadioButton();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlotRadioButton)
};