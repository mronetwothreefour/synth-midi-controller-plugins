#pragma once

#include <JuceHeader.h>

#include "../voices/voices_VoicesBanks.h"



class TabbedComponentForVoicesBanks;
class UnexposedParameters;

class VoicesBankTransmissionComponent :
	public Component,
	private Timer
{
public:
	enum class TransmissionType { push = 0, pull };

private:
	VoicesBank bank;
	TransmissionType transmissionType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 voiceCounter;
	double progress;
	ProgressBar progressBar;
	TextButton button_Stop;
	TextButton button_Close;

public:
	VoicesBankTransmissionComponent() = delete;

	VoicesBankTransmissionComponent(VoicesBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams);

private:
	void timerCallback() override;
	void transmitMidiBufferForVoiceSlot(uint8 voiceSlot);

public:
	void paint(Graphics& g) override;

private:
	const char* getTitleLabelImageData();
	size_t getTitleLabelImageDataSize();
	void cancelTransmission();
	void makeCloseButtonVisible();
	void hideThisComponent();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBankTransmissionComponent)
};

