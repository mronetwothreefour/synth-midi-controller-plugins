#include "widget_master_SliderForSettingVibratoModAmount.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingVibratoModAmount::SliderForSettingVibratoModAmount(UnexposedParameters* unexposedParams, const Identifier& propertyID) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	propertyID{ propertyID }
{
	jassert(propertyID == ID::global_VibratoAmplitudeModAmount || propertyID == ID::global_VibratoSpeedModAmount);
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 63.0, 1.0);
	auto paramValue{ propertyID == ID::global_VibratoAmplitudeModAmount ? masterOptions->vibratoAmplitudeModAmount() : masterOptions->vibratoSpeedModAmount() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, propertyID == ID::global_VibratoAmplitudeModAmount ? 63.0 : 0.0);
	setMouseDragSensitivity(110);
	setTooltip(generateTooltipString());
}

String SliderForSettingVibratoModAmount::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the degree to which the selected source modulates the ";
		tooltipText += propertyID == ID::global_VibratoAmplitudeModAmount ? "amplitude\n" : "speed\n";
		tooltipText += "of low-frequency oscillator 3, which is dedicated to vibrato.\n";
		tooltipText += "Range: 0 (no modulation) to 63 (maximum modulation).\n";
		tooltipText += "NOTE: Individual Master options are not immediately updated\n";
		tooltipText += "on the hardware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingVibratoModAmount::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == propertyID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingVibratoModAmount::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingVibratoModAmount::~SliderForSettingVibratoModAmount() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->removeListener(this);
}
