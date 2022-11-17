#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_KnobForSeqTrackProbability.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;
using KnobType = SeqTrackProbabilityKnobType;
using Track = SeqTrackNum;

class ExposedParameters;
class TooltipsOptions;

class SeqTrackProbabilities :
	public Component
{
	Track track;
	std::unique_ptr<KnobForSeqTrackProbability> knob_RestProbability;
	KnobForSeqTrackProbability knob_ResetProbability;

public:
	SeqTrackProbabilities() = delete;

	SeqTrackProbabilities(Track track, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	~SeqTrackProbabilities();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackProbabilities)
};