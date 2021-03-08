#include "widget_matrixMod_SliderForSettingAmountForMod.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingAmountForMatrixMod::SliderForSettingAmountForMatrixMod(UnexposedParameters* unexposedParams, int modNumber) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ "matrixMod_AmountForMod_" + (String)modNumber }
{
	auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
	matrixModSettings->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 127.0, 1.0);
	auto paramValue{ matrixModSettings->amountSettingForModulation(modNumber) };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 63.0);
	setMouseDragSensitivity(170);
	setTooltip(generateTooltipString());
}

String SliderForSettingAmountForMatrixMod::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets whether and to what degree the selected source\n";
		tooltipText += "modulates the selected destination. Matrix Mod\n";
		tooltipText += "settings cannot be changed via Quick Edit. Use the\n";
		tooltipText += "Push button (below the logo) to send the entire\n";
		tooltipText += "patch to the selected storage slot on the hardware.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToSigned7bitValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingAmountForMatrixMod::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingAmountForMatrixMod::paint(Graphics& g) {
	auto currentValue{ (int8)roundToInt(getValue()) };
	auto converter{ IntToSigned7bitValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingAmountForMatrixMod::~SliderForSettingAmountForMatrixMod() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
	matrixModSettings->removeListener(this);
}
