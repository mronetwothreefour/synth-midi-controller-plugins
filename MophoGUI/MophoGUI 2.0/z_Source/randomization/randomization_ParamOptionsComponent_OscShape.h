#pragma once

#include <JuceHeader.h>

#include "randomization_RepeatValuesToggleComponent.h"



class UnexposedParameters;

class ParamRandomizationOptionsComponent_OscShape :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_ForAllowingAllShapes;
	RepeatValuesToggleComponent repeatValues;
	TextButton button_ForRandomizingParameter;
	TextButton button_ForClosingComponent;
	ToggleButton toggle_ForAllowingOff;
	ToggleButton toggle_ForAllowingSawtooth;
	ToggleButton toggle_ForAllowingTriangle;
	ToggleButton toggle_ForAllowingSawTriMix;
	ToggleButton toggle_ForAllowingPulse;
	ToggleButton allowedPulseWidthsToggles[100];
	int pulseWidthToggleWidth;
	int numberOfPulseWidthToggleColumns;
	int numberOfPulseWidthToggleRows;
	int background_x;
	int background_y;
	int background_w;
	int background_h;

public:
	ParamRandomizationOptionsComponent_OscShape() = delete;

	ParamRandomizationOptionsComponent_OscShape(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void allowAllShapes();
	void turnOffAllPulseWidthToggles();
	void restorePulseWidthToggles();
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationOptionsComponent_OscShape)
};