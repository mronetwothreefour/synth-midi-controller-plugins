#include "widget_ButtonForPullingProgramFromHardwareStorageSlot.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;





ButtonForPullingProgramFromHardwareStorageSlot::ButtonForPullingProgramFromHardwareStorageSlot(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PullSelectedVoice.toString());
}

const String ButtonForPullingProgramFromHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Pull the data from a program storage slot in the\n";
		buttonTooltip += "Prophet-600 hardware (specified by the program number\n";
		buttonTooltip += "control to the left) and apply it to the plugin GUI.";
	}
	return buttonTooltip;
}

void ButtonForPullingProgramFromHardwareStorageSlot::onClickMethod() {
	auto currentPgmOptions{ unexposedParams->voiceTransmissionOptions_get() };
	auto slot{ currentPgmOptions->currentVoiceNumber() };
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(slot, outgoingMidiBuffers);
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
	callAfterDelay(transmitTime, [this, slot]
		{
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, slot);
		}
	);
}

void ButtonForPullingProgramFromHardwareStorageSlot::timerCallback() {
}
