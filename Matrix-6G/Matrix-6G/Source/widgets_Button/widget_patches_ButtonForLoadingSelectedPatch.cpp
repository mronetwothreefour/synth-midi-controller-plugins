#include "widget_patches_ButtonForLoadingSelectedPatch.h"

#include "../patches/patches_Constants.h"
#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



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
	auto slot{ patchSlots.selectedSlot };
	if (slot < patches::numberOfSlotsInBank) {
		patchSlots.loadPatchFromSelectedSlot();
		auto patchTransmissionOptions{ unexposedParams->patchTransmissionOptions_get() };
		auto transmitTime{ patchTransmissionOptions->patchTransmitTime() };
		callAfterDelay(transmitTime, [this, slot]
			{
				auto masterOptions{ unexposedParams->masterOptions_get() };
				auto basicChannel{ masterOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, slot);
			}
		);
	}
}

void ButtonForLoadingSelectedPatch::timerCallback() {
}
