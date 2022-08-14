#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class UnexposedParameters;

struct RawDataTools
{
    static const uint8 oberheim_ID{ 1 };
    static const uint8 matrix_ID{ 37 };

    static const std::vector<uint8> convertHexStringToDataVector(const String& hexString);
    static const String convertDataVectorToHexString(const std::vector<uint8>& dataVector);

    //static void applyRawVoiceDataTo_GUI(const uint8* voiceData, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    //static const std::vector<uint8> extractRawVoiceDataFrom_GUI(ExposedParameters* exposedParams);

    static bool midiMessageIsSysExForMatrix(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithMatrix_6_SysExID();
};