#include "widget_voices_ButtonForPullingSelectedVoiceFromHardware.h"

#include "../voices/voices_Constants.h"
#include "../voices/voices_VoicesBanks.h"
#include "../voices/voices_VoiceSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForPullingSelectedVoiceFromHardware::ButtonForPullingSelectedVoiceFromHardware(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullSelectedVoiceOrSplit.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedVoiceFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected patch storage slot in\n";
		buttonTooltip += "the Matrix-6R hardware and save it in the corresponding\n";
		buttonTooltip += "slot in this plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedVoiceFromHardware::onClickMethod() {
	auto slot{ voiceSlots.selectedSlot };
	if (slot < voices::numberOfSlotsInBank && (voiceSlots.bank == VoicesBank::customA || voiceSlots.bank == VoicesBank::customB)) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		if (voiceSlots.bank == VoicesBank::customA)
			voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInCustomBankA();
		else
			voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInCustomBankB();
		voiceSlots.pullSelectedVoiceFromHardware();
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this, slot]
			{
				auto masterOptions{ unexposedParams->globalOptions_get() };
				auto basicChannel{ masterOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, slot);
			}
		);
	}
}

void ButtonForPullingSelectedVoiceFromHardware::timerCallback() {
}
