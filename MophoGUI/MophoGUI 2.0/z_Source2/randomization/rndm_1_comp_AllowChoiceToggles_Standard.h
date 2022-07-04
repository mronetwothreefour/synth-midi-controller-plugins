#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"



class ExposedParameters;
class RandomizationOptions;
class TooltipsOptions;
class UnexposedParameters;

class AllowChoiceToggles_Standard :
	public AllowChoiceToggles_Base
{
	uint8 paramIndex;
	ExposedParameters* exposedParams;
	RandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	uint8 numberOfChoices;

public:
	AllowChoiceToggles_Standard() = delete;

	AllowChoiceToggles_Standard(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

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
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_Standard)
};