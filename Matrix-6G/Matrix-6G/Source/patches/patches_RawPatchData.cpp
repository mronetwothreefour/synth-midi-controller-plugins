#include "patches_RawPatchData.h"

#include "patches_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



const String RawPatchData::extractPatchNameFromRawPatchData(const uint8* patchData) {
    String patchName{ "" };
    for (auto byte = 0; byte != (2 * matrixParams::maxPatchNameLength); byte += 2) {
        auto lsbByteValue{ (uint8)patchData[byte] };
        auto msbByteValue{ (uint8)patchData[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        if (storedASCIIvalue == patches::valueForBarSymbol_Matrix)
            patchName += "|";
        else {
            auto patchNameCharASCIIValue{ storedASCIIvalue };
            if (patchNameCharASCIIValue < patches::sixthBit)
                restoreTruncated7thBitToASCIIvalue(patchNameCharASCIIValue);
            patchName += (String)std::string(1, patchNameCharASCIIValue);
        }
    }
    return patchName;
}

const std::vector<uint8> RawPatchData::convertHexStringToDataVector(const String& hexString) {
    std::vector<uint8> programData;
    auto indexOfChecksumByte{ hexString.length() - 2 };
    for (auto i = 0; i != indexOfChecksumByte; ++i) {
        auto hexValueString{ hexString.substring(i, i + 1) };
        programData.push_back((uint8)hexValueString.getHexValue32());
    }
    auto checksumHexValueString{ hexString.substring(indexOfChecksumByte, hexString.length()) };
    programData.push_back((uint8)checksumHexValueString.getHexValue32());
    return programData;
}

const String RawPatchData::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
    String hexString{ "" };
    auto indexOfChecksumByte{ dataVector.size() - 1 };
    for (auto i = 0; i < indexOfChecksumByte; ++i) {
        auto byteString{ String::toHexString(&dataVector[i], 1, 0) };
        hexString += byteString[1];
    }
    hexString += String::toHexString(&dataVector[indexOfChecksumByte], 1, 0);
    return hexString;
}


void RawPatchData::applyRawPatchDataToExposedParameters(const uint8* patchData, AudioProcessorValueTreeState* exposedParams) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
        auto paramID{ info.IDfor(param) };
        auto lsByteLocation{ info.dataByteIndexFor(param) * 2 };
        auto lsByteValue{ patchData[lsByteLocation] };
        auto msByteValue{ patchData[lsByteLocation + 1] * 16 };
        auto newValue{ lsByteValue + msByteValue };
        if (info.rangeTypeFor(param) == RangeType::signed6bitValue)
            newValue = { formatSigned6bitValueForStoringInPlugin(newValue) };
        if (info.rangeTypeFor(param) == RangeType::signed7bitValue)
            newValue = { formatSigned7bitValueForStoringInPlugin(newValue) };
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
}

void RawPatchData::applyRawPatchDataToMatrixModParameters(const uint8* patchData, UnexposedParameters* unexposedParams) {
    for (auto i = 0; i != 10; ++i) {
        auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
        auto modSourceLSByteValue{ patchData[i * 6] };
        auto modSourceMSByteValue{ patchData[(i * 6) + 1] * 16 };
        auto modSource{ modSourceLSByteValue + modSourceMSByteValue };
        matrixModSettings->setSourceForModulation((uint8)modSource, i);
        auto modAmountLSByteValue{ patchData[(i * 6) + 2] };
        auto modAmountMSByteValue{ patchData[(i * 6) + 3] * 16 };
        auto modAmount{ modAmountLSByteValue + modAmountMSByteValue };
        matrixModSettings->setAmountForModulation(formatSigned7bitValueForStoringInPlugin(modAmount), i);
        auto modDestinationLSByteValue{ patchData[(i * 6) + 4] };
        auto modDestinationMSByteValue{ patchData[(i * 6) + 5] * 16 };
        auto modDestination{ modDestinationLSByteValue + modDestinationMSByteValue };
        matrixModSettings->setDestinationForModulation((uint8)modDestination, i);
    }
}

void RawPatchData::addCurrentParameterSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector) {
    uint8 checksum{ 0 };
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchName{ currentPatchOptions->currentPatchName() };
    addPatchNameDataToVector(currentPatchName, dataVector, checksum);
    addExposedParamDataToVector(exposedParams, dataVector, checksum);
    addMatrixModDataToVector(unexposedParams, dataVector, checksum);
    dataVector[patches::rawPatchDataVectorChecksumByteIndex] = checksum % (uint8)128;
}

