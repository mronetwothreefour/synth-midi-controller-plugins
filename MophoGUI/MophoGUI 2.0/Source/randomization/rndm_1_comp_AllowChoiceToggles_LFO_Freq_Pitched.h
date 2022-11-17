#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowChoiceToggles_LFO_Freq_Pitched :
	public AllowChoiceToggles_Base
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	const uint8 numberOfFreq;

public:
	AllowChoiceToggles_LFO_Freq_Pitched() = delete;

	AllowChoiceToggles_LFO_Freq_Pitched(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	String buildChoiceName(uint8 pitchedFreq) override;
	String buildTooltip() override;
	const bool choiceIsAllowed(uint8 pitchedFreq) override;
	void setChoiceIsAllowed(uint8 pitchedFreq, bool shouldBeAllowed) override;
	void clearAllowedChoices() override;
	const bool noChoiceIsAllowed() override;

public:
	void restoreToggles() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_LFO_Freq_Pitched)
};