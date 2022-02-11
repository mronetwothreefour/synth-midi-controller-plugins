#include "widget_banks_ButtonForPushingSelectedProgramToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsWidget.h"



ButtonForPushingSelectedProgramToHardware::ButtonForPushingSelectedProgramToHardware(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	programSlots{ programSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PushSelectedVoice.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingSelectedProgramToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push the data in the selected program storage slot\n";
		buttonTooltip += "to the corresponding storage slot in the Mopho hardware.";
	}
	return buttonTooltip;
}

void ButtonForPushingSelectedProgramToHardware::onClickMethod() {
	programSlots.pushSelectedProgramToHardware();
}

