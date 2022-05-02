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
		buttonTooltip += "Click to randomize the program settings. CTRL-click\n";
		buttonTooltip += "this button to open a dialog where you can restrict\n";
		buttonTooltip += "which parameters get randomized and what settings are\n";
		buttonTooltip += "allowed for each of them. Right-click any program par-\n";
		buttonTooltip += "ameter control to set it to a random value.";
	}
	return buttonTooltip;
}

void ButtonForRandomizingAndShowingRandomizationComponent::onClickMethod() {
}
