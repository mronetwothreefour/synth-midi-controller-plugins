#include "widget_voices_ButtonForExportingSelectedVoiceToFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForExportingSelectedVoiceToFile::ButtonForExportingSelectedVoiceToFile(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::custom1)
		setComponentID(ID::button_ExportVoiceFromCustomBank1.toString());
	if (bank == VoicesBank::custom2)
		setComponentID(ID::button_ExportVoiceFromCustomBank2.toString());
	if (bank == VoicesBank::custom3)
		setComponentID(ID::button_ExportVoiceFromCustomBank3.toString());

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
