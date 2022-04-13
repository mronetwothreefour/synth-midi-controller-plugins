#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedOctavesComponent :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedOctaveToggles[randomization::numberOfOctaves];
	TextButton button_ForAllowingAllOctaves;

public:
	AllowedOctavesComponent() = delete;

	AllowedOctavesComponent(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void buttonClicked(Button* button) override;
	~AllowedOctavesComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedOctavesComponent)
};