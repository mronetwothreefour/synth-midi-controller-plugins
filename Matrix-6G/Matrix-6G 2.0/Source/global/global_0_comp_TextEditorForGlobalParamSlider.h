#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class GlobalOptions;
class TooltipsOptions;
class UnexposedParameters;

class TextEditorForGlobalParamSlider :
	public Component,
	public Value::Listener
{
	GlobalParamSliderType sliderType;
	GlobalOptions* global;
	TooltipsOptions* tooltips;
	Label textEditor;
	Value globalParamAsValue;

public:
	TextEditorForGlobalParamSlider() = delete;

	TextEditorForGlobalParamSlider(GlobalParamSliderType sliderType, UnexposedParameters* unexposedParams);

private:
	void setEditorTextUsingStoredValue();

	void onEditorShow_BasicChannel();
	void onEditorShow_ControllerNum();
	void onEditorShow_VibratoSliders();
	void onEditorShow_GlobalTune();
	void onEditorShow_DisplayBrightness();

	void onTextChange_BasicChannel();
	void onTextChange_ControllerNum();
	void onTextChange_VibratoSliders();
	void onTextChange_GlobalTune();
	void onTextChange_DisplayBrightness();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForGlobalParamSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForGlobalParamSlider)
};