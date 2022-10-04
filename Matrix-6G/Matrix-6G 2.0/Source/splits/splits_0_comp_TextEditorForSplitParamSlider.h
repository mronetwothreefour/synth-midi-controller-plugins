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
	Label textEditor;
	Value splitParamAsValue;
	const String oq{ GUI::openQuote };
	const String cq{ GUI::closeQuote };

public:
	TextEditorForSplitParamSlider() = delete;

	TextEditorForSplitParamSlider(SliderType sliderType, UnexposedParameters* unexposedParams);

private:
	void setEditorTextUsingStoredValue();

	void onEditorShow_ZoneVolumeBalance(SplitOptions* splitOptions, TooltipsOptions* tooltips);
	void onEditorShow_ZoneLimit(SplitOptions* splitOptions, TooltipsOptions* tooltips);
	void onEditorShow_ZoneVoiceNumber(SplitOptions* splitOptions, TooltipsOptions* tooltips);
	void onEditorShow_ZoneTranspose(SplitOptions* splitOptions, TooltipsOptions* tooltips);

	void onTextChange_ZoneVolumeBalance(SplitOptions* splitOptions);
	void onTextChange_ZoneLimit(bool isLowerZone, SplitOptions* splitOptions);
	void onTextChange_ZoneVoiceNumber(bool isLowerZone, SplitOptions* splitOptions);
	void onTextChange_ZoneTranspose(bool isLowerZone, SplitOptions* splitOptions);

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForSplitParamSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForSplitParamSlider)
};