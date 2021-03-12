#pragma once

#include <JuceHeader.h>

#include "../params/params_RangeTypes.h"



struct SysExID {
    enum class TargetDevice {
        Manufacturer = (char)16,    // Oberheim
        Device = (char)6            // Matrix-6
    };

    static bool matchesHardwareSynthID(const MidiMessage& midiMessage);
};



struct RawSysExDataVector {
    static std::vector<uint8> createParamChangeMessage(uint8 newValue, uint8 param);
    static std::vector<uint8> initializePatchDataMessage(uint8 slot);
    static std::vector<uint8> createPatchDataMessageHeader(uint8 slot);
    static std::vector<uint8> createPatchDataRequestMessage(uint8 slot);
    static std::vector<uint8> createActivateQuickPatchEditingMessage();
    static std::vector<uint8> initializeSplitDataMessage(uint8 slot);
    static std::vector<uint8> createSplitDataMessageHeader(uint8 slot);
    static std::vector<uint8> createSplitDataRequestMessage(uint8 slot);
    static std::vector<uint8> createSwitchToSplitModeMessage();

private:
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes(int vectorSize);
};



class UnexposedParameters;

struct RawDataTools {
    static const std::vector<uint8> convertPatchOrSplitHexStringToDataVector(const String& hexString);
    static const String convertPatchOrSplitDataVectorToHexString(const std::vector<uint8>& dataVector);
    static void addCurrentParameterSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);
    static void addCurrentSplitSettingsToDataVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);
    static void applyPatchDataVectorToGUI(const uint8 patchNumber, std::vector<uint8>& patchDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    static void applySplitDataVectorToGUI(std::vector<uint8>& splitDataVector, UnexposedParameters* unexposedParams);
    static const String extractPatchNameFromRawPatchData(const uint8* patchData);
    static const String extractSplitNameFromRawSplitData(const uint8* splitData);

private:
    static const uint8 firstPatchOrSplitParamDataByte{ 20 };
    static const int negativeValueOffset{ 256 };

    static void applyPatchNumberToGUI(const uint8 patchNumber, UnexposedParameters* unexposedParams);
    static void applyNameOfPatchInRawDataToGUI(const uint8* patchData, UnexposedParameters* unexposedParams);
    static void applyNameOfSplitInRawDataToGUI(const uint8* splitData, UnexposedParameters* unexposedParams);
    static void applyRawPatchDataToExposedParameters(const uint8* patchData, AudioProcessorValueTreeState* exposedParams);
    static void applyRawSplitDataToGUI(const uint8* splitData, UnexposedParameters* unexposedParams);
    static void applyRawPatchDataToMatrixModParameters(const uint8* patchData, UnexposedParameters* unexposedParams);
    static void addPatchOrSplitNameDataToVector(String & name, int maxLength, std::vector<uint8>& dataVector, uint8& checksum);
    static uint8 truncateASCIIvalueToLowest6bits(uint8 value);
    static void restoreTruncated7thBitToASCIIvalue(uint8& value);
    static String convertStoredASCIIvalueToString(const uint8& value);
    static void addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addSplitParamDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static uint8 formatSigned6bitValueForSendingToMatrix(uint8& value);
    static uint8 formatSigned7bitValueForSendingToMatrix(uint8& value);
    static uint8 formatSignedZoneTransposeValueForSendingToMatrix(uint8& value);
    static uint8 formatSigned6bitValueForStoringInPlugin(int& value);
    static uint8 formatSigned7bitValueForStoringInPlugin(int& value);
    static uint8 formatSignedZoneTransposeValueForStoringInPlugin(int& value);
    static void addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation);
};
