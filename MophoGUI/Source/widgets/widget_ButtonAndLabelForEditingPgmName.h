#pragma once

#include <JuceHeader.h>



class ButtonAndLabelForEditingPgmName :
	public Component,
	private Label::Listener,
	private Timer
{
	TextButton button;
	AudioProcessorValueTreeState* exposedParams;
	Label pgmNameEditor;
	String programName;
	int nameCharacter{ 0 };

	void showPgmNameEditor();
	String getProgramNameFromExposedParemeters();
	void labelTextChanged(Label* labelThatHasChanged) override;
	void addSpacesToEndOfName(String& name);
	void updateProgramNameOnHardware(String newName);
	void timerCallback() override;
	void updateNameCharacterInExposedParams();

public:
	ButtonAndLabelForEditingPgmName() = delete;

	explicit ButtonAndLabelForEditingPgmName(AudioProcessorValueTreeState* exposedParams);
	~ButtonAndLabelForEditingPgmName();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonAndLabelForEditingPgmName)
};
