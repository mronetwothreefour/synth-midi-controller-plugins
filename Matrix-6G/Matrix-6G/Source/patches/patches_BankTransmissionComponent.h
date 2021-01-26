#pragma once

#include <JuceHeader.h>

#include "../patches/patches_PatchBanks.h"



class TabbedComponentForPatchBanks;
class UnexposedParameters;

class BankTransmissionComponent :
	public Component,
	private Timer
{
public:
	enum class TransmissionType { push = 0, pull };

private:
	PatchBank bank;
	TransmissionType transmissionType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 patchCounter;
	double progress;
	ProgressBar progressBar;
	TextButton button_Stop;
	TextButton button_Close;

public:
	BankTransmissionComponent() = delete;

	BankTransmissionComponent(PatchBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams);

private:
	void timerCallback() override;
	void transmitMidiBufferForPatchSlot(uint8 patchSlot);

public:
	void paint(Graphics& g) override;

private:
	const char* getTitleLabelImageData();
	size_t getTitleLabelImageDataSize();
	void cancelTransmission();
	void makeClosebuttonVisible();
	void hideThisComponent();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankTransmissionComponent)
};

