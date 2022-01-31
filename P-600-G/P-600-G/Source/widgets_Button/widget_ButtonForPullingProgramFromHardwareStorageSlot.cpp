#include "widget_ButtonForPullingProgramFromHardwareStorageSlot.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_ProgramDataDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;





ButtonForPullingProgramFromHardwareStorageSlot::ButtonForPullingProgramFromHardwareStorageSlot(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PullSelectedProgram.toString());
}

const String ButtonForPullingProgramFromHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Pull the data from a program storage slot in the\n";
		buttonTooltip += "Prophet-600 hardware (specified by the program number\n";
		buttonTooltip += "control to the left) and apply it to the plugin GUI.";
	}
	return buttonTooltip;
}

void ButtonForPullingProgramFromHardwareStorageSlot::onClickMethod() {
	auto currentPgmOptions{ unexposedParams->programDataOptions_get() };
	auto slot{ currentPgmOptions->currentProgramNumber() };
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	ProgramDataDump::addRequestForPgmDataStoredInHardwareSlotToOutgoingMidiBuffers(slot, outgoingMidiBuffers);
	auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
	auto transmitTime{ pgmDataOptions->programTransmitTime() };
	callAfterDelay(transmitTime, [this, slot]
		{
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, slot);
		}
	);
}

void ButtonForPullingProgramFromHardwareStorageSlot::timerCallback() {
}
