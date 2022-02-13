#include "widget_master_SliderForSettingDisplayBrightness.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingDisplayBrightness::SliderForSettingDisplayBrightness(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(1.0, 31.0, 1.0);
	auto paramValue{ (double)masterOptions->displayBrightness() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 27.0);
	setMouseDragSensitivity(95);
	setTooltip(generateTooltipString());
}

String SliderForSettingDisplayBrightness::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the brightness of the display\n";
		tooltipText += "on the front panel of the hardware.\n";
		tooltipText += "Range: 1 (dimmest) to 31 (brightest).\n";
		tooltipText += "NOTE: Individual Master options are not\n";
		tooltipText += "immediately updated on the hardware.\n";
		tooltipText += "Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: Channel ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingDisplayBrightness::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::global_DisplayBrightness) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingDisplayBrightness::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingDisplayBrightness::~SliderForSettingDisplayBrightness() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->removeListener(this);
}