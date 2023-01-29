#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"

using namespace P_600_G_Constants;

class UnexposedParameters;

class GUI_Layer_VoicesBankTransmit :
	public Component,
	private Timer
{
	BankTransmitType transmitType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 voiceCounter;
	double progress;
	ProgressBar progressBar;
	TextButton btn_Esc;
	TextButton btn_OK;
	const Rectangle<int> buttonBounds{ 681, 207, GUI::buttons_w, GUI::buttons_h };

public:
	GUI_Layer_VoicesBankTransmit() = delete;

	GUI_Layer_VoicesBankTransmit(BankTransmitType transmitType, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void timerCallback() override;
	void transmitMidiBufferForVoiceSlot(uint8 voiceSlot);
	void cancelTransmission();
	void make_OK_ButtonVisible();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_VoicesBankTransmit)
};

