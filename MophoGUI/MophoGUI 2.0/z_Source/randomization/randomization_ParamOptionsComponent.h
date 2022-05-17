#pragma once

#include <JuceHeader.h>

#include "randomization_AllowedValuesTogglesComponent.h"
#include "randomization_RepeatValuesToggleComponent.h"



class UnexposedParameters;

class ParamRandomizationOptionsComponent :
	public Component
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_ForAllowingAllValues;
	RepeatValuesToggleComponent repeatValues;
	TextButton button_ForRandomizingParameter;
	TextButton button_ForClosingComponent;
	AllowedValuesTogglesComponent allowedValuesToggles;
	bool childrenShouldBeStackedVertically;
	int background_x;
	int background_y;
	int background_w;
	int background_h;

public:
	ParamRandomizationOptionsComponent() = delete;

	ParamRandomizationOptionsComponent(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationOptionsComponent)
};