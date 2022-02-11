#include "widget_voices_ButtonForPullingSelectedVoiceFromHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"



ButtonForPullingSelectedVoiceFromHardware::ButtonForPullingSelectedVoiceFromHardware(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullSelectedVoice.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedVoiceFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected program storage slot in the Mopho hardware\n";
		buttonTooltip += "and save it in the corresponding storage slot in the plugin.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedVoiceFromHardware::onClickMethod() {
	voiceSlots.pullSelectedVoiceFromHardware();
}

