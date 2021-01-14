#include "widget_patches_ButtonForPushingEntireBankToHardware.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForPushingEntireBankToHardware::ButtonForPushingEntireBankToHardware(PatchBank bank, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	if (bank == PatchBank::analogSynthsA)
		setComponentID(ID::button_PushAnalogSynthsBankA.toString());
	if (bank == PatchBank::analogSynthsB)
		setComponentID(ID::button_PushAnalogSynthsBankB.toString());
	if (bank == PatchBank::basses)
		setComponentID(ID::button_PushBassesBank.toString());
	if (bank == PatchBank::brassAndWoodwinds)
		setComponentID(ID::button_PushBrassAndWoodwindsBank.toString());
	if (bank == PatchBank::customA)
		setComponentID(ID::button_PushCustomBankA.toString());
	if (bank == PatchBank::customB)
		setComponentID(ID::button_PushCustomBankB.toString());
	if (bank == PatchBank::fxAndPercussion)
		setComponentID(ID::button_PushFXandndPercussionBank.toString());
	if (bank == PatchBank::keyboardsA)
		setComponentID(ID::button_PushKeyboardsBankA.toString());
	if (bank == PatchBank::keyboardsB)
		setComponentID(ID::button_PushKeyboardsBankB.toString());
	if (bank == PatchBank::leads)
		setComponentID(ID::button_PushLeadsBank.toString());
	if (bank == PatchBank::miscellaneousA)
		setComponentID(ID::button_PushMiscellaneousBankA.toString());
	if (bank == PatchBank::miscellaneousB)
		setComponentID(ID::button_PushMiscellaneousBankB.toString());
	if (bank == PatchBank::strings)
		setComponentID(ID::button_PushStringsBank.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPushingEntireBankToHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Push all the patches stored in this bank to the\n";
		buttonTooltip += "Matrix hardware's storage bank. NOTE: All the\n";
		buttonTooltip += "patch data stored in the hardware will be over-\n";
		buttonTooltip += "written and this cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForPushingEntireBankToHardware::onClickMethod() {
}
