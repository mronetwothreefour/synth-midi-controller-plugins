#pragma once

#include <JuceHeader.h>



struct IncomingMidi
{
	static MidiBuffer pullMessagesThatAffectExposedParamsFromBuffer(AudioProcessorValueTreeState* exposedParams, const MidiBuffer& midiMessages);

private:
	static void handleIncomingSysEx(AudioProcessorValueTreeState* exposedParams, const uint8* sysExData);
};

