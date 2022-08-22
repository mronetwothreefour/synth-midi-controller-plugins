#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using RangeType = KnobValueRangeType;

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;

class TextEditorForExposedParamKnob :
	public Component,
	public Value::Listener
{
	const uint8 paramIndex;
	InfoForExposedParameters* info;
	KnobValueRangeType rangeType;
	RangedAudioParameter* paramPtr;
	Label textEditor;
	Value parameterValue;

public:
	TextEditorForExposedParamKnob() = delete;

	TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions);
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForExposedParamKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForExposedParamKnob)
};