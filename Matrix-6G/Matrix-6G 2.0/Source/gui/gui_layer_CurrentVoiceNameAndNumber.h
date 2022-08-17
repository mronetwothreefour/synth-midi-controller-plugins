#pragma once

#include <JuceHeader.h>

class CurrentVoiceOptions;
class TooltipsOptions;

class GUI_Layer_CurrentVoiceNameAndNumber :
	public Component,
	public Value::Listener
{
	CurrentVoiceOptions* currentVoiceOptions;
	TooltipsOptions* tooltips;
	Label voiceNameEditor;
	Value shouldShowDescriptionValue;
	Value currentVoiceNameValue;
	Value currentVoiceNumberValue;
	String voiceName;
	const String allowed_ASCII_Characters{ "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?<>;:.,-+*/=()'\"&%$#!_^\\|[" };

public:
	GUI_Layer_CurrentVoiceNameAndNumber() = delete;

	GUI_Layer_CurrentVoiceNameAndNumber(CurrentVoiceOptions* currentVoiceOptions, TooltipsOptions* tooltips);

private:
	void updateTooltips();

public:
	void valueChanged(Value& value) override;
	~GUI_Layer_CurrentVoiceNameAndNumber();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CurrentVoiceNameAndNumber)
};