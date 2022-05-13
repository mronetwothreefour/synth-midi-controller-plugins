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
		buttonTooltip += "Click to randomize the program settings. Right-click\n";
		buttonTooltip += "to open a dialog where you can define which parameters\n";
		buttonTooltip += "get randomized and what values are allowed for each\n";
		buttonTooltip += "of them. Right-click any program parameter control to\n";
		buttonTooltip += "assign it a random value.";
	}
	return buttonTooltip;
}

void ButtonForRandomizingAndShowingRandomizationComponent::onClickMethod() {
}
