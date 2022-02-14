#include "widget_ButtonForShowingVoicesBankComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingVoicesBankComponent::ButtonForShowingVoicesBankComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_VoicesBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingVoicesBankComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a window where you can\n";
		buttonTooltip += "load and store program presets.";
	}
	return buttonTooltip;
}

void ButtonForShowingVoicesBankComponent::onClickMethod() {
}
