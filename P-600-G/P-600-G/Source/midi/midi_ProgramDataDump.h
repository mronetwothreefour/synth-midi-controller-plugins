#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct ProgramDataDump {
	static void addPgmDataDumpForCurrentExposedParamsSettingsToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void addRequestForPgmDataStoredInHardwareSlotToOutgoingMidiBuffers(uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentExposedParamsSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
};