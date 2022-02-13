#include "widget_master_ComboBoxForSelectingValueTipsEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingValueTipsEnabled::ComboBoxForSelectingValueTipsEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_SQUICKenabled },
	unexposedParams{ unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto paramValue{ tooltipOptions->shouldShowCurrentValue() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingValueTipsEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When enabled, a tooltip with a verbose\n";
		tooltipText += "version of the current value will appear\n";
		tooltipText += "if the mouse hovers over a control for\n";
		tooltipText += "the amount of time specified below.\n";
		tooltipText += "NOTE: Individual Master options are not\n";
		tooltipText += "immediately updated on the hardware.\n";
		tooltipText += "Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}
