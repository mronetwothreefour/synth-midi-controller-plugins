#include "widget_ButtonForShowingGlobalParametersComponent.h"

#include "widget_ButtonForShowingProgramBanksComponent.h"

#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingGlobalParametersComponent::ButtonForShowingGlobalParametersComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "GLOBAL", unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingGlobalParametersComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can change global settings\n";
		buttonTooltip += "for the hardware, as well as tooltip display options";
	}
	return buttonTooltip;
}

void ButtonForShowingGlobalParametersComponent::onClickMethod() {
}

ButtonForShowingGlobalParametersComponent::~ButtonForShowingGlobalParametersComponent() {
}
