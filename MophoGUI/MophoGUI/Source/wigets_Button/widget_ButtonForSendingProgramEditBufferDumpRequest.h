#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForSendingProgramEditBufferDumpRequest : public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForSendingProgramEditBufferDumpRequest() = delete;

	explicit ButtonForSendingProgramEditBufferDumpRequest(UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	~ButtonForSendingProgramEditBufferDumpRequest() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDumpRequest)
};
