#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class ExposedParamsRandomizationMethods;
class GUI_Layer_Randomization;
class GUI_Layer_TooltipsOptions;
class GUI_Layer_VoicesBank;
class Outgoing_MIDI_Buffers;
class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Button::Listener,
	public Value::Listener
{
	ExposedParameters* exposedParams;
	UnexposedParameters* unexposedParams;
	ExposedParamsRandomizationMethods* randomize;
	TooltipsOptions* tooltips;
	TextButton btn_Push;
	TextButton btn_Pull;
	TextButton btn_ShowVoicesBank;
	TextButton btn_ShowTooltipsOptions;
	TextButton btn_Undo;
	TextButton btn_Redo;
	TextButton btn_Randomize;
	std::unique_ptr<GUI_Layer_VoicesBank> layer_VoicesBank;
	std::unique_ptr<GUI_Layer_TooltipsOptions> layer_TooltipsOptions;
	std::unique_ptr<GUI_Layer_Randomization> layer_Randomization;
	Value shouldShowDescriptionAsValue;
	bool wasRightClicked{ false };

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();
	void showVoicesBankLayer();
	void showTooltipsOptionsLayer();
	void showRandomizationLayer();

public:
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};