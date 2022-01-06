#include "widget_ButtonForPushingProgramToHardwareStorageSlot.h"

#include "../midi/midi_Constants.h"
#include "../midi/midi_ProgramDataDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPushingProgramToHardwareStorageSlot::ButtonForPushingProgramToHardwareStorageSlot(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
	setComponentID(ID::button_PushSelectedProgram.toString());
}

const String ButtonForPushingProgramToHardwareStorageSlot::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Sends a dump of all the program data to the hardware storage\n";
		buttonTooltip += "slot specified by the program number control to the left.\n";
		buttonTooltip += "This overwrites the data that is currently stored in the slot.";
	}
	return buttonTooltip;
}

void ButtonForPushingProgramToHardwareStorageSlot::onClickMethod() {
	ProgramDataDump::addPgmDataDumpForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams);
	callAfterDelay(10, [this]
		{
			auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
			auto pgmSlot{ pgmDataOptions->currentProgramNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, pgmSlot);
		}
	);
}

void ButtonForPushingProgramToHardwareStorageSlot::timerCallback() {
}
