#include "widget_patches_ButtonForPullingSelectedPatchFromHardware.h"

#include "../patches/patches_Constants.h"
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
		buttonTooltip += "Pull the data from the selected patch storage slot in\n";
		buttonTooltip += "the Matrix-6R hardware and save it in the corresponding\n";
		buttonTooltip += "storage slot in this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedPatchFromHardware::onClickMethod() {
	if (patchSlots.bank == PatchBank::customA || patchSlots.bank == PatchBank::customB) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (patchSlots.bank == PatchBank::customA)
			midiOptions->setIncomingPatchShouldBeSavedInCustomBankA();
		else
			midiOptions->setIncomingPatchShouldBeSavedInCustomBankB();
	}
	patchSlots.pullSelectedPatchFromHardware();
}
