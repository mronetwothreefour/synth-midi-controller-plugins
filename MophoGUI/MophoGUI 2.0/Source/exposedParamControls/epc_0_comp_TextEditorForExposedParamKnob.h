#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

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
	const String oq{ GUI::openQuote };
	const String cq{ GUI::closeQuote };

public:
	TextEditorForExposedParamKnob() = delete;

	TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions);
	void setEditorText();

	void onEditorShow_ClockTempo(TooltipsOptions* tooltipsOptions);
	void onEditorShow_LFO_Freq(TooltipsOptions* tooltipsOptions);
	void onEditorShow_LPF_Freq(TooltipsOptions* tooltipsOptions);
	void onEditorShow_OscFineTune(TooltipsOptions* tooltipsOptions);
	void onEditorShow_OscPitch(TooltipsOptions* tooltipsOptions);
	void onEditorShow_OscShape(TooltipsOptions* tooltipsOptions);
	void onEditorShow_OscSlop(TooltipsOptions* tooltipsOptions);
	void onEditorShow_PitchBend(TooltipsOptions* tooltipsOptions);
	void onEditorShow_PosNeg_127(TooltipsOptions* tooltipsOptions);
	void onEditorShow_Pos_127(TooltipsOptions* tooltipsOptions);

	void onTextChange_NumericRanges();
	void onTextChange_PitchAndFreqRanges();
	void onTextChange_OscShape();

	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForExposedParamKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForExposedParamKnob)
};