//to do: eliminate this class
#pragma once

#include <JuceHeader.h>

#include "randomization_Constants.h"

using namespace constants;



class UnexposedParameters;

class AllowedOctavesComponentForSeqTrack :
	public Component,
	public Button::Listener,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedOctaveToggles[randomization::numberOfOctavesForLFOfreqAndSeqSteps];
	TextButton button_ForAllowingAllOctaves;

public:
	AllowedOctavesComponentForSeqTrack() = delete;

	AllowedOctavesComponentForSeqTrack(int trackNum, UnexposedParameters* unexposedParams);
	void generateTooltips();
	void resized() override;
	void buttonClicked(Button* button) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~AllowedOctavesComponentForSeqTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedOctavesComponentForSeqTrack)
};