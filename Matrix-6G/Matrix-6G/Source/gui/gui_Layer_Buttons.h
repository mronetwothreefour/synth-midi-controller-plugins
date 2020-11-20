#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForActivatingQuickPatchEdit.h"
#include "../widgets_Button/widget_ButtonForSendingAllPatchData.h"



class UnexposedParameters;

class ButtonsLayer :
	public Component
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForActivatingQuickPatchEdit button_ForActivatingQuickPatchEdit;
	ButtonForSendingAllPatchData button_ForSendingAllPatchData;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void resized() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};