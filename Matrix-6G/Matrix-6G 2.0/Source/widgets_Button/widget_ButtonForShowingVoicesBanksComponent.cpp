#include "widget_ButtonForShowingVoicesBanksComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingVoicesBanksComponent::ButtonForShowingVoicesBanksComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Voices.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingVoicesBanksComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can manage\n";
		buttonTooltip += "the patch presets storage banks.";
	}
	return buttonTooltip;
}

void ButtonForShowingVoicesBanksComponent::onClickMethod() {
}
