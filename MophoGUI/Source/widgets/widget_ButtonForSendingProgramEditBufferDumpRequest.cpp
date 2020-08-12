#include "widget_ButtonForSendingProgramEditBufferDumpRequest.h"

#include "../midiTools/midi_OutgoingMidiBuffers.h"
#include "../midiTools/midi_ProgramEditBufferDump.h"



ButtonForSendingProgramEditBufferDumpRequest::ButtonForSendingProgramEditBufferDumpRequest(OutgoingMidiBuffers* outgoingBuffers) :
	TextButton{ "READ" },
	outgoingBuffers{ outgoingBuffers }
{
	String tipString;
	tipString = "Requests a program edit buffer dump from the Mopho hardware\n";
	tipString += "and applies it to the plugin's program settings.";
	setTooltip(tipString);
	onClick = [this] { sendProgramEditBufferDumpRequest(); };
}

void ButtonForSendingProgramEditBufferDumpRequest::sendProgramEditBufferDumpRequest() {
	ProgramEditBufferDump::addRequestForDumpToOutgoingMidiBuffers(outgoingBuffers);
}

ButtonForSendingProgramEditBufferDumpRequest::~ButtonForSendingProgramEditBufferDumpRequest() {
}

