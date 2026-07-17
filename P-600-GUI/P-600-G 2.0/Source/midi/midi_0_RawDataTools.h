#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class VoiceTransmissionOptions;

struct RawDataTools
{
    static const uint8 sequentialCircuits_ID = 1;
    static const uint8 messageType_VoiceData{ 2 };
    static const uint8 messageType_VoiceDataRequest{ 0 };

    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);
    static bool isValidVoiceDataHexString(const String& hexString);

    static void applyRawVoiceDataToExposedParameters(const uint8* voiceData, ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions);
    static const std::vector<uint8> extractRawVoiceDataFromExposedParameters(ExposedParameters* exposedParams);

    static std::vector<uint8> createRawDataVectorWithSequentialCircuitsSysExID();


private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RawDataTools)
};