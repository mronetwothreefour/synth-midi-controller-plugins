#include "widget_master_SliderForSettingLever3Controller.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SliderForSettingLever3Controller::SliderForSettingLever3Controller(UnexposedParameters* unexposedParams) :
	BaseSliderForSettingControllerNumber{ unexposedParams, ID::global_Lever3ControllerNumber },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ (double)masterOptions->lever3ControllerNumber() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 2.0);
	setTooltip(generateTooltipString());
}

String SliderForSettingLever3Controller::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "The modulation wheel on Oberheim keyboard controllers\n";
		tooltipText += "(" + GUI::openQuote + "Lever 2" + GUI::closeQuote + ") was bi-directional, like a pitch bend wheel.\n";
		tooltipText += GUI::openQuote + "Lever 3" + GUI::closeQuote + " modulation increased as Lever 2 was pushed\n";
		tooltipText += "away from the player. This option selects the MIDI\n";
		tooltipText += "controller channel that Lever 3 will transmit and\n";
		tooltipText += "receive on. Range: 0 to 121. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hardware.\n";
		tooltipText += "Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: CC #";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

SliderForSettingLever3Controller::~SliderForSettingLever3Controller() {
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->removeListener(this);
}
