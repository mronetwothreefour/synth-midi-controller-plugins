#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class RandomizationComponent;
class UnexposedParameters;

class ButtonForUnlockingAllVCAparameters :
	public BaseButtonWithOnClickAndTooltipMethods
{
	RandomizationComponent* randomizationComponent;
	UnexposedParameters* unexposedParams;

public:

	ButtonForUnlockingAllVCAparameters() = delete;

	ButtonForUnlockingAllVCAparameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForUnlockingAllVCAparameters)
};
