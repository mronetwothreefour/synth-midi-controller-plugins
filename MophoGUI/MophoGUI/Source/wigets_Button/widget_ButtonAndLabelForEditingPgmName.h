#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ButtonAndLabelForEditingPgmName :
	public Component,
	private Label::Listener,
	private Timer,
	public ValueTree::Listener
{
	TextButton button;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	Label pgmNameEditor;
	String programName;
	int nameCharacter{ 0 };

public:
	ButtonAndLabelForEditingPgmName() = delete;

	ButtonAndLabelForEditingPgmName(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
	
	const String createButtonTooltipString() noexcept;
	void showPgmNameEditor();
	String getProgramNameFromExposedParemeters();
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
