#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedNotesComponent :
	public Component,
	public Button::Listener,
	public ValueTree::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedNoteToggles[randomization::numberOfNotes];
	TextButton button_ForAllowingAllNotes;

public:
	AllowedNotesComponent() = delete;

	AllowedNotesComponent(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void turnOffAllToggles();
	void restoreAllToggles();
	void buttonClicked(Button* button) override;
	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) override;
	~AllowedNotesComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedNotesComponent)
};