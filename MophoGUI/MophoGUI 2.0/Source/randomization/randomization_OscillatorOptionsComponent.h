//to do: eliminate this class
#pragma once

#include <JuceHeader.h>

#include "randomization_AllowedNotesForOscComponent.h"
#include "randomization_AllowedOctavesForOscComponent.h"



class UnexposedParameters;

class OscillatorRandomizationOptionsComponent :
	public Component
{
	AllowedNotesForOscComponent allowedNotesForOsc1;
	AllowedOctavesForOscComponent allowedOctavesForOsc1;
	AllowedNotesForOscComponent allowedNotesForOsc2;
	AllowedOctavesForOscComponent allowedOctavesForOsc2;
	TextButton button_ForClosingOscOptionsComponent;

public:
	OscillatorRandomizationOptionsComponent() = delete;

	explicit OscillatorRandomizationOptionsComponent(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorRandomizationOptionsComponent)
};
