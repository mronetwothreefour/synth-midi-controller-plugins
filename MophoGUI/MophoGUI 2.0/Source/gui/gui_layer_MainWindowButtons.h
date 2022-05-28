#pragma once

#include <JuceHeader.h>


class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public ValueTree::Listener,
	private MultiTimer,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_WriteEditBuffer;
	TextButton button_ReadEditBuffer;
	TextButton button_Undo;
	TextButton button_Redo;
	HyperlinkButton button_Hyperlink;
	TextButton buttons_ForClearingSeqTracks[4];
	int sequencerStep{ 0 };

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void clearSeqTrack(int trackNum);
	void timerCallback(int timerID) override;
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