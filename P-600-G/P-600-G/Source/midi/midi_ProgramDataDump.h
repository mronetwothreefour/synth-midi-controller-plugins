#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct ProgramDataDump {
	static void addRequestForPgmDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers);
};