#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class MatrixModOptions;
class UnexposedParameters;
class VoiceTransmissionOptions;

struct RawDataTools
{
    static const uint8 oberheim_ID{ 16 };
    static const uint8 matrix_ID{ 6 };
    static const uint8 valueForBarSymbol{ 29 };
    static const int voiceAndSplitDataMessageSlotByte{ 4 };
    static const int firstVoiceAndSplitNameByte{ 5 };

    static bool midiMessageIsSysExForMatrix(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithMatrix_6_SysExID();

    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);

    static void applyRawVoiceDataTo_GUI(const uint8 voiceNum, const uint8* voiceData, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    static const std::vector<uint8> extractRawVoiceDataFrom_GUI(ExposedParameters* exposedParams);
    static bool isValidVoiceDataHexString(const String& hexString);

    static void removeSeventhBitFrom_ASCII_Value(uint8& value);
    static void restoreSeventhBitTo_ASCII_Value(uint8& value);

private:
    static const bool uses_6_bits{ false };
    static const bool uses_7_bits{ true };
    static const int voiceDataSize{ 268 };
    static const int exposedParamsDataSize{ 192 };
    static const int matrixModDataSize{ 60 };
    static const int negativeValueOffset{ 256 };

    static void applyRawVoiceDataToExposedParameters(const uint8* voiceData, ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions);
    static void applyRawVoiceDataToMatrixModOptions(const uint8* voiceData, MatrixModOptions* matrixModOptions);

    static void addVoiceOrSplitNameDataToVectorAndUpdateChecksum(bool isVoiceName, String& name, std::vector<uint8>& dataVector, uint8& checksum);
    static void addExposedParamDataToVectorAndUpdateChecksum(ExposedParameters* exposedParams, std::vector<uint8>& dataVector, uint8& checksum);
    static void addMatrixModDataToVectorAndUpdateChecksum(MatrixModOptions* matrixModOptions, std::vector<uint8>& dataVector, uint8& checksum);
    
    static void formatSignedValueForSendingToMatrix(bool is_7_bit, uint8& value);
    static void formatSignedValueForStoringInPlugin(bool is_7_bit, uint8& value);

    static String convertStored_ASCII_ValueToString(const uint8& value);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RawDataTools)
};