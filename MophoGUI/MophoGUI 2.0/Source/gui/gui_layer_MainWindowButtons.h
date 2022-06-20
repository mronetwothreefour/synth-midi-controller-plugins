#pragma once

#include <JuceHeader.h>



class GlobalOptions;
class GUI_Layer_CommError_NRPN;
class GUI_Layer_CommError_SysEx;
class GUI_Layer_GlobalParameters;
class GUI_Layer_VoicesBanks;
class TooltipsOptions;
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
	GlobalOptions* global;
	TooltipsOptions* tooltips;
	Label voiceNameEditor;
	TextButton button_ShowVoiceNameEditor;
	TextButton button_WriteEditBuffer;
	TextButton button_ReadEditBuffer;
	TextButton button_ShowVoicesBanks;
	TextButton button_ShowGlobalParams;
	TextButton button_Undo;
	TextButton button_Redo;
	HyperlinkButton button_Hyperlink;
	TextButton buttons_ForClearingSeqTracks[4];
	std::unique_ptr<GUI_Layer_VoicesBanks> voicesBanks;
	std::unique_ptr<GUI_Layer_GlobalParameters> globalParams;
	std::unique_ptr<GUI_Layer_CommError_NRPN> commError_NRPN;
	std::unique_ptr<GUI_Layer_CommError_SysEx> commError_SysEx;
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
	void showVoicesBanksLayer();
	void prepareToShowGlobalParamsLayer();
	void showCommError_SysExLayer();
	void showCommError_NRPN_Layer();
	void showGlobalParamsLayer();
	void timerCallback() override;

public:
	void mouseDown(const MouseEvent& event) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};