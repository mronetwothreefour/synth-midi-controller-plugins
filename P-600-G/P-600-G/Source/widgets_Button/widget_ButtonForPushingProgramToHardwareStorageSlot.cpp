#include "widget_ButtonForPushingProgramToHardwareStorageSlot.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPushingProgramToHardwareStorageSlot::ButtonForPushingProgramToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PushSelectedVoice.toString());
}

const String ButtonForPushingProgramToHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Sends a dump of all the program data to the hardware\n";
		buttonTooltip += "storage slot specified by the program number control\n";
		buttonTooltip += "to the left. NOTE: This overwrites the data that is\n";
		buttonTooltip += "currently stored in the slot and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForPushingProgramToHardwareStorageSlot::onClickMethod() {
	VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams);
	callAfterDelay(10, [this]
		{
			auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
			auto pgmSlot{ voiceTransmissionOptions->currentVoiceNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, pgmSlot);
		}
	);
}

void ButtonForPushingProgramToHardwareStorageSlot::timerCallback() {
}
