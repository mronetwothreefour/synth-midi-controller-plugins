#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct PatchDataMessage
{
	static void sendCurrentPatchDataMessageToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, OutgoingMidiBuffers* outgoingBuffers);
	static void sendDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static std::vector<uint8> createSysExMessageFromPatchDataStoredInBankAndSlot(uint8 bank, uint8 slot);
};