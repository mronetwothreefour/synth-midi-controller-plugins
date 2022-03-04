#include "widget_voices_ButtonForImportingVoiceFromFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForImportingVoiceFromFile::ButtonForImportingVoiceFromFile(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::custom1)
		setComponentID(ID::button_ImportVoiceIntoCustomBank1.toString());
	if (bank == VoicesBank::custom2)
		setComponentID(ID::button_ImportVoiceIntoCustomBank2.toString());
	if (bank == VoicesBank::custom3)
		setComponentID(ID::button_ImportVoiceIntoCustomBank3.toString());

	setTooltip(createButtonTooltipString());
}

const String ButtonForImportingVoiceFromFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Imports the program data stored in\n";
		buttonTooltip += "a file into the selected storage slot.";
	}
	return buttonTooltip;
}

void ButtonForImportingVoiceFromFile::onClickMethod() {
}
