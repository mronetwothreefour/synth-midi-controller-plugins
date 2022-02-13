#include "widget_global_ComboBoxForSelectingVoicesMapEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingVoiceMapEnabled::ComboBoxForSelectingVoiceMapEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_VoicesMapEnabled },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto paramValue{ globalOptions->voicesMapEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingVoiceMapEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When enabled, incoming program change messages\n";
		tooltipText += "will load voices on the hardware according to\n";
		tooltipText += "the Patch Map. Click the EDIT button below to make\n";
		tooltipText += "changes to the Patch Map. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hardware.\n";
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

ComboBoxForSelectingVoiceMapEnabled::~ComboBoxForSelectingVoiceMapEnabled() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
