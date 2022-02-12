#include "widget_voices_ButtonForLoadingSelectedVoice.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ButtonForLoadingSelectedVoice::ButtonForLoadingSelectedVoice(VoiceSlotsComponent& voiceSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Load.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLoadingSelectedVoice::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Applies the program settings stored in the selected slot to the\n";
		buttonTooltip += "plugin GUI and to the Mopho hardware" + GUI::apostrophe + "s program edit buffer.";
	}
	return buttonTooltip;
}

void ButtonForLoadingSelectedVoice::onClickMethod() {
	voiceSlots.loadVoiceFromSelectedSlot();
}

