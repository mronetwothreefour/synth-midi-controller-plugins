#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class Outgoing_MIDI_Buffers;
class UnexposedParameters;

class GUI_Layer_VoiceBankTransmit :
	public Component,
	private Timer
{
	VoicesBank bank;
	BankTransmitType transmitType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 voiceCounter;
	double progress;
	ProgressBar progressBar;
	TextButton btn_Stop;
	TextButton btn_Close;

public:
	GUI_Layer_VoiceBankTransmit() = delete;

	GUI_Layer_VoiceBankTransmit(VoicesBank& bank, BankTransmitType transmitType, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void timerCallback() override;
	void transmitMidiBufferForVoiceSlot(uint8 voiceSlot);
	void cancelTransmission();
	void makeCloseButtonVisible();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_VoiceBankTransmit)
};

