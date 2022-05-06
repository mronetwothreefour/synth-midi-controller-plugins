#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedNotesAndBentNotesComponent :
	public Component,
	public Button::Listener,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedNoteToggles[randomization::numberOfNotesAndBentNotes];
	TextButton button_ForAllowingAllNotes;
	TextButton button_ForAllowingAllBentNotes;

public:
	AllowedNotesAndBentNotesComponent() = delete;

	AllowedNotesAndBentNotesComponent(int trackNum, UnexposedParameters* unexposedParams);
	void generateTooltips();
	void resized() override;
	void turnOffAllToggles();
	void buttonClicked(Button* button) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~AllowedNotesAndBentNotesComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedNotesAndBentNotesComponent)
};