#include "widget_ButtonForShowingPatchBanksComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingPatchBanksComponent::ButtonForShowingPatchBanksComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Patches.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingPatchBanksComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens a window where you can manage\n";
		buttonTooltip += "the patch presets storage banks.";
	}
	return buttonTooltip;
}

void ButtonForShowingPatchBanksComponent::onClickMethod() {
}
