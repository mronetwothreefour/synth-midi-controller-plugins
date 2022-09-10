#include "midi_0_RawDataTools.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_0_tree_MatrixModOptions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

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

void RawDataTools::applyRawVoiceDataTo_GUI(const uint8* /*voiceData*/, ExposedParameters* /*exposedParams*/, UnexposedParameters* /*unexposedParams*/)
{
}

const std::vector<uint8> RawDataTools::extractRawVoiceDataFrom_GUI(ExposedParameters* exposedParams) {
    std::vector<uint8> voiceData;
    uint8 checksum{ 0 };
    auto currentVoiceName{ exposedParams->currentVoiceOptions->currentVoiceName() };
    addVoiceOrSplitNameDataToVectorAndUpdateChecksum(true, currentVoiceName, voiceData, checksum);
    addExposedParamDataToVectorAndUpdateChecksum(exposedParams, voiceData, checksum);
    addMatrixModDataToVectorAndUpdateChecksum(exposedParams->matrixModOptions.get(), voiceData, checksum);
    for (auto i = voiceData.size(); i < voiceDataSize; ++i)
        voiceData.push_back((uint8)0);
    voiceData.push_back(checksum % (uint8)128);
    return voiceData;
}

void RawDataTools::removeSeventhBitFrom_ASCII_Value(uint8& value) {
    value %= 64;
}

void RawDataTools::restoreSeventhBitTo_ASCII_Value(uint8& value) {
    if (value < 32)
        value += 64;
}

void RawDataTools::addVoiceOrSplitNameDataToVectorAndUpdateChecksum(bool isVoiceName, String& name, std::vector<uint8>& dataVector, uint8& checksum) {
    auto maxLength{ isVoiceName ? 8 : 6 };
    for (auto charNum = 0; charNum != maxLength; ++charNum) {
        auto asciiValue{ (uint8)name[charNum] };
        removeSeventhBitFrom_ASCII_Value(asciiValue);
        dataVector.push_back(asciiValue % 16);
        dataVector.push_back(asciiValue / 16);
        checksum += asciiValue;
    }
}

void RawDataTools::addExposedParamDataToVectorAndUpdateChecksum(ExposedParameters* exposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    std::vector<uint8> exposedParamsData;
    for (auto i = 0; i != exposedParamsDataSize; ++i)
        exposedParamsData.push_back((uint8)0);
    auto info{ exposedParams->info.get() };
    for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
        auto paramID{ info->IDfor(paramIndex) };
        auto paramPtr{ exposedParams->state->getParameter(paramID) };
        auto paramValue{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
        auto dataByteIndex{ info->dataByteIndexFor(paramIndex) };
        auto lsbByteLocation{ dataByteIndex * 2 };
        auto rangeType{ info->rangeTypeFor(paramIndex) };
        if (rangeType == RangeType::signed_6_bitValue)
            formatSignedValueForSendingToMatrix(uses_6_bits, paramValue);
        if (rangeType == RangeType::signed_7_bitValue)
            formatSignedValueForSendingToMatrix(uses_7_bits, paramValue);
        exposedParamsData[lsbByteLocation] = uint8(paramValue % 16);
        exposedParamsData[lsbByteLocation + 1] = uint8(paramValue / 16);
        checksum += paramValue;
    }
    for (auto dataByte : exposedParamsData)
        dataVector.push_back(dataByte);
}

void RawDataTools::addMatrixModDataToVectorAndUpdateChecksum(MatrixModOptions* matrixModOptions, std::vector<uint8>& dataVector, uint8& checksum) {
    std::vector<uint8> exposedParamsData;
    for (auto modNum = 0; modNum != 10; ++modNum) {
        auto modSource{ matrixModOptions->modSource(modNum) };
        dataVector.push_back(modSource % 16);
        dataVector.push_back(modSource / 16);
        checksum += modSource;

        auto modAmount{ matrixModOptions->modAmount(modNum) };
        formatSignedValueForSendingToMatrix(uses_7_bits, modAmount);
        dataVector.push_back(modAmount % 16);
        dataVector.push_back(modAmount / 16);
        checksum += modAmount;

        auto modDest{ matrixModOptions->modDest(modNum) };
        dataVector.push_back(modDest % 16);
        dataVector.push_back(modDest / 16);
        checksum += modDest;
    }
}

void RawDataTools::formatSignedValueForSendingToMatrix(bool is_7_bit, uint8& value) {
    auto valueWithOffset{ value - (is_7_bit ? EP::offsetForSigned_7_BitRange : EP::offsetForSigned_6_BitRange) };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    value = (uint8)valueWithOffset;
}

