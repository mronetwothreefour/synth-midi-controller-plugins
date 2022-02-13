#include "widget_splits_ButtonForSavingCurrentSplitSettingsInSelectedSlot.h"

#include "../splits/splits_Constants.h"
#include "../splits/splits_SplitSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForSavingCurrentSplitSettingsInSelectedSlot::ButtonForSavingCurrentSplitSettingsInSelectedSlot(SplitSlotsComponent& splitSlots, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	splitSlots{ splitSlots },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Save.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForSavingCurrentSplitSettingsInSelectedSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Saves the current split settings in the\n";
		buttonTooltip += "selected patch storage slot, both in the\n";
		buttonTooltip += "plugin storage bank and in the Matrix-6R\n";
		buttonTooltip += "hardware. NOTE: This will overwrite the data\n";
		buttonTooltip += "stored in the hardware and cannot be undone.";
	}
	return buttonTooltip;
}

void ButtonForSavingCurrentSplitSettingsInSelectedSlot::onClickMethod() {
	if (splitSlots.selectedSlot < splits::numberOfSlotsInBank) {
		splitSlots.storeCurrentSplitSettingsInSelectedSlot();
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this]
			{
				auto globalOptions{ unexposedParams->globalOptions_get() };
				auto basicChannel{ globalOptions->basicChannel() };
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, (int)splitSlots.selectedSlot);
			}
		);
	}
}

void ButtonForSavingCurrentSplitSettingsInSelectedSlot::timerCallback() {
}
