#pragma once

#include <JuceHeader.h>

#include "gui_comp_JuceSlidersWithMouseMods.h"

class TooltipsOptions;
class UnexposedParameters;
class VoiceTransmissionOptions;

class GUI_Layer_CurrentVoiceNumber :
	public Component,
	public Value::Listener
{
	TooltipsOptions* tooltips;
	VoiceTransmissionOptions* transmitOptions;
	RotarySliderWithMouseWheelMoveOverride voiceNumber;
	Label voiceNumberEditor;
	Value shouldShowDescriptionAsValue;
	Value currentVoiceNumberAsValue;

public:
	GUI_Layer_CurrentVoiceNumber() = delete;

	explicit GUI_Layer_CurrentVoiceNumber(UnexposedParameters* unexposedParams);

private:
	void setVoiceNumberEditorText();
	void updateTooltip();

public:
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_CurrentVoiceNumber();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CurrentVoiceNumber)
};