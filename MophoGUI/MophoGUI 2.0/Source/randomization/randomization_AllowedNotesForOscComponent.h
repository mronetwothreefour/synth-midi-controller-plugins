#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedNotesForOscComponent :
	public Component,
	public Button::Listener
{
	int oscNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedNoteToggleButtons[randomization::numberOfNotes];

public:
	AllowedNotesForOscComponent() = delete;

	AllowedNotesForOscComponent(int oscNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void buttonClicked(Button* button) override;
	~AllowedNotesForOscComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedNotesForOscComponent)
};