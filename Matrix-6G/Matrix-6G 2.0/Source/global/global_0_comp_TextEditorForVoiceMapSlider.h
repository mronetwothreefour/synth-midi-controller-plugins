#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class GlobalOptions;
class TooltipsOptions;

class TextEditorForVoiceMapSlider :
	public Component,
	public Value::Listener
{
	Label textEditor;
	Value globalParamAsValue;

public:
	TextEditorForVoiceMapSlider() = delete;

	TextEditorForVoiceMapSlider(uint8 mapSlotNum, VoiceMapSliderType sliderType, GlobalOptions* global, TooltipsOptions* tooltips);

private:
	void setEditorTextUsingStoredValue();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForVoiceMapSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForVoiceMapSlider)
};