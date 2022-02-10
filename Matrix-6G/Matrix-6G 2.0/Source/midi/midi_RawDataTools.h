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
    static std::vector<uint8> initializeVoiceDataMessage(uint8 slot);
    static std::vector<uint8> createVoiceDataMessageHeader(uint8 slot);
    static std::vector<uint8> createVoiceDataRequestMessage(uint8 slot);
    static std::vector<uint8> createActivateQuickEditMessage();
    static std::vector<uint8> initializeSplitDataMessage(uint8 slot);
    static std::vector<uint8> createSplitDataMessageHeader(uint8 slot);
    static std::vector<uint8> createSplitDataRequestMessage(uint8 slot);
    static std::vector<uint8> createSwitchToSplitModeMessage();
    static std::vector<uint8> initializeMasterOptionsDataMessage();
    static std::vector<uint8> createMasterOptionsDataRequestMessage();

private:
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes(int vectorSize);
};



class UnexposedParameters;

struct RawDataTools {
    static const std::vector<uint8> convertVoiceOrSplitHexStringToDataVector(const String& hexString);
    static const String convertVoiceOrSplitDataVectorToHexString(const std::vector<uint8>& dataVector);
    static void addCurrentParameterSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);
    static void addCurrentSplitSettingsToDataVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);
    static void applyVoiceDataVectorToGUI(const uint8 voiceNumber, std::vector<uint8>& voiceDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    static void applySplitDataVectorToGUI(std::vector<uint8>& splitDataVector, UnexposedParameters* unexposedParams);
    static void applyMasterOptionsRawDataToGUI(const uint8* masterOptionsData, UnexposedParameters* unexposedParams);
    static const String extractVoiceNameFromRawVoiceData(const uint8* voiceData);
    static const String extractSplitNameFromRawSplitData(const uint8* splitData);
    static void addCurrentMasterSettingsToDataVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector);

private:
    static const uint8 indexOfFirstVoiceOrSplitParamDataLSByte{ 20 };
    static const uint16 indexOfFirstMasterOptionDataLSByte{ 6 };
    static const int negativeValueOffset{ 256 };

    static void applyVoiceNumberToGUI(const uint8 voiceNumber, UnexposedParameters* unexposedParams);
    static void applyNameOfVoiceInRawDataToGUI(const uint8* voiceData, UnexposedParameters* unexposedParams);
    static void applyNameOfSplitInRawDataToGUI(const uint8* splitData, UnexposedParameters* unexposedParams);
    static void applyRawVoiceDataToExposedParameters(const uint8* voiceData, AudioProcessorValueTreeState* exposedParams);
    static void applyRawSplitDataToGUI(const uint8* splitData, UnexposedParameters* unexposedParams);
    static void applyRawVoiceDataToMatrixModParameters(const uint8* voiceData, UnexposedParameters* unexposedParams);
    static void addVoiceOrSplitNameDataToVector(String & name, int maxLength, std::vector<uint8>& dataVector, uint8& checksum);
    static uint8 truncateASCIIvalueToLowest6bits(uint8 value);
    static void restoreTruncated7thBitToASCIIvalue(uint8& value);
    static String convertStoredASCIIvalueToString(const uint8& value);
    static void addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addSplitParamDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addMasterOptionsDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static uint8 formatSigned6bitValueForSendingToMatrix(uint8& value);
    static uint8 formatSigned7bitValueForSendingToMatrix(uint8& value);
    static uint8 formatSignedZoneTransposeValueForSendingToMatrix(uint8& value);
    static uint8 formatSigned6bitValueForStoringInPlugin(int& value);
    static uint8 formatSigned7bitValueForStoringInPlugin(int& value);
    static uint8 formatSignedZoneTransposeValueForStoringInPlugin(int& value);
    static void addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation);
};
