#pragma once

#include <JuceHeader.h>

#include "randomization_AllowedNotesComponent.h"
#include "randomization_AllowedOctavesComponentForLPFfreq.h"
#include "randomization_ValueRangeComponentForLPFfreq.h"



class UnexposedParameters;

class RandomizationOptionsComponent_LPFfreq :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton valueRangeModeToggle;
	ToggleButton pitchesModeToggle;
	ValueRangeComponentForLPFfreq valueRange;
	AllowedNotesComponent allowedNotes;
	AllowedOctavesComponentForLPFfreq allowedOctaves;
	TextButton button_ForClosingComponent;

public:
	RandomizationOptionsComponent_LPFfreq() = delete;

	explicit RandomizationOptionsComponent_LPFfreq(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_LPFfreq();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_LPFfreq)
};
