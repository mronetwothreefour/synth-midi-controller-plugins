#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class ExposedParameters;
class InfoForExposedParameters;
class ParamRandomizationMethods;
class TooltipsOptions;

class GUI_Layer_AllowedChoices_Binary :
	public Component
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	AllowRepeatChoicesToggle repeatChoicesToggle;
	RandomizeButtonForAllowedChoicesLayers btn_Randomize;
	ButtonForHidingLayer btn_Close;
	const int background_x;
	const int background_y;
	const int background_w{ 110 };
	const int background_h{ 112 };

public:
	GUI_Layer_AllowedChoices_Binary() = delete;

	GUI_Layer_AllowedChoices_Binary(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_Binary)
};
