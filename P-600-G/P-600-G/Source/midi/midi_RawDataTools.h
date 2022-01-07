#pragma once

#include <JuceHeader.h>



struct RawSysExDataVector {
    static std::vector<uint8> createPgmDataRequestMessage(uint8 slot);
    static std::vector<uint8> initializePgmDataDumpMessage(uint8 slot);

private:
    static std::vector<uint8> createRawDataVectorWithManufacturerIDheaderByte(int vectorSize);
};



class UnexposedParameters;

struct RawDataTools {
    static void addCurrentExposedParamsSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector);

private:
    static void insertFilterKeyTrackValueIntoDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector);
    static void insertExposedParamValueIntoDataVector(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector);

public:
    static void applyPgmDataVectorToGUI(const uint8 pgmNumber, std::vector<uint8>& pgmDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    static void applyPgmNumberToGUI(const uint8 pgmNumber, UnexposedParameters* unexposedParams);
    static void applyRawPgmDataToExposedParameters(const uint8* pgmData, AudioProcessorValueTreeState* exposedParams);
    static uint8 extractFilterKeyTrackValueFromPgmData(const uint8* pgmData);
    static uint8 extractParamValueFromPgmData(uint8 param, const uint8* pgmData);
};