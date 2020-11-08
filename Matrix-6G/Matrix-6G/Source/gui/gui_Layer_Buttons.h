#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForActivatingQuickPatchEdit.h"



class UnexposedParameters;

class ButtonsLayer :
	public Component
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForActivatingQuickPatchEdit button_ForActivatingQuickPatchEdit;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};