#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class GUI_Layer_VoicesBank;
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
	TooltipsOptions* tooltips;
	TextButton btn_Push;
	TextButton btn_Pull;
	TextButton btn_ShowVoicesBank;
	std::unique_ptr<GUI_Layer_VoicesBank> layer_VoicesBank;
	Value shouldShowDescriptionAsValue;

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();
	void timerCallback() override;
	void addProgramChangeMessageToOutgoingBuffersAfterDelay(int delayInMilliseconds);
	void showVoicesBankLayer();

public:
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};