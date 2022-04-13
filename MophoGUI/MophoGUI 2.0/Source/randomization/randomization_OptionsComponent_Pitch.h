#pragma once

#include <JuceHeader.h>

#include "randomization_AllowedNotesComponent.h"
#include "randomization_AllowedOctavesComponent.h"



class UnexposedParameters;

class RandomizationOptionsComponent_Pitch :
	public Component
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	AllowedNotesComponent allowedNotes;
	AllowedOctavesComponent allowedOctaves;
	TextButton button_ForClosingComponent;
	int background_x;
	int background_y;

public:
	RandomizationOptionsComponent_Pitch() = delete;

	RandomizationOptionsComponent_Pitch(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_Pitch)
};