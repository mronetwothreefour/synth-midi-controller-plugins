#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedOctavesComponentForLFOfreq :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedOctaveToggles[randomization::numberOfOctavesForLFOfreqAndSeqSteps];
	TextButton button_ForAllowingAllOctaves;

public:
	AllowedOctavesComponentForLFOfreq() = delete;

	AllowedOctavesComponentForLFOfreq(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	~AllowedOctavesComponentForLFOfreq();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedOctavesComponentForLFOfreq)
};