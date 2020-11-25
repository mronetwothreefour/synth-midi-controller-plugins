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
	static const uint16 firstExposedParamDataByte{ 20 };

	static std::vector<uint8> createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void addCurrentSettingsDataToVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);
	static void addPatchNameDataToVector(String& patchName, std::vector<uint8>& dataVector, uint8& checksum);
	static uint8 truncateASCIIvalueToLowest6bits(uint8 value);
	static void addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum);
	static void addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
	static uint8 offsetValueInSignedRange(uint8& value, RangeType rangeType);
	static void addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation);
	static std::vector<uint8> createSysExMessageFromPatchDataStoredInBankAndSlot(uint8 bank, uint8 slot);
};