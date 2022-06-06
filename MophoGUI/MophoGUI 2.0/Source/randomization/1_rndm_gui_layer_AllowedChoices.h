#pragma once

#include <JuceHeader.h>

#include "0_rndm_comp_AllowChoiceToggles.h"
#include "0_rndm_comp_AllowRepeatChoicesToggle.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class UnexposedParameters;

class GUI_Layer_AllowedChoices :
	public Component
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_AllowAll;
	AllowRepeatChoicesToggle repeatChoicesToggle;
	ButtonForHidingLayer button_Close;
	AllowChoiceToggles allowChoiceToggles;
	TextButton button_Randomize;
	bool childrenShouldBeStackedVertically;
	int background_x;
	int background_y;
	int background_w;
	int background_h;

public:
	GUI_Layer_AllowedChoices() = delete;

	GUI_Layer_AllowedChoices(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices)
};