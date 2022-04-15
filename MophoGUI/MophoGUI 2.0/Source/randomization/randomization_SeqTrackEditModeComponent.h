#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class SeqTrackEditModeComponent :
	public Component,
	public Button::Listener,
	public ComboBox::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	ToggleButton editAllStepsModeToggle;
	ToggleButton editSelectedStepModeToggle;
	ComboBox stepSelector;

public:
	SeqTrackEditModeComponent() = delete;

	SeqTrackEditModeComponent(int trackNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void buttonClicked(Button* button) override;
	void comboBoxChanged(ComboBox* comboBox) override;
	~SeqTrackEditModeComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackEditModeComponent)
};