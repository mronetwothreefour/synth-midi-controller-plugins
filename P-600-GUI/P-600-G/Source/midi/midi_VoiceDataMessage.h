#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct VoiceDataMessage {
	static void addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void addVoiceDataMessageForVoiceStoredInSlotToOutgoingMidiBuffers(uint8 slot, UnexposedParameters* unexposedParams);
	static void addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentExposedParamsSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static std::vector<uint8> createSysExMessageFromVoiceDataStoredInSlot(uint8 slot, UnexposedParameters* unexposedParams);
};