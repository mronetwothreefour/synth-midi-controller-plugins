#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedOctavesForOscComponent :
	public Component,
	public Button::Listener
{
	int oscNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedOctaveToggles[randomization::numberOfOctavesForOscillators];
	TextButton button_ForAllowingAllOctaves;

public:
	AllowedOctavesForOscComponent() = delete;

	AllowedOctavesForOscComponent(int oscNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void buttonClicked(Button* button) override;
	~AllowedOctavesForOscComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedOctavesForOscComponent)
};