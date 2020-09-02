#include "widget_global_ToggleButtonForStereoOutput.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ToggleButtonForStereoOutput::ToggleButtonForStereoOutput(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_HardwareOutputIsStereo }
{
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_ToggleButton.toString());
	setToggleState(globalAudioOptions->hardwareOutputIsStereo(), dontSendNotification);
	setTooltip(generateTooltipString());
}

String ToggleButtonForStereoOutput::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToMonoStereoString::get() };
		auto currentValue{ (uint8)getToggleState() };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether the hardware's\n";
		tooltipText += "audio output is mono or stereo.";
	}
	return tooltipText;
}

void ToggleButtonForStereoOutput::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setToggleState((bool)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ToggleButtonForStereoOutput::~ToggleButtonForStereoOutput() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->removeListener(this);
}
