#include "widget_splits_SliderForSettingZoneVoiceNumber.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingZoneVoiceNumber::SliderForSettingZoneVoiceNumber(UnexposedParameters* unexposedParams, Identifier parameterID) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ parameterID }
{
	jassert(parameterID == ID::split_LowerZoneVoiceNumber || parameterID == ID::split_UpperZoneVoiceNumber);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ parameterID == ID::split_LowerZoneVoiceNumber ? splitOptions->lowerZoneVoiceNumber() : splitOptions->upperZoneVoiceNumber() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 0.0);
	setMouseDragSensitivity(160);
	setTooltip(generateTooltipString());
}

String SliderForSettingZoneVoiceNumber::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects which patch will be played by the\n";
		if (parameterID == ID::split_LowerZoneVoiceNumber)
			tooltipText += "lower zone (the left side of the keyboard).\n";
		else
			tooltipText += "upper zone (the right side of the keyboard).\n";
		tooltipText += "Range: 0 to 99. NOTE: Changes made to\n";
		tooltipText += "split parameters are not sent to the hard-\n";
		tooltipText += "ware until you SAVE the split in one of\n";
		tooltipText += "the storage bank slots below.";
	}
	return tooltipText;
}

void SliderForSettingZoneVoiceNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
	}
}

void SliderForSettingZoneVoiceNumber::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueWithLeadingZeroString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingZoneVoiceNumber::~SliderForSettingZoneVoiceNumber() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
