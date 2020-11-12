#include "widget_SliderForPatchNumber.h"

#include "../gui/gui_Colors.h"
#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForPatchNumber::SliderForPatchNumber(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::currentPatch_Number }
{
	auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
	currentPatchOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ currentPatchOptions->currentPatchNumber() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 0.0);
	setMouseDragSensitivity(160);
	setTooltip(generateTooltipString());
}

String SliderForPatchNumber::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the storage slot on the hardware\n";
		tooltipText += "that the patch settings will be sent to when\n";
		tooltipText += "the Send All button (left) is clicked.\n";
		tooltipText += "Range: 0 to 99.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForPatchNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void SliderForPatchNumber::paint(Graphics& g) {
	g.fillAll(Color::black);
	auto currentValue{ (int8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueWithLeadingZeroString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForPatchNumber::~SliderForPatchNumber() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
	currentPatchOptions->removeListener(this);
}
