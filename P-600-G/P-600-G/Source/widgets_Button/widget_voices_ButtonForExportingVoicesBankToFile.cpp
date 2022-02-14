#include "widget_voices_ButtonForExportingVoicesBankToFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForExportingVoicesBankToFile::ButtonForExportingVoicesBankToFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_ExptBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForExportingVoicesBankToFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Exports the data for all the programs in the storage bank to a\n";
		buttonTooltip += "file which can be read by other instances of the P-600-G plugin.";
	}
	return buttonTooltip;
}

void ButtonForExportingVoicesBankToFile::onClickMethod() {
}
