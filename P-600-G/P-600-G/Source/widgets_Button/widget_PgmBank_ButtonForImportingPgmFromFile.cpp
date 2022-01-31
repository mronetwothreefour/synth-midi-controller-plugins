#include "widget_PgmBank_ButtonForImportingPgmFromFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForImportingProgramFromFile::ButtonForImportingProgramFromFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_ImptSelectedProgram.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForImportingProgramFromFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Imports the program data stored in\n";
		buttonTooltip += "a file into the selected storage slot.";
	}
	return buttonTooltip;
}

void ButtonForImportingProgramFromFile::onClickMethod() {
}
