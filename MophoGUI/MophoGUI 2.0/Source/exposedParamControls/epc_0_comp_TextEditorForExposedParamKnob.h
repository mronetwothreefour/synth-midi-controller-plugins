#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;
using EditorType = KnobTextEditorType;

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;

class TextEditorForExposedParamKnob :
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
	TextEditorForExposedParamKnob() = delete;

	TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void setEditorTextUsingStoredValue();

	void onEditorShow_ClockTempo(TooltipsOptions* tooltips);
	void onEditorShow_LFO_Freq(TooltipsOptions* tooltips);
	void onEditorShow_LPF_Freq(TooltipsOptions* tooltips);
	void onEditorShow_OscFineTune(TooltipsOptions* tooltips);
	void onEditorShow_OscPitch(TooltipsOptions* tooltips);
	void onEditorShow_OscShape(TooltipsOptions* tooltips);
	void onEditorShow_OscSlop(TooltipsOptions* tooltips);
	void onEditorShow_PitchBend(TooltipsOptions* tooltips);
	void onEditorShow_PosNeg_127(TooltipsOptions* tooltips);
	void onEditorShow_Pos_127(TooltipsOptions* tooltips);

	void onTextChange_NumericRanges();
	void onTextChange_PitchAndFreqRanges();
	void onTextChange_OscShape();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForExposedParamKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForExposedParamKnob)
};