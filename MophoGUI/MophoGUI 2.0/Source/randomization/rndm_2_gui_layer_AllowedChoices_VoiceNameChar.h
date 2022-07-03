#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "rndm_1_comp_AllowChoiceToggles_VoiceNameChar.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class ExposedParameters;
class ParamRandomizationMethods;
class UnexposedParameters;

class GUI_Layer_AllowedChoices_VoiceNameChar :
	public Component
{
	uint8 paramIndex;
	ExposedParameters* exposedParams;
	TextButton button_AllowAll;
	AllowRepeatChoicesToggle repeatChoicesToggle;
	ButtonForHidingLayer button_Close;
	AllowChoiceToggles_VoiceNameChar allowChoiceToggles;
	RandomizeButtonForAllowedChoicesLayers button_Randomize;
	const int background_x;
	const int background_y;
	const int background_w;
	const int background_h;

public:
	GUI_Layer_AllowedChoices_VoiceNameChar() = delete;

	GUI_Layer_AllowedChoices_VoiceNameChar(uint8 paramIndex, ExposedParameters* exposedParams, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_VoiceNameChar)
};