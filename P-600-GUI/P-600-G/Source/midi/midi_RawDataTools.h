#pragma once

#include <JuceHeader.h>



struct RawSysExDataVector {
    static std::vector<uint8> createVoiceDataRequestMessage(uint8 slot);
    static std::vector<uint8> initializeVoiceDataMessage(uint8 slot);
    static std::vector<uint8> createVoiceDataMessageHeader(uint8 slot);

private:
    static std::vector<uint8> createRawDataVectorWithManufacturerIDheaderByte(int vectorSize);
};



class UnexposedParameters;

struct RawDataTools {
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);
    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static void addCurrentExposedParamsSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector);
    static bool isValidVoiceDataHexString(const String& hexString);

private:
    static void insertFilterKeyTrackValueIntoDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector);
    static void insertExposedParamValueIntoDataVector(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector);

public:
    static void applyVoiceDataVectorToGUI(const uint8 voiceNumber, std::vector<uint8>& voiceDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    static void applyVoiceNumberToGUI(const uint8 voiceNumber, UnexposedParameters* unexposedParams);
    static void applyRawVoiceDataToExposedParameters(const uint8* voiceData, AudioProcessorValueTreeState* exposedParams);
    static uint8 extractFilterKeyTrackValueFromRawVoiceData(const uint8* voiceData);
    static uint8 extractParamValueFromRawVoiceData(uint8 param, const uint8* voiceData);
};