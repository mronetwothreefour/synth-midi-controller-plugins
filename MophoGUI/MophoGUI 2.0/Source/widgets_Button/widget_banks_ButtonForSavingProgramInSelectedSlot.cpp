#include "widget_banks_ButtonForSavingProgramInSelectedSlot.h"

#include "../banks/banks_ProgramSlotsWidget.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForSavingProgramInSelectedSlot::ButtonForSavingProgramInSelectedSlot(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	programSlots{ programSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Save.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSavingProgramInSelectedSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Saves the plugin GUI's current settings\n";
		buttonTooltip += "in the selected program storage slot.";
	}
	return buttonTooltip;
}

void ButtonForSavingProgramInSelectedSlot::onClickMethod() {
	programSlots.storeCurrentProgramSettingsInSelectedSlot();
}

