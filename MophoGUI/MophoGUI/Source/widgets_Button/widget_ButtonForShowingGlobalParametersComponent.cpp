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
		buttonTooltip += "Opens a window where you can change the Mopho's global parameter settings.\n";
		buttonTooltip += "WARNING: Some of these options can disrupt communication between this\n";
		buttonTooltip += "plugin and the hardware, so be very careful when making changes to them!";
	}
	return buttonTooltip;
}

void ButtonForShowingGlobalParametersComponent::onClickMethod() {
}

ButtonForShowingGlobalParametersComponent::~ButtonForShowingGlobalParametersComponent() {
}
