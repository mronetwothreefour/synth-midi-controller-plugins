#include "widget_global_KnobForGlobalFineTune.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



KnobForGlobalFineTune::KnobForGlobalFineTune(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_FineTune }
{
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 100.0, 1.0);
	auto paramValue{ globalAudioOptions->globalFineTune() };
	setValue((double)paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String KnobForGlobalFineTune::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToFineTuneString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "All audio output from the hardware will\n";
		tooltipText += "be tuned up or down by this amount.\n";
		tooltipText += "Range: -50 to +50 cents.";
	}
	return tooltipText;
}

void KnobForGlobalFineTune::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

KnobForGlobalFineTune::~KnobForGlobalFineTune() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->removeListener(this);
}
