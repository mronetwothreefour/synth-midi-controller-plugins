#include "widget_patchMap_SliderForSettingInPatchForProgramNumber.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingInPatchForProgramNumber::SliderForSettingInPatchForProgramNumber(UnexposedParameters* unexposedParams, uint8 programNumber) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	programNumber{ programNumber },
	sliderID{ "master_PatchMapIn_" + (String)programNumber }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ (double)masterOptions->patchMapInPatchForProgramNumber(programNumber) };
	setValue(paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, (double)programNumber);
	setMouseDragSensitivity(130);
	setTooltip(generateTooltipString());
}

String SliderForSettingInPatchForProgramNumber::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When the Patch Map is enabled, a MIDI program change\n";
		tooltipText += "message calling program " + (String)programNumber + " will load the patch selected\n";
		tooltipText += "here into tha hardware instead. NOTE: Changes to the\n";
		tooltipText += "Patch Map will not be updated on the hardware until\n";
		tooltipText += "the PUSH button in the Master window is clicked.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToUnsignedValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: Patch ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingInPatchForProgramNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == sliderID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
}

void SliderForSettingInPatchForProgramNumber::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForSettingInPatchForProgramNumber::~SliderForSettingInPatchForProgramNumber() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
