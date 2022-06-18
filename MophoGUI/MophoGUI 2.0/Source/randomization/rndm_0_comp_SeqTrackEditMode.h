#pragma once

#include <JuceHeader.h>
#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class RandomizationOptions;
class UnexposedParameters;

class SeqTrackEditMode :
	public Component,
	public Button::Listener,
	public ComboBox::Listener
{
	Track track;
	RandomizationOptions* randomizationOptions;
	ToggleButton toggle_AllStepsMode;
	ToggleButton toggle_SelectedStepMode;
	ComboBox stepSelector;

public:
	SeqTrackEditMode() = delete;

	SeqTrackEditMode(Track track, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void buttonClicked(Button* button) override;
	void comboBoxChanged(ComboBox* comboBox) override;
	~SeqTrackEditMode();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackEditMode)
};