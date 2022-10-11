#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class Outgoing_MIDI_Buffers;
class UnexposedParameters;

class GUI_Layer_SplitsBankTransmit :
	public Component,
	private Timer
{
	BankTransmitType transmitType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 splitCounter;
	double progress;
	ProgressBar progressBar;
	TextButton btn_Stop;
	TextButton btn_Close;

public:
	GUI_Layer_SplitsBankTransmit() = delete;

	GUI_Layer_SplitsBankTransmit(BankTransmitType transmitType, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void timerCallback() override;
	void transmitMidiBufferForSplitSlot(uint8 splitSlot);
	void cancelTransmission();
	void makeCloseButtonVisible();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_SplitsBankTransmit)
};

