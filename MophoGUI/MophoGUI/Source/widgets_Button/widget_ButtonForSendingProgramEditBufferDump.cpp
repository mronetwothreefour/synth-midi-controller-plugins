#include "widget_ButtonForSendingProgramEditBufferDump.h"

#include "../midi/midi_ProgramEditBufferDump.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForSendingProgramEditBufferDump::ButtonForSendingProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "WRITE", unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForSendingProgramEditBufferDump::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Writes the plugin's current program settings\n";
		buttonTooltip += "into the Mopho hardware's program edit buffer.";
	}
	return buttonTooltip;
}

void ButtonForSendingProgramEditBufferDump::onClickMethod() {
	ProgramEditBufferDump::addDumpToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
}

ButtonForSendingProgramEditBufferDump::~ButtonForSendingProgramEditBufferDump() {
}
