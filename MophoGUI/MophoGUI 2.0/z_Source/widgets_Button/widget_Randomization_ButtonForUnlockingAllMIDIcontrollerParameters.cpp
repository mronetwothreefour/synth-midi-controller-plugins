#include "widget_Randomization_ButtonForUnlockingAllMIDIcontrollerParameters.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllMIDIcontrollerParameters::ButtonForUnlockingAllMIDIcontrollerParameters(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllMIDIcontrollerParameters::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Unlocks all the parameters\n";
		buttonTooltip += "related to MIDI controllers.";
	}
	return buttonTooltip;
}

void ButtonForUnlockingAllMIDIcontrollerParameters::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllMIDIcontrollerParameters(randomizationComponent, false);
}
