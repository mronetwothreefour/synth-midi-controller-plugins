#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class RandomizationComponent;
class UnexposedParameters;

class ButtonForLockingAllStepsInSeqTrack :
	public BaseButtonWithOnClickAndTooltipMethods
{
	int trackNum;
	RandomizationComponent* randomizationComponent;
	UnexposedParameters* unexposedParams;

public:

	ButtonForLockingAllStepsInSeqTrack() = delete;

	ButtonForLockingAllStepsInSeqTrack(int trackNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLockingAllStepsInSeqTrack)
};
