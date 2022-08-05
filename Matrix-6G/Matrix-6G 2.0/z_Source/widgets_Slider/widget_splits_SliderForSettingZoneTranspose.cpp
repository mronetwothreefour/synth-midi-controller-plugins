#include "widget_splits_SliderForSettingZoneTranspose.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingZoneTranspose::SliderForSettingZoneTranspose(UnexposedParameters* unexposedParams, Identifier parameterID) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ parameterID }
{
	jassert(parameterID == ID::split_LowerZoneTranspose || parameterID == ID::split_UpperZoneTranspose);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	setRange(0.0, 60.0, 1.0);
	auto paramValue{ parameterID == ID::split_LowerZoneTranspose ? splitOptions->lowerZoneTranspose() : splitOptions->upperZoneTranspose() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 36.0);
	setMouseDragSensitivity(110);
	setTooltip(generateTooltipString());
}

String SliderForSettingZoneTranspose::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		
		tooltipText += "Raises or lowers the pitch of all notes\n";
		tooltipText += "in this zone in semitone increments.\n";
		tooltipText += "Range: -36 (lowered by 3 octaves) to\n";
		tooltipText += "+24 (raised by 2 octaves).\n";
		tooltipText += "NOTE: Changes made to split parame-\n";
		tooltipText += "ters are not sent to the hardware\n";
		tooltipText += "until you SAVE the split in one of\n";
		tooltipText += "the storage bank slots below.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToZoneTranspose::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingZoneTranspose::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingZoneTranspose::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToZoneTranspose::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingZoneTranspose::~SliderForSettingZoneTranspose() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
