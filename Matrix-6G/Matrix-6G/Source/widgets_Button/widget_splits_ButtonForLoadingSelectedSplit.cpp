#include "widget_splits_ButtonForLoadingSelectedSplit.h"


#include "../splits/splits_Constants.h"
#include "../splits/splits_SplitSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForLoadingSelectedSplit::ButtonForLoadingSelectedSplit(SplitSlotsComponent& splitSlots, UnexposedParameters* unexposedParams) :
    BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
    splitSlots{ splitSlots },
    unexposedParams{ unexposedParams }
{
    setComponentID(ID::button_Load.toString());
    setTooltip(createButtonTooltipString());
}

const String ButtonForLoadingSelectedSplit::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Loads the split settings stored in the selected slot into the plugin GUI\n";
		buttonTooltip += "and pushes it into the corresponding slot on the hardware. NOTE: This will\n";
		buttonTooltip += "overwrite the split data in the hardware storage slot and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForLoadingSelectedSplit::onClickMethod() {
	auto slot{ splitSlots.selectedSlot };
	if (slot < splits::numberOfSlotsInBank) {
		splitSlots.loadSplitFromSelectedSlot();
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto transmitTime{ midiOptions->patchTransmitTime() };
		callAfterDelay(transmitTime, [this, midiOptions, slot]
			{
				auto basicChannel{ midiOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, slot);
			}
		);
	}
}

void ButtonForLoadingSelectedSplit::timerCallback() {
}
