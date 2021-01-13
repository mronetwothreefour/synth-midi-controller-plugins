#include "widget_patches_ButtonForLoadingSelectedPatch.h"

#include "../patches/patches_PatchSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForLoadingSelectedPatch::ButtonForLoadingSelectedPatch(PatchSlotsWidget& patchSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	patchSlots{ patchSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Load.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForLoadingSelectedPatch::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Applies the patch settings stored in the selected slot to the\n";
		buttonTooltip += "plugin GUI and to the Matrix-6R hardware's patch edit buffer.";
	}
	return buttonTooltip;
}

void ButtonForLoadingSelectedPatch::onClickMethod()
{
}
