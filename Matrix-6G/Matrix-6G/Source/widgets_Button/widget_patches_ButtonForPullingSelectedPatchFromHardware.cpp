#include "widget_patches_ButtonForPullingSelectedPatchFromHardware.h"

#include "../patches/patches_Constants.h"
#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForPullingSelectedPatchFromHardware::ButtonForPullingSelectedPatchFromHardware(PatchSlotsComponent& patchSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	patchSlots{ patchSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullSelectedPatchOrSplit.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedPatchFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected patch storage slot in\n";
		buttonTooltip += "the Matrix-6R hardware and save it in the corresponding\n";
		buttonTooltip += "slot in this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedPatchFromHardware::onClickMethod() {
	auto slot{ patchSlots.selectedSlot };
	if (slot < patches::numberOfSlotsInBank && (patchSlots.bank == PatchBank::customA || patchSlots.bank == PatchBank::customB)) {
		auto patchTransmissionOptions{ unexposedParams->patchTransmissionOptions_get() };
		if (patchSlots.bank == PatchBank::customA)
			patchTransmissionOptions->setIncomingPatchShouldBeSavedInCustomBankA();
		else
			patchTransmissionOptions->setIncomingPatchShouldBeSavedInCustomBankB();
		patchSlots.pullSelectedPatchFromHardware();
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

void ButtonForPullingSelectedPatchFromHardware::timerCallback() {
}
