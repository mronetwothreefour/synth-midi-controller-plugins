#include "widget_voices_ButtonForImportingVoicesBankFromFile.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForImportingVoicesBankFromFile::ButtonForImportingVoicesBankFromFile(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::custom1)
		setComponentID(ID::button_ImportBankIntoCustomBank1.toString());
	if (bank == VoicesBank::custom2)
		setComponentID(ID::button_ImportBankIntoCustomBank2.toString());
	if (bank == VoicesBank::custom3)
		setComponentID(ID::button_ImportBankIntoCustomBank3.toString());

	setTooltip(createButtonTooltipString());
}

const String ButtonForImportingVoicesBankFromFile::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Replace all the programs in the storage\n";
		buttonTooltip += "bank with those stored in a file.";
	}
	return buttonTooltip;
}

void ButtonForImportingVoicesBankFromFile::onClickMethod() {
}
