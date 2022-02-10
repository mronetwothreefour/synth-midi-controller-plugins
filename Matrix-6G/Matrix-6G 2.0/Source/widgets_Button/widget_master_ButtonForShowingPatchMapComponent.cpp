#include "widget_master_ButtonForShowingPatchMapComponent.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForShowingPatchMapComponent::ButtonForShowingPatchMapComponent(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Edit.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForShowingPatchMapComponent::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "When enabled, the Patch Map lets you easliy customize which patch gets\n";
		buttonTooltip += "loaded when the hardware receives a program change message, without\n";
		buttonTooltip += "having to physically reorder the voices in the storage bank. For example,\n";
		buttonTooltip += "a program change message calling program 0 can be specified to load\n";
		buttonTooltip += "patch 23 instead, and to also load patch 57 on a second device further\n";
		buttonTooltip += "on in the MIDI chain. Click this button to open a window where you can\n";
		buttonTooltip += "edit the Patch Map. NOTE: The changes you make will not be immediately\n";
		buttonTooltip += "updated on the hardware. Click the PUSH button to update all options.\n";
	}
	return buttonTooltip;
}

void ButtonForShowingPatchMapComponent::onClickMethod() {
}
