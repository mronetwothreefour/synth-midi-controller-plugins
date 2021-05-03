#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class HardwareSettingsWarningComponent :
	public Component,
	private Timer
{
protected:
	UnexposedParameters* unexposedParams;
	TextButton button_ForClosingComponent;
	TextButton button_ForSendingGlobalParametersDumpRequest;

public:
	HardwareSettingsWarningComponent() = delete;

	explicit HardwareSettingsWarningComponent(UnexposedParameters* unexposedParams);

protected:
	void addButtonsToComponent();

private:
	void sendRequestForGlobalParametersDump();

protected:
	virtual void checkHardwareSettings() = 0;
	void hideThisComponent();

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HardwareSettingsWarningComponent)
};

