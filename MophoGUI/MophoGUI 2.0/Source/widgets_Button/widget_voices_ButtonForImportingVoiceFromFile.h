#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"
#include "../voices/voices_VoicesBanks.h"



class UnexposedParameters;

class ButtonForImportingVoiceFromFile :
	public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:

	ButtonForImportingVoiceFromFile() = delete;

	ButtonForImportingVoiceFromFile(VoicesBank bank, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForImportingVoiceFromFile)
};
