#pragma once

#include <JuceHeader.h>



class TabbedComponentForFactoryProgramBanks;
class UnexposedParameters;

class BankTransmissionComponent :
	public Component,
	private Timer
{
public:
	enum class TransmissionType { push = 0, pull };

private:
	TabbedComponentForFactoryProgramBanks& tabbedComponent;
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
	TextButton button_Close;

public:
	BankTransmissionComponent() = delete;

	BankTransmissionComponent(TabbedComponentForFactoryProgramBanks& tabbedComponent, TransmissionType transmissionType, UnexposedParameters* unexposedParams);

private:
	void timerCallback() override;
	void transmitMidiBufferForProgramSlot(uint8 programSlot);

public:
	void paint(Graphics& g) override;

private:
	const char* getTitleLabelImageData();
	size_t getTitleLabelImageDataSize();
	void cancelTransmission();
	void makeClosebuttonVisible();
	void hideThisComponent();

public:
	~BankTransmissionComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BankTransmissionComponent)
};

