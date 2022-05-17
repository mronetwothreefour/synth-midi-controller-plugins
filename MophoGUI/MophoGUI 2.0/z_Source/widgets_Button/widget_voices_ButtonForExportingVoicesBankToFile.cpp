#include "widget_voices_ButtonForExportingVoicesBankToFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForExportingVoicesBankToFile::ButtonForExportingVoicesBankToFile(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::custom1)
		setComponentID(ID::button_ExportCustomBank1.toString());
	if (bank == VoicesBank::custom2)
		setComponentID(ID::button_ExportCustomBank2.toString());
	if (bank == VoicesBank::custom3)
		setComponentID(ID::button_ExportCustomBank3.toString());

	setTooltip(createButtonTooltipString());
}

const String ButtonForExportingVoicesBankToFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Exports the data for all the programs in the storage bank to a\n";
		buttonTooltip += "file which can be read by other instances of the MophoGUI plugin.";
	}
	return buttonTooltip;
}

void ButtonForExportingVoicesBankToFile::onClickMethod() {
}
