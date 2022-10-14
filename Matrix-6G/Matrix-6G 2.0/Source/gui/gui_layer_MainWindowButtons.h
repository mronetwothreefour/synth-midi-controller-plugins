#pragma once

#include <JuceHeader.h>

#include "gui_comp_ButtonForActivatingQuickEdit.h"

class ExposedParameters;
class GUI_Layer_Splits;
class GUI_Layer_VoicesBanks;
class Outgoing_MIDI_Buffers;
class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Button::Listener,
	public Value::Listener,
	private Timer
{
	ExposedParameters* exposedParams;
	UnexposedParameters* unexposedParams;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	TooltipsOptions* tooltips;
	ButtonForActivatingQuickEdit btn_ActivateQuickEdit;
	TextButton btn_Push;
	TextButton btn_Pull;
	TextButton btn_ShowVoicesBanks;
	TextButton btn_ShowSplits;
	std::unique_ptr<GUI_Layer_Splits> layer_Splits;
	std::unique_ptr<GUI_Layer_VoicesBanks> layer_VoicesBanks;
	Value shouldShowDescriptionAsValue;

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();
	void timerCallback() override;
	void addProgramChangeMessageToOutgoingBuffersAfterDelay(int delayInMilliseconds);
	void showSplitsLayer();
	void showVoicesBanksLayer();

public:
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};