#include "widget_master_ComboBoxForSelectingControllersEnabled.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ComboBoxForSelectingControllersEnabled::ComboBoxForSelectingControllersEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_ControllersEnabled },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ masterOptions->controllersEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingControllersEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, the hardware will respond to incoming\n";
		tooltipText += "MIDI controller messages, as well as to the pedal inputs\n";
		tooltipText += "on the hardware" + GUI::apostrophe + "s rear panel (if Local Control is also on).\n";
		tooltipText += "When set to off, the hardware will only respond to MIDI\n";
		tooltipText += "note messages. NOTE: Individual Master options are not\n";
		tooltipText += "immediately updated on the hardware. Click the PUSH\n";
		tooltipText += "button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingControllersEnabled::~ComboBoxForSelectingControllersEnabled() {
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->removeListener(this);
}
