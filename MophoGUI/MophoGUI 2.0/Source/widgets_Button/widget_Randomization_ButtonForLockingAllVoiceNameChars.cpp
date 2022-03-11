#include "widget_Randomization_ButtonForLockingAllVoiceNameChars.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../randomization/randomizationComponent.h"



ButtonForLockingAllVoiceNameChars::ButtonForLockingAllVoiceNameChars(RandomizationComponent* randomizationComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	randomizationComponent{ randomizationComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Lock.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLockingAllVoiceNameChars::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions())
		buttonTooltip += "Locks all the program name characters.";
	return buttonTooltip;
}

void ButtonForLockingAllVoiceNameChars::onClickMethod() {
	randomizationComponent->lockAllVoiceNameCharacters();
}
