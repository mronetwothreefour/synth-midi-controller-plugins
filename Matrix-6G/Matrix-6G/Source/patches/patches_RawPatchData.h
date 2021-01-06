#pragma once

#include <JuceHeader.h>

#include "../params/params_RangeTypes.h"



class UnexposedParameters;

struct RawPatchData {
    static const String RawPatchData::extractPatchNameFromRawPatchData(const uint8* patchData);
    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);
    static void applyRawPatchDataToExposedParameters(const uint8* patchData, AudioProcessorValueTreeState* exposedParams);
    static void applyRawPatchDataToMatrixModParameters(const uint8* patchData, UnexposedParameters* unexposedParams);

public:
    static void addCurrentParameterSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);

private:
    static const uint16 firstExposedParamDataByte{ 20 };
    static const int negativeValueOffset{ 256 };

    static void addPatchNameDataToVector(String& patchName, std::vector<uint8>& dataVector, uint8& checksum);
    static uint8 truncateASCIIvalueToLowest6bits(uint8 value);
    static void addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static uint8 formatSigned6bitValueForSendingToMatrix(uint8& value);
    static uint8 formatSigned7bitValueForSendingToMatrix(uint8& value);
    static uint8 formatSigned6bitValueForStoringInPlugin(int& value);
    static uint8 formatSigned7bitValueForStoringInPlugin(int& value);
    static void addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation);
};