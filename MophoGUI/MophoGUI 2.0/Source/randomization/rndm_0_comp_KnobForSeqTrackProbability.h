#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_TextEditorForSeqTrackProbabilityKnob.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;
using KnobType = SeqTrackProbabilityKnobType;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class TooltipsOptions;
class UnexposedParameters;

class KnobForSeqTrackProbability :
	public RotarySliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	KnobType knobType;
	Track track;
	ExposedParamsRandomizationOptions* randomization;
	TextEditorForSeqTrackProbabilityKnob textEditor;
	Value targetStepForSeqTrackAsValue;
	Value seqTrackProbAsValue;
	TooltipsOptions* tooltips;

public:
	KnobForSeqTrackProbability() = delete;

	KnobForSeqTrackProbability(KnobType knobType, Track track, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void mouseDoubleClick(const MouseEvent& event) override;
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~KnobForSeqTrackProbability();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForSeqTrackProbability)

};