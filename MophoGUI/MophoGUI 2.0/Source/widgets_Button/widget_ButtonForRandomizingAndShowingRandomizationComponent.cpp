#include "widget_ButtonForRandomizingAndShowingRandomizationComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForRandomizingAndShowingRandomizationComponent::ButtonForRandomizingAndShowingRandomizationComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Randomize.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForRandomizingAndShowingRandomizationComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Click to randomize the program settings. CTRL-click to\n";
		buttonTooltip += "open a dialog where you can restrict which parameters\n";
		buttonTooltip += "are randomized and what settings are allowed.";
	}
	return buttonTooltip;
}

void ButtonForRandomizingAndShowingRandomizationComponent::onClickMethod() {
}
