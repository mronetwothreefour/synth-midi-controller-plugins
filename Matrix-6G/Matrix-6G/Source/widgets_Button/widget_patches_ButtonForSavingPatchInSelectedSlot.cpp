#include "widget_patches_ButtonForSavingPatchInSelectedSlot.h"

#include "../patches/patches_Constants.h"
#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForSavingPatchInSelectedSlot::ButtonForSavingPatchInSelectedSlot(PatchSlotsComponent& patchSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	patchSlots{ patchSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Save.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSavingPatchInSelectedSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Saves the plugin GUI's current settings\n";
		buttonTooltip += "in the selected patch storage slot, both\n";
		buttonTooltip += "in this storage bank and in the Matrix-6R\n";
		buttonTooltip += "hardware. NOTE: This will overwrite the data\n";
		buttonTooltip += "stored in the hardware and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForSavingPatchInSelectedSlot::onClickMethod() {
	if (patchSlots.selectedSlot < patches::numberOfSlotsInBank) {
		patchSlots.storeCurrentPatchSettingsInSelectedSlot();
		auto patchTransmissionOptions{ unexposedParams->patchTransmissionOptions_get() };
		auto transmitTime{ patchTransmissionOptions->patchTransmitTime() };
		callAfterDelay(transmitTime, [this]
			{
				auto masterOptions{ unexposedParams->masterOptions_get() };
				auto basicChannel{ masterOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, (int)patchSlots.selectedSlot);
			}
		);
	}
}

void ButtonForSavingPatchInSelectedSlot::timerCallback() {
}
