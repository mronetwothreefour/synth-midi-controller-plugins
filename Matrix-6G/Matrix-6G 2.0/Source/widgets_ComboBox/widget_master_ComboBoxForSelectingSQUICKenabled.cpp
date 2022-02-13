#include "widget_master_ComboBoxForSelectingSQUICKenabled.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ComboBoxForSelectingSQUICKenabled::ComboBoxForSelectingSQUICKenabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_SQUICKenabled },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ masterOptions->squickEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingSQUICKenabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When editing parameters with the keypad on the hardware" + GUI::apostrophe + "s front panel,\n";
		tooltipText += "normally the numeral keys select the parameter number and the arrow\n";
		tooltipText += "keys change the parameter value. When SQUICK (" + GUI::openQuote + "Switch Quick" + GUI::closeQuote + ") is enabled,\n";
		tooltipText += "the arrow keys select the parameter number and the numeral keys change\n";
		tooltipText += "the parameter value. NOTE: Individual Master options are not immediately\n";
		tooltipText += "updated on the hardware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingSQUICKenabled::~ComboBoxForSelectingSQUICKenabled() {
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->removeListener(this);
}
