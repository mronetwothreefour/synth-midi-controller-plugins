#include "widget_ButtonForShowingTipsComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForShowingTipsComponent::ButtonForShowingTipsComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Tips.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingTipsComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a window where you can set\n";
		buttonTooltip += "display options for control tooltips.";
	}
	return buttonTooltip;
}

void ButtonForShowingTipsComponent::onClickMethod() {
}
