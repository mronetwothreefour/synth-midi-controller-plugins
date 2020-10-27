#pragma once

#include <JuceHeader.h>
#include "../widgets_Button//widget_ButtonAndLabelForEditingPgmName.h"



class UnexposedParameters;

class ButtonsLayer :
	public Component
{
	ButtonAndLabelForEditingPgmName button_ForEditingPgmName;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};