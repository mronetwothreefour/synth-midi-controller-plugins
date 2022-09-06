#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using KnobType = SeqTrackProbabilityKnobType;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;

class ExposedParamsRandomizationOptions;
class TooltipsOptions;

class TextEditorForSeqTrackProbabilityKnob :
	public Component,
	public Value::Listener
{
	KnobType knobType;
	Track track;
	ExposedParamsRandomizationOptions* randomization;
	Label textEditor;
	Value targetStepForSeqTrackAsValue;
	Value seqTrackProbAsValue;

public:
	TextEditorForSeqTrackProbabilityKnob() = delete;

	TextEditorForSeqTrackProbabilityKnob(KnobType knobType, Track track, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips);
	void setEditorText();
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForSeqTrackProbabilityKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForSeqTrackProbabilityKnob)
};