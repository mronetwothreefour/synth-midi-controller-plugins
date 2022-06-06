#pragma once

#include <JuceHeader.h>

#include "0_rndm_comp_AllowRepeatChoicesToggle.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class UnexposedParameters;

class GUI_Layer_AllowedChoices_OscShape :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_ForAllowingAllShapes;
	AllowRepeatChoicesToggle repeatValues;
	ButtonForHidingLayer button_Close;
	ToggleButton toggle_ForAllowingOff;
	ToggleButton toggle_ForAllowingSawtooth;
	ToggleButton toggle_ForAllowingTriangle;
	ToggleButton toggle_ForAllowingSawTriMix;
	ToggleButton toggle_ForAllowingPulse;
	ToggleButton allowedPulseWidthsToggles[100];
	TextButton button_ForRandomizingParameter;
	const int pulseWidthToggleWidth{ 42 };
	const int numberOfPulseWidthToggleColumns{ 10 };
	const int numberOfPulseWidthToggleRows{ 10 };
	int background_x;
	int background_y;
	const int background_w{ 454 };
	const int background_h{ 301 };

public:
	GUI_Layer_AllowedChoices_OscShape() = delete;

	GUI_Layer_AllowedChoices_OscShape(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void allowAllShapes();
	void disablePulseWidthToggles();
	void restorePulseWidthToggles();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_OscShape)
};