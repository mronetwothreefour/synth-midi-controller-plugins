#include "widget_patches_ButtonForPullingSelectedPatchFromHardware.h"

#include "../patches/patches_Constants.h"
#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForPullingSelectedPatchFromHardware::ButtonForPullingSelectedPatchFromHardware(VoiceSlotsComponent& patchSlots, UnexposedParameters* unexposedParams) :
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
	if (slot < voices::numberOfSlotsInBank && (patchSlots.bank == VoicesBank::customA || patchSlots.bank == VoicesBank::customB)) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		if (patchSlots.bank == VoicesBank::customA)
			voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInCustomBankA();
		else
			voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInCustomBankB();
		patchSlots.pullSelectedVoiceFromHardware();
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
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
