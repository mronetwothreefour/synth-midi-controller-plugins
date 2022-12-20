#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesSwitch.h"
#include "rndm_0_comp_AllowChoiceToggles.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class ExposedParameters;
class InfoForExposedParameters;
class ParamRandomizationMethods;
class TooltipsOptions;

class GUI_Layer_AllowedChoices_OscPitch :
	public Component
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	AllowRepeatChoicesSwitch repeatChoicesSwitch;
	ButtonForHidingLayer btn_Exit;
	AllowChoiceToggles allowChoiceToggles;
	TextButton btn_AllowAll;
	RandomizeButtonForAllowedChoicesLayers btn_Randomize;
	const int background_x;
	const int background_y;
	const int background_w{ 160 };
	const int background_h{ 330 };

public:
	GUI_Layer_AllowedChoices_OscPitch() = delete;

	GUI_Layer_AllowedChoices_OscPitch(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_OscPitch)
};
