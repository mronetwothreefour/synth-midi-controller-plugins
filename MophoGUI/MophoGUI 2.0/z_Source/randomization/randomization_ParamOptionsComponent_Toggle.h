#pragma once

#include <JuceHeader.h>

#include "randomization_RepeatValuesToggleComponent.h"



class UnexposedParameters;

class ParamRandomizationOptionsComponent_Toggle :
	public Component
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	RepeatValuesToggleComponent repeatValues;
	TextButton button_ForRandomizingParameter;
	TextButton button_ForClosingComponent;
	int background_x;
	int background_y;
	int background_w;
	int background_h;

public:
	ParamRandomizationOptionsComponent_Toggle() = delete;

	ParamRandomizationOptionsComponent_Toggle(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationOptionsComponent_Toggle)
};