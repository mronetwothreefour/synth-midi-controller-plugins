#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class UnexposedParameters;

struct RawDataTools {
    static const uint8 daveSmithInstruments_ID = 1;
    static const uint8 mopho_ID = 37;


    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);
    static bool isValidVoiceDataHexString(const String& hexString);

    static void applyRawVoiceDataToExposedParameters(const uint8* voiceData, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    static const std::vector<uint8> extractRawVoiceDataFromExposedParameters(ExposedParameters* exposedParams);

    static bool midiMessageIsSysExForMopho(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithMophoSysExID();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RawDataTools)
};