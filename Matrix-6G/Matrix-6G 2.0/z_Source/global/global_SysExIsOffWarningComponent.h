#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class SysExIsOffWarningComponent :
	public Component,
	private Timer
{
	UnexposedParameters* unexposedParams;
	TextButton button_ForClosingComponent;
	TextButton button_ForSendingGlobalOptionsDataRequest;

public:
	SysExIsOffWarningComponent() = delete;

	explicit SysExIsOffWarningComponent(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	void sendRequestForGlobalOptionsData();
	void checkHardwareSettings();
	void hideThisComponent();
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SysExIsOffWarningComponent)
};

