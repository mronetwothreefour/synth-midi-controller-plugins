#include "widget_banks_ButtonForLoadingSelectedProgram.h"

#include "../banks/banks_ProgramSlotsWidget.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForLoadingSelectedProgram::ButtonForLoadingSelectedProgram(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	programSlots{ programSlots },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForLoadingSelectedProgram::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Applies the program settings stored in the selected slot to the\n";
		buttonTooltip += "plugin GUI and to the Mopho hardware's program edit buffer.";
	}
	return buttonTooltip;
}

void ButtonForLoadingSelectedProgram::onClickMethod() {
	programSlots.loadProgramFromSelectedSlot();
}

