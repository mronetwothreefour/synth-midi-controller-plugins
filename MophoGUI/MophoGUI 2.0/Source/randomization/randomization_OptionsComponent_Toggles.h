#pragma once

#include <JuceHeader.h>

#include "randomization_RepeatValuesToggleComponent.h"



class RandomizationOptionsComponent_Toggles :
	public Component
{
	uint8 paramIndex;
	RepeatValuesToggleComponent repeatValues;
	TextButton button_ForClosingComponent;
	int background_x;
	int background_y;

public:
	RandomizationOptionsComponent_Toggles() = delete;

	RandomizationOptionsComponent_Toggles(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_Toggles)
};