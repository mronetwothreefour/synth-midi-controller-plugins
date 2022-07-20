#pragma once

#include <JuceHeader.h>

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
	public ValueTree::Listener
{
	KnobType knobType;
	Track track;
	ExposedParamsRandomizationOptions* randomization;
	ValueTree trackTree;
	TooltipsOptions* tooltips;

public:
	KnobForSeqTrackProbability() = delete;

	KnobForSeqTrackProbability(KnobType knobType, Track track, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~KnobForSeqTrackProbability();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForSeqTrackProbability)

};