#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class FailedLinkComponent :
	public Component,
	private Timer
{
	UnexposedParameters* unexposedParams;
	TextButton button_ForClosingFailedLinkComponent;
	TextButton button_ForSendingGlobalParametersDumpRequest;

public:
	FailedLinkComponent() = delete;

	explicit FailedLinkComponent(UnexposedParameters* unexposedParams);

private:
	void sendRequestForGlobalParametersDump();
	void checkSysExLink();
	void hideThisComponent();

public:
	void paint(Graphics& g) override;
	void resized() override;

private:
	void timerCallback() override;

public:
	~FailedLinkComponent() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FailedLinkComponent)
};

