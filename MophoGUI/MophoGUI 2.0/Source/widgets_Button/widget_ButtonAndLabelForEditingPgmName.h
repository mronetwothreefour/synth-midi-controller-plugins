#pragma once

#include <JuceHeader.h>

#include "widget_ButtonForOpeningPgmNameEditor.h"



class UnexposedParameters;

class ButtonAndLabelForEditingPgmName :
	public Component,
	private Label::Listener,
	private Timer
{
	Label pgmNameEditor;
	ButtonForOpeningPgmNameEditor button_ForOpeningPgmNameEditor;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	String programName;
	int nameCharacter{ 0 };

public:
	ButtonAndLabelForEditingPgmName() = delete;

	ButtonAndLabelForEditingPgmName(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void labelTextChanged(Label* labelThatHasChanged) override;
	void padNamesLessThan16CharactersLongWithSpaces(String& name);
	void startUpdatingProgramName(String newName);
	void timerCallback() override;
	void updateNameCharacterInExposedParams();

public:
	~ButtonAndLabelForEditingPgmName();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonAndLabelForEditingPgmName)
};
