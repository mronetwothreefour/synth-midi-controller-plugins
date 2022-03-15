#include "widget_Randomization_ButtonForUnlockingAllVoiceNameChars.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/RandomizationComponent.h"
#include "../randomization/randomization_ParamGroupLockingAndUnlockingMethods.h"



ButtonForUnlockingAllVoiceNameChars::ButtonForUnlockingAllVoiceNameChars(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Unlock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForUnlockingAllVoiceNameChars::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Unlocks all the program name characters.";
	return buttonTooltip;
}

void ButtonForUnlockingAllVoiceNameChars::onClickMethod() {
	ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVoiceNameCharacters(randomizationComponent, false);
}
