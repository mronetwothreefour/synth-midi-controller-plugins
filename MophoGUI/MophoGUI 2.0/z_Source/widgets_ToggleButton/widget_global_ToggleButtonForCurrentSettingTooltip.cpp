#include "widget_global_ToggleButtonForCurrentSettingTooltip.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ToggleButtonForCurrentSettingTooltip::ToggleButtonForCurrentSettingTooltip(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::tooltips_ShouldShowCurrentValue }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_ToggleButton.toString());
	setToggleState(tooltipOptions->shouldShowCurrentValue(), dontSendNotification);
	setTooltip(generateTooltipString());
}

String ToggleButtonForCurrentSettingTooltip::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		tooltipText += "Selects whether hovering over a control with the mouse cursor will open\n";
		tooltipText += "a tooltip box showing a wordy version of the control" + GUI::apostrophe + "s current setting.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToShowDontShowString::get() };
		auto currentValue{ (uint8)getToggleState() };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ToggleButtonForCurrentSettingTooltip::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ToggleButtonForCurrentSettingTooltip::~ToggleButtonForCurrentSettingTooltip() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
