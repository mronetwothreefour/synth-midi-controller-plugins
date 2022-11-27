#pragma once

#include <JuceHeader.h>

#include "gui_comp_ButtonForActivatingQuickEdit.h"

class ExposedParameters;
class InfoForExposedParameters;
class ParamRandomizationMethods;
class GlobalOptions;
class GUI_Layer_CommError;
class GUI_Layer_GlobalParameters;
class GUI_Layer_Randomization;
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
	InfoForExposedParameters* info;
	ParamRandomizationMethods* randomize;
	UnexposedParameters* unexposedParams;
	GlobalOptions* global;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	TooltipsOptions* tooltips;
	ButtonForActivatingQuickEdit btn_ActivateQuickEdit;
	TextButton btn_Push;
	TextButton btn_Pull;
	TextButton btn_Randomize;
	TextButton btn_ShowVoicesBanks;
	TextButton btn_ShowSplits;
	TextButton btn_ShowGlobalParams;
	std::unique_ptr<GUI_Layer_Randomization> layer_Randomization;
	std::unique_ptr<GUI_Layer_Splits> layer_Splits;
	std::unique_ptr<GUI_Layer_VoicesBanks> layer_VoicesBanks;
	std::unique_ptr<GUI_Layer_GlobalParameters> layer_GlobalParams;
	std::unique_ptr<GUI_Layer_CommError> layer_CommError;
	Value shouldShowDescriptionAsValue;
	bool wasRightClicked{ false };

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();
	void timerCallback() override;
	void addProgramChangeMessageToOutgoingBuffersAfterDelay(int delayInMilliseconds);
	void showRandomizationLayer();
	void showSplitsLayer();
	void showVoicesBanksLayer();
	void prepareToShowGlobalParamsLayer();
	void showCommErrorLayer();
	void showGlobalParamsLayer();

public:
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};