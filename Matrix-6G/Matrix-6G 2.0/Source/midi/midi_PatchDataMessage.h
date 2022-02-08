#pragma once

#include <JuceHeader.h>

#include "../patches/patches_PatchBanks.h"



class OutgoingMidiBuffers;
class UnexposedParameters;

struct PatchDataMessage
{
	static void addDataMessageForCurrentPatchToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void addDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(PatchBank bank, uint8 slot, UnexposedParameters* unexposedParams);
	static void addRequestForPatchDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static std::vector<uint8> createSysExMessageFromPatchDataStoredInBankAndSlot(PatchBank bank, uint8 slot, UnexposedParameters* unexposedParams);
};