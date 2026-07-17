#include "widget_voices_ButtonForImportingVoiceFromFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForImportingVoiceFromFile::ButtonForImportingVoiceFromFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_ImptSelectedVoice.toString());
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
