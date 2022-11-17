#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "rndm_1_comp_AllowChoiceToggles_PulseWidth.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;
using Shape = OscWaveShape;

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class GUI_Layer_AllowedChoices_OscShape :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	TextButton btn_AllowAll;
	AllowRepeatChoicesToggle repeatChoices;
	ButtonForHidingLayer btn_Close;
	ToggleButton toggle_Off;
	ToggleButton toggle_Saw;
	ToggleButton toggle_Tri;
	ToggleButton toggle_SawTri;
	ToggleButton toggle_Pulse;
	AllowChoiceToggles_PulseWidth allowPulseWidthToggles;
	RandomizeButtonForAllowedChoicesLayers btn_Randomize;
	const int background_x;
	const int background_y;
	const int background_w{ 454 };
	const int background_h{ 301 };
	const int shapeTogglesRow_y;
	const int pulseToggle_y;

public:
	GUI_Layer_AllowedChoices_OscShape() = delete;

	GUI_Layer_AllowedChoices_OscShape(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void makeShapeTheOnlyOneAllowed(Shape shape);
	void allowAllChoices();
	~GUI_Layer_AllowedChoices_OscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_OscShape)
};