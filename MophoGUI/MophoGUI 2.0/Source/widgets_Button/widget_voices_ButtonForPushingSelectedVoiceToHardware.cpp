#include "widget_voices_ButtonForPushingSelectedVoiceToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"



ButtonForPushingSelectedVoiceToHardware::ButtonForPushingSelectedVoiceToHardware(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PushSelectedVoice.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingSelectedVoiceToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push the data in the selected program storage slot\n";
		buttonTooltip += "to the corresponding storage slot in the Mopho hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingSelectedVoiceToHardware::onClickMethod() {
	voiceSlots.pushSelectedVoiceToHardware();
}

