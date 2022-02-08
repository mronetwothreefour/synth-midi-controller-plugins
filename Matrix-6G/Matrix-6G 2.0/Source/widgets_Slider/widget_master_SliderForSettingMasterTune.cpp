#include "widget_master_SliderForSettingMasterTune.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingMasterTune::SliderForSettingMasterTune(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 126.0, 1.0);
	auto paramValue{ (double)masterOptions->masterTune() };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 63.0);
	setMouseDragSensitivity(143);
	setTooltip(generateTooltipString());
}

String SliderForSettingMasterTune::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Tunes all audio output from the hardware\n";
		tooltipText += "up or down. Range: -63 to +63, which represents\n";
		tooltipText += " +/- one quarter tone. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hardware.\n";
		tooltipText += "Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToSigned7bitValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingMasterTune::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::master_Tune) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingMasterTune::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToSigned7bitValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingMasterTune::~SliderForSettingMasterTune() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
