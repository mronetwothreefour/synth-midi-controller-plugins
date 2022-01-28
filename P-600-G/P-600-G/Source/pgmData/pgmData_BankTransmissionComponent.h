#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ProgramBankTransmissionComponent :
	public Component,
	private Timer
{
public:
	enum class TransmissionType { push = 0, pull };

private:
	TransmissionType transmissionType;
	UnexposedParameters* unexposedParams;
	int transmitTime;
	uint8 pgmCounter;
	double progress;
	ProgressBar progressBar;
	TextButton button_Esc;
	TextButton button_OK;

public:
	ProgramBankTransmissionComponent() = delete;

	ProgramBankTransmissionComponent(TransmissionType transmissionType, UnexposedParameters* unexposedParams);

private:
	void timerCallback() override;
	void transmitMidiBufferForProgramSlot(uint8 pgmSlot);

public:
	void paint(Graphics& g) override;

private:
	const char* getTitleLabelImageData();
	size_t getTitleLabelImageDataSize();
	void cancelTransmission();
	void makeOKbuttonVisible();
	void hideThisComponent();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBankTransmissionComponent)
};

