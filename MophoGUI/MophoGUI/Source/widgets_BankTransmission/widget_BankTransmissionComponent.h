#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class BankTransmissionComponent :
	public Component,
	private Timer
{
public:
	enum class TransmissionType { push = 0, pull };

private:
	uint8 bank;
	TransmissionType transmissionType;
	UnexposedParameters* unexposedParams;
	String title;
	String message;
	int transmitTime;
	uint8 programCounter;
	double progress;
	ProgressBar progressBar;
	TextButton button_Stop;
	TextButton button_OK;

public:
	BankTransmissionComponent() = delete;

	BankTransmissionComponent(uint8 bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams);

private:
	void timerCallback() override;
	void transmitMidiBufferForProgramSlot(uint8 programSlot);

public:
	void paint(Graphics& g) override;

private:
	void cancelTransmission();
	void makeOKbuttonVisible();
	void hideThisComponent();

public:
	~BankTransmissionComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankTransmissionComponent)
};

