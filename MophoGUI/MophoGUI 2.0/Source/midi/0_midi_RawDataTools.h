#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

struct RawDataTools {
    static const int rawVoiceDataSize{ 293 };
    static const uint8 daveSmithInstrumentsID = 1;
    static const uint8 mophoID = 37;


    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);
    static bool isValidVoiceDataHexString(const String& hexString);
    static void applyRawDataToExposedParameters(const uint8* dumpData, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    static const std::vector<uint8> extractRawDataFromExposedParameters(AudioProcessorValueTreeState* exposedParams);
    static bool midiMessageIsSysExForMopho(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytesForMopho();
};