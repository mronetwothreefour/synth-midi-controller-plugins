#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class OscillatorRandomizationOptionsComponent :
	public Component,
	public Button::Listener
{
	UnexposedParameters* unexposedParams;
	ToggleButton allowNoteToggleButtons[randomization::numberOfNotes];
	ToggleButton allowOctaveToggleButtons[randomization::numberOfOctavesForOscillators];
	TextButton button_ForClosingOscOptionsComponent;

public:
	OscillatorRandomizationOptionsComponent() = delete;

	explicit OscillatorRandomizationOptionsComponent(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void hideThisComponent();
	~OscillatorRandomizationOptionsComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorRandomizationOptionsComponent)
};
