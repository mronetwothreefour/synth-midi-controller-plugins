#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;
using EditorType = SliderTextEditorType;

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;

class TextEditorForExposedParamSlider :
	public Component,
	public Value::Listener
{
	const uint8 paramIndex;
	InfoForExposedParameters* info;
	EditorType editorType;
	RangedAudioParameter* paramPtr;
	Label textEditor;
	Value paramAsValue;
	const String oq{ GUI::openQuote };
	const String cq{ GUI::closeQuote };

public:
	TextEditorForExposedParamSlider() = delete;

	TextEditorForExposedParamSlider(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void setEditorTextUsingStoredValue();

	void onEditorShow_Pitch(TooltipsOptions* tooltips);
	void onEditorShow_SignedRanges(TooltipsOptions* tooltips);
	void onEditorShow_UnsignedRanges(TooltipsOptions* tooltips);

	void onTextChange_Pitch();
	void onTextChange_NumericRanges();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForExposedParamSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForExposedParamSlider)
};