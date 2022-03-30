#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedOctavesForLFOcomponent :
	public Component,
	public Button::Listener
{
	int lfoNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedOctaveToggles[randomization::numberOfOctavesForLFOsAndSeqSteps];
	TextButton button_ForAllowingAllOctaves;

public:
	AllowedOctavesForLFOcomponent() = delete;

	AllowedOctavesForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	~AllowedOctavesForLFOcomponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedOctavesForLFOcomponent)
};