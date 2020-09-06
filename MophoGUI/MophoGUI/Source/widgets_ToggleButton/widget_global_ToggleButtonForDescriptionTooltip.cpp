#include "widget_global_ToggleButtonForDescriptionTooltip.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ToggleButtonForDescriptionTooltip::ToggleButtonForDescriptionTooltip(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::tooltips_ShouldShowDescription }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_ToggleButton.toString());
	setToggleState(tooltipOptions->shouldShowDescription(), dontSendNotification);
	setTooltip(generateTooltipString());
}

String ToggleButtonForDescriptionTooltip::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether hovering over a control with the mouse cursor will\n";
		tooltipText += "open a tooltip box showing a description of what the control does.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToShowDontShowString::get() };
		auto currentValue{ (uint8)getToggleState() };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ToggleButtonForDescriptionTooltip::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID || property == ID::tooltips_ShouldShowCurrentValue) {
		setTooltip(generateTooltipString());
	}
}

ToggleButtonForDescriptionTooltip::~ToggleButtonForDescriptionTooltip() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
