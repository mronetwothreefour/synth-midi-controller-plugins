#include "widget_banks_ButtonForResettingAllBanksToFactoryDefaults.h"

#include "../banks/banks_PluginProgramBanks.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForResettingAllBanksToFactoryDefaults::ButtonForResettingAllBanksToFactoryDefaults(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "RESET", unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForResettingAllBanksToFactoryDefaults::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Restores the factory default programs\n";
		buttonTooltip += "to all three of the plugin storage banks.";
	}
	return buttonTooltip;
}

void ButtonForResettingAllBanksToFactoryDefaults::onClickMethod() {
}

