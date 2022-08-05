#include "widget_global_ComboBoxForSelectingDescriptionTipsEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingDescriptionTipsEnabled::ComboBoxForSelectingDescriptionTipsEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_SQUICKenabled },
	unexposedParams{ unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto paramValue{ tooltipOptions->shouldShowDescription() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingDescriptionTipsEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When enabled, a descriptive tooltip will appear if the mouse\n";
		tooltipText += "hovers over a control for the amount of time specified below.\n";
		tooltipText += "NOTE: Individual Master options are not immediately updated\n";
		tooltipText += "on the hardware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

