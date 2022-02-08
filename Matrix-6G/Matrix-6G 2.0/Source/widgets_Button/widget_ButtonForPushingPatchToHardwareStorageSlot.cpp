#include "widget_ButtonForPushingPatchToHardwareStorageSlot.h"

#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




ButtonForPushingPatchToHardwareStorageSlot::ButtonForPushingPatchToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_Push.toString());
}

const String ButtonForPushingPatchToHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Sends a dump of all the patch data to the hardware storage\n";
		buttonTooltip += "slot specified by the patch number control to the right,\n";
		buttonTooltip += "overwriting the data that is currently stored in the slot.";
	}
	return buttonTooltip;
}

void ButtonForPushingPatchToHardwareStorageSlot::onClickMethod() {
	PatchDataMessage::addDataMessageForCurrentPatchToOutgoingMidiBuffers(exposedParams, unexposedParams);
	callAfterDelay(10, [this]
		{
			auto masterOptions{ unexposedParams->masterOptions_get() };
			auto basicChannel{ masterOptions->basicChannel() };
			auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
			auto patchSlot{ currentPatchOptions->currentPatchNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(basicChannel, patchSlot);
		}
	);
}

void ButtonForPushingPatchToHardwareStorageSlot::timerCallback() {
}
