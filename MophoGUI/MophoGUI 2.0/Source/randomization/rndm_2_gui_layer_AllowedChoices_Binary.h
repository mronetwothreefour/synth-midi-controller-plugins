#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class ParamRandomizationMethods;
class UnexposedParameters;

class GUI_Layer_AllowedChoices_Binary :
	public Component
{
	uint8 paramIndex;
	AllowRepeatChoicesToggle repeatChoicesToggle;
	RandomizeButtonForAllowedChoicesLayers button_Randomize;
	ButtonForHidingLayer button_Close;
	const int background_x;
	const int background_y;
	const int background_w{ 110 };
	const int background_h{ 112 };

public:
	GUI_Layer_AllowedChoices_Binary() = delete;

	GUI_Layer_AllowedChoices_Binary(uint8 paramIndex, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_Binary)
};
