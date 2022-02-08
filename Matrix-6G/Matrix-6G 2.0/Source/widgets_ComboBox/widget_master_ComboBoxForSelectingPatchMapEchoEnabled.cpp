#include "widget_master_ComboBoxForSelectingPatchMapEchoEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingPatchMapEchoEnabled::ComboBoxForSelectingPatchMapEchoEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::master_PatchMapEchoEnabled },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ masterOptions->patchMapEchoEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingPatchMapEchoEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When the Patch Map is enabled and this option is\n";
		tooltipText += "on, the hardware will send program changes to a\n";
		tooltipText += "device further on in the MIDI chain in accordance\n";
		tooltipText += "with the Patch Map settings. NOTE: Individual Master\n";
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

ComboBoxForSelectingPatchMapEchoEnabled::~ComboBoxForSelectingPatchMapEchoEnabled() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
