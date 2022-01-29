#include "widget_PgmBank_ButtonForExportingPgmBankToFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForExportingProgramBankToFile::ButtonForExportingProgramBankToFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_ExptBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForExportingProgramBankToFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Exports the data for all the programs in the storage bank to a\n";
		buttonTooltip += "file which can be read by other instances of the P-600-G plugin.";
	}
	return buttonTooltip;
}

void ButtonForExportingProgramBankToFile::onClickMethod() {
}