void RawPatchData::addPatchNameDataToVector(String& patchName, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != 8; ++i) {
        auto asciiValue{ (uint8)patchName[i] };
        auto truncatedValue{ truncateASCIIvalueToLowest6bits(asciiValue) };
        auto lsbByteLocation{ patches::rawPatchDataVectorNumberOfHeaderBytes + (2 * i) };
        addValueToDataVectorAtLSBbyteLocation(truncatedValue, &dataVector[lsbByteLocation]);
        checksum += truncatedValue;
    }
}

uint8 RawPatchData::truncateASCIIvalueToLowest6bits(uint8 value) {
    auto truncatedValue{ uint8(value % patches::seventhBit) };
    if (value == patches::valueForBarSymbol_ASCII) {
        truncatedValue = patches::valueForBarSymbol_Matrix;
    }
    return truncatedValue;
}

void RawPatchData::restoreTruncated7thBitToASCIIvalue(uint8& value) {
    value += patches::seventhBit;
}

void RawPatchData::addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        auto param{ exposedParams->getParameter(paramID) };
        auto paramValue{ uint8(param->getValue() * info.maxValueFor(paramIndex)) };
        auto dataByteIndex{ info.dataByteIndexFor(paramIndex) };
        auto lsbByteLocation{ firstExposedParamDataByte + (dataByteIndex * 2) };
        auto rangeType{ info.rangeTypeFor(paramIndex) };
        if (rangeType == RangeType::signed6bitValue)
            paramValue = formatSigned6bitValueForSendingToMatrix(paramValue);
        if (rangeType == RangeType::signed7bitValue)
            paramValue = formatSigned7bitValueForSendingToMatrix(paramValue);
        addValueToDataVectorAtLSBbyteLocation(paramValue, &dataVector[lsbByteLocation]);
        checksum += paramValue;
    }
}

void RawPatchData::addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != 10; ++i) {
        auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
        auto modSource{ matrixModSettings->sourceSettingForModulation(i) };
        auto modAmount{ matrixModSettings->amountSettingForModulation(i) };
        auto modAmountWithOffset{ formatSigned7bitValueForSendingToMatrix(modAmount) };
        auto modDestination{ matrixModSettings->destinationSettingForModulation(i) };
        auto lsbByteLocationForSource{ matrixModSettings->lsbByteLocationForModulation0Source + (i * 6) };
        addValueToDataVectorAtLSBbyteLocation(modSource, &dataVector[lsbByteLocationForSource]);
        checksum += modSource;
        auto lsbByteLocationForAmount{ matrixModSettings->lsbByteLocationForModulation0Amount + (i * 6) };
        addValueToDataVectorAtLSBbyteLocation(modAmountWithOffset, &dataVector[lsbByteLocationForAmount]);
        checksum += modAmountWithOffset;
        auto lsbByteLocationForDestination{ matrixModSettings->lsbByteLocationForModulation0Destination + (i * 6) };
        addValueToDataVectorAtLSBbyteLocation(modDestination, &dataVector[lsbByteLocationForDestination]);
        checksum += modDestination;
    }
}

uint8 RawPatchData::formatSigned6bitValueForSendingToMatrix(uint8& value) {
    auto valueWithOffset{ value -  matrixParams::offsetForSigned6bitRange };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    return (uint8)valueWithOffset;
}

uint8 RawPatchData::formatSigned7bitValueForSendingToMatrix(uint8& value) {
    auto valueWithOffset{ value -  matrixParams::offsetForSigned7bitRange };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    return (uint8)valueWithOffset;
}

uint8 RawPatchData::formatSigned6bitValueForStoringInPlugin(int& value) {
    if (value > 127)
        value -= negativeValueOffset;
    auto valueWithOffset{ value +  matrixParams::offsetForSigned6bitRange };
    return (uint8)valueWithOffset;
}

uint8 RawPatchData::formatSigned7bitValueForStoringInPlugin(int& value) {
    if (value > 127)
        value -= negativeValueOffset;
    auto valueWithOffset{ value +  matrixParams::offsetForSigned7bitRange };
    return (uint8)valueWithOffset;
}

void RawPatchData::addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation) {
    auto leastSignificantByte{ uint8(value % 16) };
    auto mostSignificantByte{ uint8(value / 16) };
    *lsbByteLocation = leastSignificantByte;
    *(lsbByteLocation + 1) = mostSignificantByte;
}