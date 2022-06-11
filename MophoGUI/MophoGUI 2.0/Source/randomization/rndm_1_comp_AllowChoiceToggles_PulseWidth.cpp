#include "rndm_1_comp_AllowChoiceToggles_PulseWidth.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



AllowChoiceToggles_PulseWidth::AllowChoiceToggles_PulseWidth(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	numberOfWidths{ EP::numberOfPulseWidths },
	AllowChoiceToggles_Base{ numberOfWidths, 10, 10, 0, 42 }
{
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
}

String AllowChoiceToggles_PulseWidth::buildChoiceName(uint8 pulseWidth) {
	return "PW " + (String)pulseWidth;
}

String AllowChoiceToggles_PulseWidth::buildTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String toggleTooltip{ "" };
	if (shouldShowDescriptions) {
		auto paramID{ Info::get().IDfor(paramIndex).toString() };
		auto oscNumString{ paramID.fromFirstOccurrenceOf("Osc_", false, false).upToFirstOccurrenceOf("_Shape", false, false) };
		toggleTooltip += "Click a pulse width to toggle whether or\n";
		toggleTooltip += "not it is allowed when generating a random\n";
		toggleTooltip += "shape for oscillator " + oscNumString + ".\n";
		toggleTooltip += "CTRL-click a pulse width to make it the only\n";
		toggleTooltip += "one allowed. SHIFT-click to allow a range of\n";
		toggleTooltip += "pulse widths. ALT-click to allow a range of\n";
		toggleTooltip += "pulse widths that are all in the same row.";
	}
	return toggleTooltip;
}

const bool AllowChoiceToggles_PulseWidth::choiceIsAllowed(uint8 pulseWidth) {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	return randomizationOptions->pulseWidthIsAllowedForParam(pulseWidth, paramIndex);
}

void AllowChoiceToggles_PulseWidth::setChoiceIsAllowed(uint8 pulseWidth, bool shouldBeAllowed) {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	randomizationOptions->setPulseWidthIsAllowedForParam(pulseWidth, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_PulseWidth::clearAllowedChoices() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	randomizationOptions->clearAllowedPulseWidthsForParam(paramIndex);
}

const bool AllowChoiceToggles_PulseWidth::noChoiceIsAllowed() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	return randomizationOptions->noPulseWidthIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles_PulseWidth::restoreToggles() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	for (auto pulseWidth = 0; pulseWidth < numberOfWidths; ++pulseWidth) {
		auto isAllowed{ randomizationOptions->pulseWidthIsAllowedForParam(pulseWidth, paramIndex) };
		allowedChoiceToggles[pulseWidth]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
