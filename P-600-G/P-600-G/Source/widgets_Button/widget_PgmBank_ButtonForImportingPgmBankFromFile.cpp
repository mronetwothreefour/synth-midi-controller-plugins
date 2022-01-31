#include "widget_PgmBank_ButtonForImportingPgmBankFromFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForImportingProgramBankFromFile::ButtonForImportingProgramBankFromFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_ImptBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForImportingProgramBankFromFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Replace all the programs in the storage\n";
		buttonTooltip += "bank with those stored in a file.";
	}
	return buttonTooltip;
}

void ButtonForImportingProgramBankFromFile::onClickMethod() {
}
