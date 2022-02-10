#include "widget_ButtonForPullingPatchFromHardwareStorageSlot.h"

#include "../midi/midi_VoiceDataMessage.h"
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
	auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
	auto slot{ currentVoiceOptions->currentVoiceNumber() };
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(slot, outgoingMidiBuffers);
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
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

void ButtonForPullingPatchFromHardwareStorageSlot::timerCallback() {
}
