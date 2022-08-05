#include "widget_splits_SliderForSettingZoneLimit.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingZoneLimit::SliderForSettingZoneLimit(UnexposedParameters* unexposedParams, Identifier parameterID) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ parameterID }
{
	jassert(parameterID == ID::split_LowerZoneLimit || parameterID == ID::split_UpperZoneLimit);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	setRange(0.0, 127.0, 1.0);
	auto paramValue{ parameterID == ID::split_LowerZoneLimit ? splitOptions->lowerZoneLimit() : splitOptions->upperZoneLimit() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 0.0);
	setMouseDragSensitivity(160);
	setTooltip(generateTooltipString());
}

String SliderForSettingZoneLimit::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		if (parameterID == ID::split_LowerZoneLimit) {
			tooltipText += "The lower zone extends from this note\n";
			tooltipText += "down to C 0 (MIDI note number 0).\n";
		}
		else {
			tooltipText += "The upper zone extends from this note\n";
			tooltipText += "up to G 10 (MIDI note number 127).\n";
		}
		tooltipText += "The lower and upper zones can overlap,\n";
		tooltipText += "making it possible to play two voices\n";
		tooltipText += "at the same time. Range: C0 to G10.\n";
		tooltipText += "NOTE: Changes made to split parameters\n";
		tooltipText += "are not sent to the hardware until you\n";
		tooltipText += "SAVE the split in one of the storage\n";
		tooltipText += "bank slots below.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOscPitchString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingZoneLimit::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingZoneLimit::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToOscPitchString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingZoneLimit::~SliderForSettingZoneLimit() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
