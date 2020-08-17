#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForSendingProgramEditBufferDump : public BaseButtonWithOnClickAndTooltipMethods
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	ButtonForSendingProgramEditBufferDump() = delete;

	ButtonForSendingProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	~ButtonForSendingProgramEditBufferDump() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDump)
};

