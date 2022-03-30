#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedNotesForLFOcomponent :
	public Component,
	public Button::Listener
{
	int lfoNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedNoteToggles[randomization::numberOfNotes];
	TextButton button_ForAllowingAllNotes;

public:
	AllowedNotesForLFOcomponent() = delete;

	AllowedNotesForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	~AllowedNotesForLFOcomponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedNotesForLFOcomponent)
};