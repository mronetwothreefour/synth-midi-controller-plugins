#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace P_600_G_Constants;

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;

class TextEditorForExposedParamKnob :
	public Component,
	public Value::Listener
{
	const uint8 paramIndex;
	InfoForExposedParameters* info;
	RangedAudioParameter* paramPtr;
	Label textEditor;
	Value paramAsValue;
	const String oq{ GUI::openQuote };
	const String cq{ GUI::closeQuote };

public:
	TextEditorForExposedParamKnob() = delete;

	TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions);

private:
	void setEditorTextUsingStoredValue();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForExposedParamKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForExposedParamKnob)
};