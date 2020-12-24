#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

struct RawProgramData {
    static const int rawProgramDataSize{ 293 };

    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);
    static void applyToExposedParameters(const uint8* dumpData, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    static const std::vector<uint8> extractFromExposedParameters(AudioProcessorValueTreeState* exposedParams);
};