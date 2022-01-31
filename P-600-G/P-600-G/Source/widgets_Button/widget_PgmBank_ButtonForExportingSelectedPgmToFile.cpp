#include "widget_PgmBank_ButtonForExportingSelectedPgmToFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForExportingSelectedProgramToFile::ButtonForExportingSelectedProgramToFile(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_ExptSelectedProgram.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForExportingSelectedProgramToFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Exports the program data stored in the selected slot to a file\n";
		buttonTooltip += "which can be read by other instances of the P-600-G plugin.";
	}
	return buttonTooltip;
}

void ButtonForExportingSelectedProgramToFile::onClickMethod() {
}
