#include "midi_0_RawDataTools.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

const std::vector<uint8> RawDataTools::convertHexStringToDataVector(const String& hexString) {
    std::vector<uint8> dataVector;
    auto indexOfChecksumByte{ hexString.length() - 2 };
    for (auto i = 0; i != indexOfChecksumByte; ++i) {
        auto hexValueString{ hexString.substring(i, i + 1) };
        dataVector.push_back((uint8)hexValueString.getHexValue32());
    }
    auto checksumHexValueString{ hexString.substring(indexOfChecksumByte, hexString.length()) };
    dataVector.push_back((uint8)checksumHexValueString.getHexValue32());
    return dataVector;
}

const String RawDataTools::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
    String hexString{ "" };
    auto indexOfChecksumByte{ dataVector.size() - 1 };
    for (auto i = 0; i < indexOfChecksumByte; ++i) {
        auto byteString{ String::toHexString(&dataVector[i], 1, 0) };
        auto byteStringStrippedOfLeadingZero{ byteString[1] };
        hexString += byteStringStrippedOfLeadingZero;
    }
    hexString += String::toHexString(&dataVector[indexOfChecksumByte], 1, 0);
    return hexString;
}

void RawDataTools::removeSeventhBitFrom_ASCII_Value(uint8& value) {
    value %= 64;
}

void RawDataTools::restoreSeventhBitTo_ASCII_Value(uint8& value) {
    if (value < 32)
        value += 64;
}

bool RawDataTools::midiMessageIsSysExForMatrix(const MidiMessage& midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        auto manufacturerID{ sysExData[1] };
        auto synthID{ sysExData[2] };
        return (manufacturerID == oberheim_ID && synthID == matrix_ID);
    }
    else
        return false;
}

std::vector<uint8> RawDataTools::createRawDataVectorWithMatrix_6_SysExID() {
    std::vector<uint8> rawDataVector;
    rawDataVector.push_back(oberheim_ID);
    rawDataVector.push_back(matrix_ID);
    return rawDataVector;
}
