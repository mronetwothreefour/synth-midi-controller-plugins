#include "widget_ButtonForShowingVoicesBanksComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingVoicesBanksComponent::ButtonForShowingVoicesBanksComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Banks.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingVoicesBanksComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can manage the\n";
		buttonTooltip += "six storage voices for program presets.";
	}
	return buttonTooltip;
}

void ButtonForShowingVoicesBanksComponent::onClickMethod() {
}

