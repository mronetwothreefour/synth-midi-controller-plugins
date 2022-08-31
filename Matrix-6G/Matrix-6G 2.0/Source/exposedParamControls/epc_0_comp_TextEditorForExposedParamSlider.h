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
	Value parameterValue;
	const String oq{ GUI::openQuote };
	const String cq{ GUI::closeQuote };

public:
	TextEditorForExposedParamSlider() = delete;

	TextEditorForExposedParamSlider(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions);
	void setEditorText();

	void onEditorShow_Pitch(TooltipsOptions* tooltipsOptions);
	void onEditorShow_SignedRanges(TooltipsOptions* tooltipsOptions);
	void onEditorShow_UnsignedRanges(TooltipsOptions* tooltipsOptions);

	void onTextChange_Pitch();
	void onTextChange_NumericRanges();

	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForExposedParamSlider();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForExposedParamSlider)
};