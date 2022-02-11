#include "widget_voices_ButtonForSavingVoiceIntoSelectedSlot.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ButtonForSavingVoiceIntoSelectedSlot::ButtonForSavingVoiceIntoSelectedSlot(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Save.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSavingVoiceIntoSelectedSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Saves the plugin GUI" + GUI::apostrophe + "s current settings\n";
		buttonTooltip += "into the selected program storage slot.";
	}
	return buttonTooltip;
}

void ButtonForSavingVoiceIntoSelectedSlot::onClickMethod() {
	voiceSlots.saveCurrentVoiceSettingsIntoSelectedSlot();
}

