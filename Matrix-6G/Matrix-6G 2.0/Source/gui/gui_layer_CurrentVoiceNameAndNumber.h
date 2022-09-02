#pragma once

#include <JuceHeader.h>

#include "gui_comp_JuceSlidersWithMouseMods.h"

class ExposedParameters;
class CurrentVoiceOptions;
class TooltipsOptions;

class GUI_Layer_CurrentVoiceNameAndNumber :
	public Component,
	public Value::Listener
{
	CurrentVoiceOptions* currentVoiceOptions;
	TooltipsOptions* tooltips;
	Label voiceNameEditor;
	RotarySliderWithMouseWheelMoveOverride voiceNumber;
	Label voiceNumberEditor;
	Value shouldShowDescriptionValue;
	Value currentVoiceNameValue;
	Value currentVoiceNumberValue;
	String voiceName;
	const String allowed_ASCII_Characters{ "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?<>;:.,-+*/=()'\"&%$#!_^\\|[" };

public:
	GUI_Layer_CurrentVoiceNameAndNumber() = delete;

	GUI_Layer_CurrentVoiceNameAndNumber(ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void setVoiceNumberEditorText();
	void updateTooltips();

public:
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_CurrentVoiceNameAndNumber();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CurrentVoiceNameAndNumber)
};