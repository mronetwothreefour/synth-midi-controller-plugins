#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForSendingEditBufferDataMessage : public BaseButtonWithOnClickAndTooltipMethods
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	ButtonForSendingEditBufferDataMessage() = delete;

	ButtonForSendingEditBufferDataMessage(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingEditBufferDataMessage)
};

