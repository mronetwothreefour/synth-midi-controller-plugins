#pragma once

#include <JuceHeader.h>

#include "../params/params_RangeTypes.h"



class OutgoingMidiBuffers;
class UnexposedParameters;

struct PatchDataMessage
{
	static void sendCurrentPatchDataMessageToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, OutgoingMidiBuffers* outgoingBuffers);
	static void sendDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(uint8 bank, uint8 slot, OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static std::vector<uint8> createSysExMessageFromPatchDataStoredInBankAndSlot(uint8 bank, uint8 slot);
	static void addCurrentSettingsDataToVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);
	static uint8 truncateASCIIvalueToLowest6bits(uint8 value);
	static uint8 offsetValueInSignedRange(uint8& value, RangeType rangeType);
	static void addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation);
};