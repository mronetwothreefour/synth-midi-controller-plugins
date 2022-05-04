#pragma once

#include <JuceHeader.h>

#include "randomization_AllowedNotesComponent.h"
#include "randomization_AllowedOctavesComponentForLFOfreq.h"
#include "randomization_AllowedSyncedFreqComponent.h"
#include "randomization_AllowedUnsyncedFreqComponent.h"
#include "randomization_RepeatValuesToggleComponent.h"



class UnexposedParameters;

class RandomizationOptionsComponent_LFOfreq :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton toggle_ForAllowingPitchedFreq;
	AllowedNotesComponent allowedNotes;
	AllowedOctavesComponentForLFOfreq allowedOctaves;
	ToggleButton toggle_ForAllowingUnsyncedFreq;
	AllowedUnsyncedFreqComponent allowedUnsyncedFreq;
	ToggleButton toggle_ForAllowingSyncedFreq;
	AllowedSyncedFreqComponent allowedSyncedFreq;
	RepeatValuesToggleComponent repeatValues;
	TextButton button_ForClosingComponent;
	int background_x;
	int background_y;

public:
	RandomizationOptionsComponent_LFOfreq() = delete;

	RandomizationOptionsComponent_LFOfreq(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_LFOfreq();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_LFOfreq)
};
