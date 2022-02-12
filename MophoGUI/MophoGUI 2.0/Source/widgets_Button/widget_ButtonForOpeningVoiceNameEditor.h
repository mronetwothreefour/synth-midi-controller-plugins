#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ButtonForOpeningVoiceNameEditor : public BaseButtonWithOnClickAndTooltipMethods
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	Label& voiceNameEditor;

public:
	ButtonForOpeningVoiceNameEditor() = delete;

	ButtonForOpeningVoiceNameEditor(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, Label& voiceNameEditor);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	String getVoiceNameFromExposedParemeters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForOpeningVoiceNameEditor)
};

