#include "widget_patches_ButtonForPushingEntireBankToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingEntireBankToHardware::ButtonForPushingEntireBankToHardware(VoicesBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == VoicesBank::analogSynthsA)
		setComponentID(ID::button_PushAnalogSynthsBankA.toString());
	if (bank == VoicesBank::analogSynthsB)
		setComponentID(ID::button_PushAnalogSynthsBankB.toString());
	if (bank == VoicesBank::basses)
		setComponentID(ID::button_PushBassesBank.toString());
	if (bank == VoicesBank::brassAndWoodwinds)
		setComponentID(ID::button_PushBrassAndWoodwindsBank.toString());
	if (bank == VoicesBank::customA)
		setComponentID(ID::button_PushCustomBankA.toString());
	if (bank == VoicesBank::customB)
		setComponentID(ID::button_PushCustomBankB.toString());
	if (bank == VoicesBank::fxAndPercussion)
		setComponentID(ID::button_PushFXandndPercussionBank.toString());
	if (bank == VoicesBank::keyboardsA)
		setComponentID(ID::button_PushKeyboardsBankA.toString());
	if (bank == VoicesBank::keyboardsB)
		setComponentID(ID::button_PushKeyboardsBankB.toString());
	if (bank == VoicesBank::leads)
		setComponentID(ID::button_PushLeadsBank.toString());
	if (bank == VoicesBank::miscellaneousA)
		setComponentID(ID::button_PushMiscellaneousBankA.toString());
	if (bank == VoicesBank::miscellaneousB)
		setComponentID(ID::button_PushMiscellaneousBankB.toString());
	if (bank == VoicesBank::strings)
		setComponentID(ID::button_PushStringsBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingEntireBankToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push all the voices stored in this bank to\n";
		buttonTooltip += "the Matrix hardware's storage bank. NOTE: All\n";
		buttonTooltip += "the patch data stored in the hardware will be\n";
		buttonTooltip += "overwritten and this cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForPushingEntireBankToHardware::onClickMethod() {
}
