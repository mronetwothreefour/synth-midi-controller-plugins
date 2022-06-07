#pragma once

#include <JuceHeader.h>

#include "0_rndm_comp_AllowRepeatChoicesToggle.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;



class UnexposedParameters;

class GUI_Layer_AllowedChoices_OscShape :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_AllowAll;
	AllowRepeatChoicesToggle repeatValues;
	ButtonForHidingLayer button_Close;
	ToggleButton toggle_Off;
	ToggleButton toggle_Saw;
	ToggleButton toggle_Tri;
	ToggleButton toggle_SawTri;
	ToggleButton toggle_Pulse;
	static const int numberOfPulseWidths { 100 };
	ToggleButton allowPulseWidthToggles[numberOfPulseWidths];
	TextButton button_Randomize;
	const int numberOfRows { 10 };
	const int pulseWidthToggle_w{ 42 };
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
	void makeShapeTheOnlyOneAllowed(OscWaveShape shape);
	void allowAllShapes();
	void disablePulseWidthToggles();
	void restorePulseWidthToggles();
	~GUI_Layer_AllowedChoices_OscShape();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_OscShape)
};