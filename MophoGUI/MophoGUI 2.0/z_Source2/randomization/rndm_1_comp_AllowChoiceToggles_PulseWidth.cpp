#include "rndm_1_comp_AllowChoiceToggles_PulseWidth.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



AllowChoiceToggles_PulseWidth::AllowChoiceToggles_PulseWidth(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	numberOfWidths{ EP::numberOfPulseWidths },
	AllowChoiceToggles_Base{ numberOfWidths, 10, 10, 0, 42 }
{
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	for (auto width = (uint8)0; width < numberOfWidths; ++width) {
		allowedChoiceToggles[width]->setName(buildChoiceName(width));
		allowedChoiceToggles[width]->setTooltip(buildTooltip());
		allowedChoiceToggles[width]->setToggleState(randomization->pulseWidthIsAllowedForParam(width, paramIndex), dontSendNotification);
	}
}

String AllowChoiceToggles_PulseWidth::buildChoiceName(uint8 pulseWidth) {
	return "PW " + (String)pulseWidth;
}

String AllowChoiceToggles_PulseWidth::buildTooltip() {
	String tip{ "" };
	if (tooltips->shouldShowDescriptions()) {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto oscNumString{ paramID.fromFirstOccurrenceOf("Osc_", false, false).upToFirstOccurrenceOf("_Shape", false, false) };
		tip += "Click a pulse width to toggle whether or\n";
		tip += "not it is allowed when generating a random\n";
		tip += "shape for oscillator " + oscNumString + ".\n";
		tip += "CTRL-click a pulse width to make it the only\n";
		tip += "one allowed. SHIFT-click to allow a range of\n";
		tip += "pulse widths. ALT-click to allow a range of\n";
		tip += "pulse widths that are all in the same row.";
	}
	return tip;
}

const bool AllowChoiceToggles_PulseWidth::choiceIsAllowed(uint8 pulseWidth) {
	return randomization->pulseWidthIsAllowedForParam(pulseWidth, paramIndex);
}

void AllowChoiceToggles_PulseWidth::setChoiceIsAllowed(uint8 pulseWidth, bool shouldBeAllowed) {
	randomization->setPulseWidthIsAllowedForParam(pulseWidth, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_PulseWidth::clearAllowedChoices() {
	randomization->clearAllowedPulseWidthsForParam(paramIndex);
}

const bool AllowChoiceToggles_PulseWidth::noChoiceIsAllowed() {
	return randomization->noPulseWidthIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles_PulseWidth::restoreToggles() {
	for (auto pulseWidth = 0; pulseWidth < numberOfWidths; ++pulseWidth) {
		auto isAllowed{ randomization->pulseWidthIsAllowedForParam(pulseWidth, paramIndex) };
		allowedChoiceToggles[pulseWidth]->setToggleState(isAllowed ? true : false, dontSendNotification);
		allowedChoiceToggles[pulseWidth]->setEnabled(true);
	}
}
