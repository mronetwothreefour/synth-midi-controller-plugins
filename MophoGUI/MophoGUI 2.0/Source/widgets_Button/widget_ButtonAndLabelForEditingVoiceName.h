#pragma once

#include <JuceHeader.h>

#include "widget_ButtonForOpeningVoiceNameEditor.h"



class UnexposedParameters;

class ButtonAndLabelForEditingVoiceName :
	public Component,
	private Label::Listener,
	private Timer
{
	Label voiceNameEditor;
	ButtonForOpeningVoiceNameEditor button_ForOpeningVoiceNameEditor;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	String voiceName;
	int nameCharacterNum{ 0 };

public:
	ButtonAndLabelForEditingVoiceName() = delete;

	ButtonAndLabelForEditingVoiceName(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void labelTextChanged(Label* labelThatHasChanged) override;
	void startUpdatingVoiceName(String newName);
	void timerCallback() override;
	void updateNameCharacterInExposedParams();

public:
	~ButtonAndLabelForEditingVoiceName();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonAndLabelForEditingVoiceName)
};
