#pragma once

#include <JuceHeader.h>

#include "randomization_AllowedNotesForLFOcomponent.h"
#include "randomization_AllowedOctavesForLFOcomponent.h"
#include "randomization_AllowedSyncedFreqForLFOcomponent.h"
#include "randomization_AllowedUnsyncedFreqForLFOcomponent.h"



class UnexposedParameters;

class LFOfreqRandomizationOptionsComponent :
	public Component,
	public Button::Listener
{
	int lfoNum;
	UnexposedParameters* unexposedParams;
	ToggleButton toggle_ForAllowingPitchedFreq;
	AllowedNotesForLFOcomponent allowedNotes;
	AllowedOctavesForLFOcomponent allowedOctaves;
	ToggleButton toggle_ForAllowingUnsyncedFreq;
	AllowedUnsyncedFreqForLFOcomponent allowedUnsyncedFreq;
	ToggleButton toggle_ForAllowingSyncedFreq;
	AllowedSyncedFreqForLFOcomponent allowedSyncedFreq;
	TextButton button_ForClosingLFOfreqOptionsComponent;

public:
	LFOfreqRandomizationOptionsComponent() = delete;

	LFOfreqRandomizationOptionsComponent(int lfoNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void hideThisComponent();
	~LFOfreqRandomizationOptionsComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LFOfreqRandomizationOptionsComponent)
};
