#include "widget_ButtonForSendingProgramEditBufferDump.h"

#include "../midiTools/midi_OutgoingMidiBuffers.h"
#include "../midiTools/midi_ProgramEditBufferDump.h"


ButtonForSendingProgramEditBufferDump::ButtonForSendingProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers) :
	TextButton{ "WRITE" },
	outgoingBuffers{ outgoingBuffers },
	exposedParams{ exposedParams }
{
	String tipString;
	tipString =  "Writes the plugin's current program settings\n";
	tipString += "into the Mopho hardware's program edit buffer.";
	setTooltip(tipString);
	onClick = [this] { sendProgramEditBufferDump(); };
}


void ButtonForSendingProgramEditBufferDump::sendProgramEditBufferDump() {
	ProgramEditBufferDump::addDumpToOutgoingMidiBuffers(exposedParams, outgoingBuffers);
}

ButtonForSendingProgramEditBufferDump::~ButtonForSendingProgramEditBufferDump() {
}
