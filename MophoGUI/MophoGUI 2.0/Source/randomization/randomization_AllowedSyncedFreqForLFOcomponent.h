#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedSyncedFreqForLFOcomponent :
	public Component,
	public Button::Listener
{
	int lfoNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedSyncedFreqToggles[randomization::numberOfSyncedFreqForLFOs];
	TextButton button_ForAllowingAllSyncedFreq;

public:
	AllowedSyncedFreqForLFOcomponent() = delete;

	AllowedSyncedFreqForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	~AllowedSyncedFreqForLFOcomponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedSyncedFreqForLFOcomponent)
};