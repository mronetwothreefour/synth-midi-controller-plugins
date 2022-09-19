#include "midi_0_RawDataTools.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_0_tree_MatrixModOptions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_VoiceTransmissionOptions.h"
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

void RawDataTools::applyRawVoiceDataTo_GUI(const uint8 voiceNum, const uint8* voiceData, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) {
    auto currentVoiceOptions{ exposedParams->currentVoiceOptions.get() };
    currentVoiceOptions->setCurrentVoiceNumber(voiceNum);

    String voiceName{ "" };
    for (auto byte = 0; byte != VCS::numberOfCharsInVoiceName * 2; byte += 2) {
        auto lsbByteValue{ (uint8)voiceData[byte] };
        auto msbByteValue{ (uint8)voiceData[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        restoreSeventhBitTo_ASCII_Value(storedASCIIvalue);
        voiceName += convertStored_ASCII_ValueToString(storedASCIIvalue);
    }
    currentVoiceOptions->setCurrentVoiceName(voiceName);

    auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
    applyRawVoiceDataToExposedParameters(voiceData + VCS::indexOfFirstExposedParamsDataByte, exposedParams, transmitOptions);

    auto matrixModOptions{ exposedParams->matrixModOptions.get() };
    applyRawVoiceDataToMatrixModOptions(voiceData + VCS::indexOfFirstMatrixModDataByte, matrixModOptions);
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

bool RawDataTools::isValidVoiceDataHexString(const String& hexString) {
    auto isNotCorrectLength{ hexString.length() != VCS::lengthOfVoiceDataHexString };
    if (isNotCorrectLength)
        return false;
    else
        return true;
}

void RawDataTools::removeSeventhBitFrom_ASCII_Value(uint8& value) {
    value %= 64;
}

void RawDataTools::restoreSeventhBitTo_ASCII_Value(uint8& value) {
    if (value < 32 && value != valueForBarSymbol)
        value += 64;
}

void RawDataTools::applyRawVoiceDataToExposedParameters(const uint8* voiceData, ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions) {
    transmitOptions->setParamChangesShouldBeTransmitted(false);
    auto info{ exposedParams->info.get() };
    for (uint8 param = 0; param != EP::numberOfExposedParams; ++param) {
        auto paramID{ info->IDfor(param) };
        auto lsByteLocation{ info->dataByteIndexFor(param) * 2 };
        auto lsByteValue{ voiceData[lsByteLocation] };
        auto msByteValue{ voiceData[lsByteLocation + 1] * 16 };
        auto newValue{ uint8(lsByteValue + msByteValue) };
        if (info->rangeTypeFor(param) == RangeType::signed_6_bitValue)
            formatSignedValueForStoringInPlugin(uses_6_bits, newValue);
        if (info->rangeTypeFor(param) == RangeType::signed_7_bitValue)
            formatSignedValueForStoringInPlugin(uses_7_bits, newValue);
        auto paramPtr{ exposedParams->state->getParameter(paramID) };
        paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newValue));
    }
    transmitOptions->setParamChangesShouldBeTransmitted(true);
}

void RawDataTools::applyRawVoiceDataToMatrixModOptions(const uint8* voiceData, MatrixModOptions* matrixModOptions) {
    for (auto modNum = 0; modNum != 10; ++modNum) {
        auto modSource_LS_ByteValue{ voiceData[modNum * 6] };
        auto modSource_MS_ByteValue{ voiceData[(modNum * 6) + 1] * 16 };
        auto modSource{ modSource_LS_ByteValue + modSource_MS_ByteValue };
        matrixModOptions->setModSource(modNum, (uint8)modSource);

        auto modAmount_LS_ByteValue{ voiceData[(modNum * 6) + 2] };
        auto modAmount_MS_ByteValue{ voiceData[(modNum * 6) + 3] * 16 };
        auto modAmount{ uint8(modAmount_LS_ByteValue + modAmount_MS_ByteValue) };
        formatSignedValueForStoringInPlugin(uses_7_bits, modAmount);
        matrixModOptions->setModAmount(modNum, modAmount);

        auto modDest_LS_ByteValue{ voiceData[(modNum * 6) + 4] };
        auto modDest_MS_ByteValue{ voiceData[(modNum * 6) + 5] * 16 };
        auto modDest{ modDest_LS_ByteValue + modDest_MS_ByteValue };
        matrixModOptions->setModDest(modNum, (uint8)modDest);
    }
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

void RawDataTools::formatSignedValueForStoringInPlugin(bool is_7_bit, uint8& value) {
    int valueWithOffset{ value };
    if (valueWithOffset > 127)
        valueWithOffset -= negativeValueOffset;
    valueWithOffset += (is_7_bit ? EP::offsetForSigned_7_BitRange : EP::offsetForSigned_6_BitRange);
    value = (uint8)valueWithOffset;
}

String RawDataTools::convertStored_ASCII_ValueToString(const uint8& value) {
    String characterString;
    if (value == valueForBarSymbol)
        characterString = "|";
    else {
        auto splitNameCharASCIIValue{ value };
        restoreSeventhBitTo_ASCII_Value(splitNameCharASCIIValue);
        characterString = (String)std::string(1, splitNameCharASCIIValue);
    }
    return characterString;
}

