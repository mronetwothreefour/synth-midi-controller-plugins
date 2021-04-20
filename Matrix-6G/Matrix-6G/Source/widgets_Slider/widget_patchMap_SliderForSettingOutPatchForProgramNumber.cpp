#include "widget_patchMap_SliderForSettingOutPatchForProgramNumber.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingOutPatchForProgramNumber::SliderForSettingOutPatchForProgramNumber(UnexposedParameters* unexposedParams, uint8 programNumber) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	programNumber{ programNumber },
	sliderID{ "master_PatchMapOut_" + (String)programNumber }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ (double)masterOptions->patchMapOutPatchForProgramNumber(programNumber) };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, (double)programNumber);
	setMouseDragSensitivity(130);
	setTooltip(generateTooltipString());
}

String SliderForSettingOutPatchForProgramNumber::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When the Patch Map and Patch Map Echo are both enabled\n";
		tooltipText += "and a MIDI program change message calling program " + (String)programNumber + " is\n";
		tooltipText += "received, the hardware will send out a new program change\n";
		tooltipText += "message to downstream devices calling this program instead.\n";
		tooltipText += "NOTE: Changes to the Patch Map will not be updated on the\n";
		tooltipText += "hardware until the PUSH button in the Master window is clicked.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: Program ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingOutPatchForProgramNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == sliderID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingOutPatchForProgramNumber::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingOutPatchForProgramNumber::~SliderForSettingOutPatchForProgramNumber() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
