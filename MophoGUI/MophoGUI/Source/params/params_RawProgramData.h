#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

struct RawProgramData {
    static const int rawProgramDataSize{ 293 };

    static void applyToExposedParameters(const uint8* dumpData, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    static const std::vector<uint8> extractFromExposedParameters(AudioProcessorValueTreeState* exposedParams);
};