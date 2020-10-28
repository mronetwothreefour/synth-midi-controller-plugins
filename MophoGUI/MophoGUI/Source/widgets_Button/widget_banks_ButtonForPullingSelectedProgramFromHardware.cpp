#include "widget_banks_ButtonForPullingSelectedProgramFromHardware.h"

#include "../banks/banks_ProgramSlotsWidget.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPullingSelectedProgramFromHardware::ButtonForPullingSelectedProgramFromHardware(ProgramSlotsWidget& programSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	programSlots{ programSlots },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedProgramFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected program storage slot in the Mopho hardware\n";
		buttonTooltip += "and save it in the corresponding storage slot in the plugin.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedProgramFromHardware::onClickMethod() {
	programSlots.pullSelectedProgramFromHardware();
}

