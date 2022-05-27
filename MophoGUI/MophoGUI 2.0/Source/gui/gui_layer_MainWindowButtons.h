#pragma once

#include <JuceHeader.h>


class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public ValueTree::Listener,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	TextButton button_WriteEditBuffer;
	TextButton button_ReadEditBuffer;
	HyperlinkButton button_Hyperlink;

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void timerCallback() override;

public:
	void mouseDown(const MouseEvent& event) override;
	void resized() override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};