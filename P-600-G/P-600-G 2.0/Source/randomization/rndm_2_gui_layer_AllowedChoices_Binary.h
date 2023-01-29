#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesSwitch.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class ExposedParameters;
class InfoForExposedParameters;
class ParamRandomizationMethods;
class UnexposedParameters;

class GUI_Layer_AllowedChoices_Binary :
	public Component
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	AllowRepeatChoicesSwitch repeatChoicesSwitch;
	RandomizeButtonForAllowedChoicesLayers btn_Randomize;
	ButtonForHidingLayer btn_Exit;
	const int background_x;
	const int background_y;

public:
	GUI_Layer_AllowedChoices_Binary() = delete;

	GUI_Layer_AllowedChoices_Binary(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_Binary)
};
