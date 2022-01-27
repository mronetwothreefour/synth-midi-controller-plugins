#pragma once

#include <JuceHeader.h>

#include "../splits/splits_SplitsBank.h"



class UnexposedParameters;

class SplitsBankTransmissionComponent :
	public Component,
	private Timer
{
public:
	enum class TransmissionType { push = 0, pull };

private:
	TransmissionType transmissionType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 splitCounter;
	double progress;
	ProgressBar progressBar;
	TextButton button_Stop;
	TextButton button_Close;

public:
	SplitsBankTransmissionComponent() = delete;

	SplitsBankTransmissionComponent(TransmissionType transmissionType, UnexposedParameters* unexposedParams);

private:
	void timerCallback() override;
	void transmitMidiBufferForSplitSlot(uint8 splitSlot);

public:
	void paint(Graphics& g) override;

private:
	const char* getTitleLabelImageData();
	size_t getTitleLabelImageDataSize();
	void cancelTransmission();
	void makeCloseButtonVisible();
	void hideThisComponent();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsBankTransmissionComponent)
};

