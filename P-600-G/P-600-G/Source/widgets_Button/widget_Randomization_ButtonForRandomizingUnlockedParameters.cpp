#include "widget_Randomization_ButtonForRandomizingUnlockedParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/randomizationComponent.h"



ButtonForRandomizingUnlockedParameters::ButtonForRandomizingUnlockedParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_OKrandomization.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForRandomizingUnlockedParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Click to assign random values to each of the unlocked\n";
		buttonTooltip += "program parameters. NOTE: This will overwrite the\n";
		buttonTooltip += "program data stored in the selected slot on the\n";
		buttonTooltip += "Prophet-600 hardware and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForRandomizingUnlockedParameters::onClickMethod() {
	randomizationComponent->randomizeUnlockedParameters();
}
