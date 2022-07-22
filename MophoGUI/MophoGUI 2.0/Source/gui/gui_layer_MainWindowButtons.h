#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_MainWindowButtons :
	public Component,
	public Value::Listener
{
	ExposedParameters* exposedParams;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	UnexposedParameters* unexposedParams;
	TooltipsOptions* tooltips;
	TextButton btn_Undo;
	TextButton btn_Redo;
	Value shouldShowDescriptionValue;

public:
	GUI_Layer_MainWindowButtons() = delete;

	GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void updateTooltips();

public:
	void valueChanged(Value& value) override;
	~GUI_Layer_MainWindowButtons();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MainWindowButtons)
};