#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowChoiceToggles_Base.h"

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;

class AllowChoiceToggles_PulseWidth :
	public AllowChoiceToggles_Base
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	const uint8 numberOfWidths;

public:
	AllowChoiceToggles_PulseWidth() = delete;

	AllowChoiceToggles_PulseWidth(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	String buildChoiceName(uint8 choiceNum) override;
	String buildTooltip() override;
	const bool choiceIsAllowed(uint8 pulseWidth) override;
	void setChoiceIsAllowed(uint8 pulseWidth, bool shouldBeAllowed) override;
	void clearAllowedChoices() override;
	const bool noChoiceIsAllowed() override;

public:
	void restoreToggles() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_PulseWidth)
};