#include "widget_ButtonForSendingProgramEditBufferDumpRequest.h"

#include "../midiTools/midi_ProgramEditBufferDump.h"



ButtonForSendingProgramEditBufferDumpRequest::ButtonForSendingProgramEditBufferDumpRequest() :
	TextButton{ "READ" }
{
	String tipString;
	tipString = "Requests a program edit buffer dump from the Mopho hardware\n";
	tipString += "and applies it to the plugin's program settings.";
	setTooltip(tipString);
	onClick = [this] { sendProgramEditBufferDumpRequest(); };
}

void ButtonForSendingProgramEditBufferDumpRequest::sendProgramEditBufferDumpRequest() {
	ProgramEditBufferDump::request();
}

ButtonForSendingProgramEditBufferDumpRequest::~ButtonForSendingProgramEditBufferDumpRequest() {
}
