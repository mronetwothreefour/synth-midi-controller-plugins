#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Button::Listener,
	public Label::Listener,
	public Value::Listener,
	private Timer
{
	ExposedParameters* exposedParams;
	UnexposedParameters* unexposedParams;
	TooltipsOptions* tooltips;
	Value shouldShowDescriptionAsValue;

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();

public:
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};