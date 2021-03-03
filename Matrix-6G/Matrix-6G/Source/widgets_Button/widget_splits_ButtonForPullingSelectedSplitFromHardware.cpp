#include "widget_splits_ButtonForPullingSelectedSplitFromHardware.h"

#include "../splits/splits_Constants.h"
#include "../splits/splits_SplitSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForPullingSelectedSplitFromHardware::ButtonForPullingSelectedSplitFromHardware(SplitSlotsComponent& splitSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	splitSlots{ splitSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullSelectedPatchOrSplit.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedSplitFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the data from the selected split storage slot in\n";
		buttonTooltip += "the Matrix-6R hardware and save it in the corresponding\n";
		buttonTooltip += "slot in the plugin storage bank.";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedSplitFromHardware::onClickMethod() {
	auto slot{ splitSlots.selectedSlot };
	if (slot < splits::numberOfSlotsInBank) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		splitSlots.pullSelectedSplitFromHardware();
		auto transmitTime{ midiOptions->patchTransmitTime() };
		callAfterDelay(transmitTime, [this, slot, midiOptions]
			{
				auto basicChannel{ midiOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, slot);
			}
		);
	}
}

void ButtonForPullingSelectedSplitFromHardware::timerCallback() {
}
