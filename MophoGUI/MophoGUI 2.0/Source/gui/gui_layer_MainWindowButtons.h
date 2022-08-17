#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class ExposedParamsRandomizationMethods;
class GlobalOptions;
class GUI_Layer_CommError_NRPN;
class GUI_Layer_CommError_SysEx;
class GUI_Layer_GlobalParameters;
class GUI_Layer_Randomization;
class GUI_Layer_VoicesBanks;
class InfoForExposedParameters;
class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Button::Listener,
	public Label::Listener,
	public Value::Listener,
	private MultiTimer,
	private Timer
{
	ExposedParameters* exposedParams;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationMethods* randomize;
	UnexposedParameters* unexposedParams;
	GlobalOptions* global;
	TooltipsOptions* tooltips;
	Label voiceNameEditor;
	TextButton btn_ShowVoiceNameEditor;
	TextButton btn_WriteEditBuffer;
	TextButton btn_ReadEditBuffer;
	TextButton btn_ShowVoicesBanks;
	TextButton btn_ShowGlobalParams;
	TextButton btn_Randomize;
	TextButton btn_Undo;
	TextButton btn_Redo;
	HyperlinkButton btn_Hyperlink;
	TextButton btns_ClearSeqTracks[4];
	std::unique_ptr<GUI_Layer_VoicesBanks> layer_VoicesBanks;
	std::unique_ptr<GUI_Layer_GlobalParameters> layer_GlobalParams;
	std::unique_ptr<GUI_Layer_CommError_NRPN> layer_CommError_NRPN;
	std::unique_ptr<GUI_Layer_CommError_SysEx> layer_CommError_SysEx;
	std::unique_ptr<GUI_Layer_Randomization> layer_Randomization;
	Value shouldShowDescriptionValue;
	int nameCharNum{ -1 };
	int sequencerStep{ -1 };
	const int timerID_VoiceNameEdit{ 4 };
	String voiceName;
	const String basic_ASCII_Characters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };
	bool wasRightClicked{ false };

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
	void showVoicesBanksLayer();
	void prepareToShowGlobalParamsLayer();
	void showCommError_SysExLayer();
	void showCommError_NRPN_Layer();
	void showGlobalParamsLayer();
	void showRandomizationLayer();
	void timerCallback() override;

public:
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};