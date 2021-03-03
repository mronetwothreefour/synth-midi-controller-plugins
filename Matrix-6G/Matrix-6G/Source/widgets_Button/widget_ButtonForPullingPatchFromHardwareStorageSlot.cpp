#include "widget_ButtonForPullingPatchFromHardwareStorageSlot.h"

#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForPullingPatchFromHardwareStorageSlot::ButtonForPullingPatchFromHardwareStorageSlot(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PullSelectedPatchOrSplit.toString());
}

const String ButtonForPullingPatchFromHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected patch storage slot in\n";
		buttonTooltip += "the Matrix-6R hardware and apply it to the plugin GUI.";
	}
	return buttonTooltip;
}

void ButtonForPullingPatchFromHardwareStorageSlot::onClickMethod() {
	auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
	auto slot{ currentPatchOptions->currentPatchNumber() };
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	PatchDataMessage::addRequestForPatchDataStoredInHardwareSlotToOutgoingMidiBuffers(slot, outgoingMidiBuffers);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	auto transmitTime{ midiOptions->patchTransmitTime() };
	callAfterDelay(transmitTime, [this, slot, midiOptions] 
		{
			auto basicChannel{ midiOptions->basicChannel() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(basicChannel, slot);
		}
	);
}

void ButtonForPullingPatchFromHardwareStorageSlot::timerCallback() {
}
