#include "widget_patches_ButtonForLoadingSelectedPatch.h"

#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForLoadingSelectedPatch::ButtonForLoadingSelectedPatch(PatchSlotsComponent& patchSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	patchSlots{ patchSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Load.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLoadingSelectedPatch::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Loads the patch settings stored in the selected slot into the plugin GUI\n";
		buttonTooltip += "and pushes it into the corresponding slot on the hardware. NOTE: This will\n";
		buttonTooltip += "overwrite the patch data in the hardware storage slot and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForLoadingSelectedPatch::onClickMethod() {
	patchSlots.loadPatchFromSelectedSlot();
	auto midiOptions{ unexposedParams->midiOptions_get() };
	auto transmitTime{ midiOptions->patchTransmitTime() };
	callAfterDelay(transmitTime, [this, midiOptions]
		{
			auto basicChannel{ midiOptions->basicChannel() };
			auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
			auto patchSlot{ currentPatchOptions->currentPatchNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addPatchSelectMessage(basicChannel, patchSlot);
		}
	);
}

void ButtonForLoadingSelectedPatch::timerCallback() {
}
