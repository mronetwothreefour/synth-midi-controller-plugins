#include "widget_ButtonForShowingProgramBanksComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingProgramBanksComponent::ButtonForShowingProgramBanksComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Banks.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingProgramBanksComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can manage the\n";
		buttonTooltip += "three storage banks for program presets.";
	}
	return buttonTooltip;
}

void ButtonForShowingProgramBanksComponent::onClickMethod() {
}

