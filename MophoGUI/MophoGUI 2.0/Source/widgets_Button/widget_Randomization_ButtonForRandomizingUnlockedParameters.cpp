#include "widget_Randomization_ButtonForRandomizingUnlockedParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"



ButtonForRandomizingUnlockedParameters::ButtonForRandomizingUnlockedParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Randomize.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForRandomizingUnlockedParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Click to assign random values to each\n";
		buttonTooltip += "of the unlocked program parameters.";
	}
	return buttonTooltip;
}

void ButtonForRandomizingUnlockedParameters::onClickMethod() {
	randomizationComponent->randomizeUnlockedParameters();
}
