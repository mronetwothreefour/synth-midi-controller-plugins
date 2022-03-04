#include "widget_voices_ButtonForExportingSelectedVoiceToFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForExportingSelectedVoiceToFile::ButtonForExportingSelectedVoiceToFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Export.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForExportingSelectedVoiceToFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Exports the program data stored in the selected slot to a file\n";
		buttonTooltip += "which can be read by other instances of the MophoGUI plugin.";
	}
	return buttonTooltip;
}

void ButtonForExportingSelectedVoiceToFile::onClickMethod() {
}
