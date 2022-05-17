#include "widget_Randomization_ButtonForUnlockingAllLFOparameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllLFOparameters::ButtonForUnlockingAllLFOparameters(int lfoNum, RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllLFOparameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the parameters related to LFO " + (String)lfoNum + ".";
	return buttonTooltip;
}

void ButtonForUnlockingAllLFOparameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLFOparameters(lfoNum, randomizationComponent, false);
}
