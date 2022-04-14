#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedSyncedFreqComponent :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedSyncedFreqToggles[randomization::numberOfSyncedFreqForLFOs];
	TextButton button_ForAllowingAllSyncedFreq;

public:
	AllowedSyncedFreqComponent() = delete;

	AllowedSyncedFreqComponent(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	~AllowedSyncedFreqComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedSyncedFreqComponent)
};