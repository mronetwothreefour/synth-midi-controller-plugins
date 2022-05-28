#pragma once

#include <JuceHeader.h>


class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Label::Listener,
	public ValueTree::Listener,
	private MultiTimer,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	Label voiceNameEditor;
	TextButton button_ShowVoiceNameEditor;
	TextButton button_WriteEditBuffer;
	TextButton button_ReadEditBuffer;
	TextButton button_Undo;
	TextButton button_Redo;
	HyperlinkButton button_Hyperlink;
	TextButton buttons_ForClearingSeqTracks[4];
	int sequencerStep{ -1 };
	int nameCharNum{ -1 };
	const int timerID_VoiceNameEdit{ 4 };
	String voiceName;
	const String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void updateTooltips();
	void showVoiceNameEditor();
	String getVoiceNameFromExposedParemeters();
	void labelTextChanged(Label* labelThatHasChanged) override;
	void startUpdatingVoiceName(String newName);
	void startClearingSeqTrack(int trackNum);
	void timerCallback(int timerID) override;
	void updateExposedParamForNameChar();
	void clearSequencerStep(int trackNum, int stepNum);
	void timerCallback() override;

public:
	void mouseDown(const MouseEvent& event) override;
	void resized() override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};