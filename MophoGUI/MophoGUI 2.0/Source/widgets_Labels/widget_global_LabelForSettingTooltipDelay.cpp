#include "widget_global_LabelForSettingTooltipDelay.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



LabelForSettingTooltipDelay::LabelForSettingTooltipDelay(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::tooltips_DelayInMilliseconds }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_EditLabel.toString());
	setEditable(true);
	setText((String)tooltipOptions->delayInMilliseconds() + " ms", dontSendNotification);
	setTooltip(generateTooltipString());
}

String LabelForSettingTooltipDelay::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the amount of time (in milliseconds) the mouse cursor\n";
		tooltipText += "must hover over a control before a tooltip box is shown.\n";
		tooltipText += "Maximum delay: 5000 ms.";
	}
	return tooltipText;
}

void LabelForSettingTooltipDelay::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

LabelForSettingTooltipDelay::~LabelForSettingTooltipDelay() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
