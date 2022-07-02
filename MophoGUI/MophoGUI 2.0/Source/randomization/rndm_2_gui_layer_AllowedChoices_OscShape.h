#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "rndm_1_comp_AllowChoiceToggles_PulseWidth.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;
using Shape = OscWaveShape;



class InfoForExposedParameters;
class ParamRandomizationMethods;
class RandomizationOptions;
class UnexposedParameters;

class GUI_Layer_AllowedChoices_OscShape :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	RandomizationOptions* randomization;
	TextButton button_AllowAll;
	AllowRepeatChoicesToggle repeatChoices;
	ButtonForHidingLayer button_Close;
	ToggleButton toggle_Off;
	ToggleButton toggle_Saw;
	ToggleButton toggle_Tri;
	ToggleButton toggle_SawTri;
	ToggleButton toggle_Pulse;
	AllowChoiceToggles_PulseWidth allowPulseWidthToggles;
	RandomizeButtonForAllowedChoicesLayers button_Randomize;
	const int background_x;
	const int background_y;
	const int background_w{ 454 };
	const int background_h{ 301 };

public:
	GUI_Layer_AllowedChoices_OscShape() = delete;

	GUI_Layer_AllowedChoices_OscShape(uint8 paramIndex, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void buttonClicked(Button* button) override;
	void makeShapeTheOnlyOneAllowed(Shape shape);
	void allowAllChoices();
	~GUI_Layer_AllowedChoices_OscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_OscShape)
};