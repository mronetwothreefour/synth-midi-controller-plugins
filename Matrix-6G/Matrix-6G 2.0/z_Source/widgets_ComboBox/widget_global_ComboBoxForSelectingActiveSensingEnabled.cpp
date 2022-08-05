#include "widget_global_ComboBoxForSelectingActiveSensingEnabled.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ComboBoxForSelectingActiveSensingEnabled::ComboBoxForSelectingActiveSensingEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_ActiveSensingEnabled },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto paramValue{ globalOptions->activeSensingEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingActiveSensingEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, the hardware will monitor the MIDI\n";
		tooltipText += "connections to external devices and confirm that\n";
		tooltipText += "they are intact. If a connection is broken, an " + GUI::openQuote + "all\n";
		tooltipText += "notes off" + GUI::closeQuote + " command is initiated to prevent notes\n";
		tooltipText += "from being locked on. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hard-\n";
		tooltipText += "ware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingActiveSensingEnabled::~ComboBoxForSelectingActiveSensingEnabled() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
