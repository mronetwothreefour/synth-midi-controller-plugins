#include "widget_global_KnobForGlobalTranspose.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



KnobForGlobalTranspose::KnobForGlobalTranspose(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_Transpose }
{
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 24.0, 1.0);
	auto paramValue{ globalAudioOptions->globalTranspose() };
	setValue((double)paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String KnobForGlobalTranspose::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToGlobalTransposeString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "All audio output from the hardware will be\n";
		tooltipText += "transposed up or down by this amount.\n";
		tooltipText += "Range: -12 to +12 semitones.";
	}
	return tooltipText;
}

void KnobForGlobalTranspose::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

KnobForGlobalTranspose::~KnobForGlobalTranspose() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->removeListener(this);
}
