#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;

class ExposedParamsRandomizationOptions;
class TooltipsOptions;

class AllowChoiceToggles_SeqTrackStep :
	public AllowChoiceToggles_Base
{
	Track track;
	Step step;
	bool destIsPitched;
	ExposedParamsRandomizationOptions* randomization;
	TooltipsOptions* tooltips;

public:
	AllowChoiceToggles_SeqTrackStep() = delete;

	AllowChoiceToggles_SeqTrackStep(Track track, bool destIsPitched, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips);

private:
	String buildChoiceName(uint8 choiceNum) override;
	String buildTooltip() override;
	const bool choiceIsAllowed(uint8 choiceNum) override;
	void setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) override;
	void clearAllowedChoices() override;
	const bool noChoiceIsAllowed() override;

public:
	void restoreToggles() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_SeqTrackStep)
};