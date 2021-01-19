#include "widget_patches_ButtonForPullingSelectedPatchFromHardware.h"

#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingSelectedPatchFromHardware::ButtonForPullingSelectedPatchFromHardware(PatchSlotsComponent& patchSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	patchSlots{ patchSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullSelectedPatch.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedPatchFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected program storage slot in the Matrix-6R hardware\n";
		buttonTooltip += "and save it in the corresponding storage slot in this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedPatchFromHardware::onClickMethod() {
	patchSlots.pullSelectedPatchFromHardware();
}
