#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedOctavesComponentForLPFfreq :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedOctaveToggles[randomization::numberOfOctavesForLPFfreq];
	TextButton button_ForAllowingAllOctaves;

public:
	AllowedOctavesComponentForLPFfreq() = delete;

	explicit AllowedOctavesComponentForLPFfreq(UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	~AllowedOctavesComponentForLPFfreq();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedOctavesComponentForLPFfreq)
};