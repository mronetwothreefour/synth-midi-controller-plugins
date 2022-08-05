#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct SplitDataMessage
{
	static void addDataMessageForSplitStoredInSlotToOutgoingMidiBuffers(uint8 slot, UnexposedParameters* unexposedParams);
	static void addRequestForSplitDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromSplitDataStoredInSlot(uint8 slot, UnexposedParameters* unexposedParams);
};