#include "widget_master_ComboBoxForSelectingSysExEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingSysExEnabled::ComboBoxForSelectingSysExEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::master_SysExEnabled },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ masterOptions->sysExEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingSysExEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, the hardware will respond to MIDI\n";
		tooltipText += "System Exclusive (SysEx) messages. IMPORTANT: This\n";
		tooltipText += "plugin uses SysEx to communicate with the hardware and\n";
		tooltipText += "it is imperative that this option be set to on. If it\n";
		tooltipText += "gets turned off, it can only be turned back on in the\n";
		tooltipText += "Master Edit page on the hardware itself (parameter 04).\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingSysExEnabled::~ComboBoxForSelectingSysExEnabled() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
