#include "widget_global_ComboBoxForSelectingOmniModeEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingOmniModeEnabled::ComboBoxForSelectingOmniModeEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_OmniModeEnabled },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto paramValue{ globalOptions->omniModeEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingOmniModeEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When Omni Mode is on, the hardware will respond to\n";
		tooltipText += "MIDI messages (notes, patch changes, and controllers)\n";
		tooltipText += "coming in on all 16 MIDI channels. When Omni Mode is\n";
		tooltipText += "off, the hardware will only respond to MIDI messages\n";
		tooltipText += "coming on the Basic Channel (above). NOTE: Individual\n";
		tooltipText += "Master options are not immediately updated on the\n";
		tooltipText += "hardware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingOmniModeEnabled::~ComboBoxForSelectingOmniModeEnabled() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
