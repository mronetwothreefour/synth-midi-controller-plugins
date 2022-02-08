#include "widget_master_SliderForSettingVibratoSpeed.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingVibratoSpeed::SliderForSettingVibratoSpeed(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 63.0, 1.0);
	auto paramValue{ (double)masterOptions->vibratoSpeed() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 30.0);
	setMouseDragSensitivity(110);
	setTooltip(generateTooltipString());
}

String SliderForSettingVibratoSpeed::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the cycle rate of low-frequency\n";
		tooltipText += "oscillator 3, which is dedicated to vibrato.\n";
		tooltipText += "Range: 0 (slowest) to 63 (fastest).\n";
		tooltipText += "NOTE: Individual Master options are not\n";
		tooltipText += "immediately updated on the hardware.\n";
		tooltipText += "Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingVibratoSpeed::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::master_VibratoSpeed) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingVibratoSpeed::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingVibratoSpeed::~SliderForSettingVibratoSpeed() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
