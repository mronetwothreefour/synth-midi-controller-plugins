#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;
using SliderType = SplitParamSliderType;

class SplitOptions;
class TooltipsOptions;
class UnexposedParameters;

class TextEditorForSplitParamSlider :
	public Component,
	public Value::Listener
{
	SliderType sliderType;
	SplitOptions* splitOptions;
	TooltipsOptions* tooltips;
	Label textEditor;
	Value splitParamAsValue;
	const String oq{ GUI::openQuote };
	const String cq{ GUI::closeQuote };

public:
	TextEditorForSplitParamSlider() = delete;

	TextEditorForSplitParamSlider(SliderType sliderType, UnexposedParameters* unexposedParams);

private:
	void setEditorTextUsingStoredValue();

	void onEditorShow_ZoneVolumeBalance();
	void onEditorShow_ZoneLimit();
	void onEditorShow_ZoneVoiceNumber();
	void onEditorShow_ZoneTranspose();

	void onTextChange_ZoneVolumeBalance();
	void onTextChange_ZoneLimit(SplitZone zone);
	void onTextChange_ZoneVoiceNumber(SplitZone zone);
	void onTextChange_ZoneTranspose(SplitZone zone);

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForSplitParamSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForSplitParamSlider)
};