#include "widget_ButtonForShowingProgramBankComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingProgramBankComponent::ButtonForShowingProgramBankComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PgmBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingProgramBankComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Opens a window where you can\n";
		buttonTooltip += "load and store program presets.";
	}
	return buttonTooltip;
}

void ButtonForShowingProgramBankComponent::onClickMethod() {
}
