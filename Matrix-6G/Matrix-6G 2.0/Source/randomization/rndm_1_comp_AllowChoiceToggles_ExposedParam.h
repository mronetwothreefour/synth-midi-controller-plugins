#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"

class ExposedParameters;
class ParamRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowChoiceToggles_ExposedParam :
	public AllowChoiceToggles_Base
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ParamRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	uint8 numberOfChoices;
	bool rangeIsSigned;

public:
	AllowChoiceToggles_ExposedParam() = delete;

	AllowChoiceToggles_ExposedParam(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	String buildChoiceName(uint8 choiceNum) override;
	String buildTooltip() override;
	const bool choiceIsAllowed(uint8 choiceNum) override;
	void setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) override;
	void clearAllowedChoices() override;
	const bool noChoiceIsAllowed() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_ExposedParam)
};