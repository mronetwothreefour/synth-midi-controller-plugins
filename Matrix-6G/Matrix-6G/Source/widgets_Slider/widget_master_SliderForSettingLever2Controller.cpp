#include "widget_master_SliderForSettingLever2Controller.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SliderForSettingLever2Controller::SliderForSettingLever2Controller(UnexposedParameters* unexposedParams) :
	BaseSliderForSettingControllerNumber{ unexposedParams, ID::master_Lever2ControllerNumber },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ (double)masterOptions->lever2ControllerNumber() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 1.0);
	setTooltip(generateTooltipString());
}

String SliderForSettingLever2Controller::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the MIDI controller channel that Lever 2\n";
		tooltipText += "will transmit and receive on. " + GUI::openQuote + "Lever 2" + GUI::closeQuote + " is equi-\n";
		tooltipText += "valent to the modulation wheel found on most\n";
		tooltipText += "MIDI keyboard controllers. Range: 0 to 121.\n";
		tooltipText += "NOTE: Individual Master options are not immedi-\n";
		tooltipText += "ately updated on the hardware. Click the PUSH\n";
		tooltipText += "button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: CC #";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

SliderForSettingLever2Controller::~SliderForSettingLever2Controller() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
