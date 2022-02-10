#pragma once

#include <JuceHeader.h>

#include "../patches/patches_PatchBanks.h"



class OutgoingMidiBuffers;
class UnexposedParameters;

struct VoiceDataMessage
{
	static void addDataMessageForCurrentVoiceToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void addDataMessageForVoiceStoredInBankAndSlotToOutgoingMidiBuffers(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams);
	static void addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentVoiceSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static std::vector<uint8> createSysExMessageFromVoiceDataStoredInBankAndSlot(VoicesBank bank, uint8 slot, UnexposedParameters* unexposedParams);
};