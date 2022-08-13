#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;

class Outgoing_MIDI_Buffers;
class UnexposedParameters;

class GUI_Layer_BankTransmit :
	public Component,
	private Timer
{
	VoicesBank bank;
	String bankName;
	BankTransmitType transmitType;
	UnexposedParameters* unexposedParams;
	String progressMessage;
	int transmitTime;
	uint8 voiceCounter;
	double progress;
	ProgressBar progressBar;
	TextButton btn_Stop;
	ButtonForHidingLayer btn_Close;
	const Rectangle<int> buttonBounds{ 611, 344, btn_Close.getWidth(), GUI::redButton_h};

public:
	GUI_Layer_BankTransmit() = delete;

	GUI_Layer_BankTransmit(VoicesBank& bank, BankTransmitType transmitType, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void timerCallback() override;
	void transmitMidiBufferForVoiceSlot(uint8 voiceSlot);
	void cancelTransmission();
	void makeClosebuttonVisible();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_BankTransmit)
};

