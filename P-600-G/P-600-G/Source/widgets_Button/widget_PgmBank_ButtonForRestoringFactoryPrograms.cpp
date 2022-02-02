#include "widget_PgmBank_ButtonForRestoringFactoryPrograms.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForRestoringFactoryPrograms::ButtonForRestoringFactoryPrograms(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Fact.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForRestoringFactoryPrograms::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Restores the entire plugin bank to the original\n";
		buttonTooltip += "factory programs. NOTE: This cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForRestoringFactoryPrograms::onClickMethod() {
}
