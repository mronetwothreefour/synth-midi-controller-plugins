#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowChoiceToggles_LFO_Freq_Unsynced :
	public AllowChoiceToggles_Base
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	const uint8 numberOfFreq;

public:
	AllowChoiceToggles_LFO_Freq_Unsynced() = delete;

	AllowChoiceToggles_LFO_Freq_Unsynced(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	String buildChoiceName(uint8 unsyncedFreq) override;
	String buildTooltip() override;
	const bool choiceIsAllowed(uint8 unsyncedFreq) override;
	void setChoiceIsAllowed(uint8 unsyncedFreq, bool shouldBeAllowed) override;
	void clearAllowedChoices() override;
	const bool noChoiceIsAllowed() override;

public:
	void restoreToggles() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_LFO_Freq_Unsynced)
};