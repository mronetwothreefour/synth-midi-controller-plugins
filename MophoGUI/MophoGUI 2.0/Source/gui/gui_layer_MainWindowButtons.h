#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Label::Listener,
	public Value::Listener,
	private MultiTimer,
	private Timer
{
	ExposedParameters* exposedParams;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	UnexposedParameters* unexposedParams;
	TooltipsOptions* tooltips;
	Label voiceNameEditor;
	TextButton btn_ShowVoiceNameEditor;
	TextButton btn_WriteEditBuffer;
	TextButton btn_ReadEditBuffer;
	TextButton btn_Undo;
	TextButton btn_Redo;
	HyperlinkButton btn_Hyperlink;
	TextButton btns_ClearSeqTracks[4];
	Value shouldShowDescriptionValue;
	int nameCharNum{ -1 };
	int sequencerStep{ -1 };
	const int timerID_VoiceNameEdit{ 4 };
	String voiceName;
	const String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
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
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};