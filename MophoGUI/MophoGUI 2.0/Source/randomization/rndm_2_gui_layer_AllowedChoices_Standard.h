#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "rndm_1_comp_AllowChoiceToggles_Standard.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class UnexposedParameters;

class GUI_Layer_AllowedChoices_Standard :
	public Component
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	TextButton button_AllowAll;
	AllowRepeatChoicesToggle repeatChoicesToggle;
	ButtonForHidingLayer button_Close;
	AllowChoiceToggles_Standard allowChoiceToggles;
	RandomizeButtonForAllowedChoicesLayers button_Randomize;
	bool childrenShouldBeStackedVertically;
	const int background_x;
	const int background_y;
	int background_w;
	int background_h;

public:
	GUI_Layer_AllowedChoices_Standard() = delete;

	GUI_Layer_AllowedChoices_Standard(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_Standard)
};