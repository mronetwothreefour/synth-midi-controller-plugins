#include "patches_RawPatchData.h"

#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



const String RawPatchData::RawPatchData::extractPatchNameFromRawPatchData(const uint8* patchData) {
    String patchName{ "" };
    for (auto byte = 0; byte != 16; byte += 2) {
        auto lsbByteValue{ (char)patchData[byte] };
        auto msbByteValue{ (char)patchData[byte + 1] };
        auto asciiValueTruncatedToLowest6Bits{ char(lsbByteValue + (msbByteValue * 16)) };
        auto matrixValueForBarSymbol{ (char)29 };
        if (asciiValueTruncatedToLowest6Bits == matrixValueForBarSymbol)
            patchName += "|";
        else {
            auto offsetForTruncatedASCII{ (char)64 };
            auto patchNameCharASCIIValue = char(asciiValueTruncatedToLowest6Bits + offsetForTruncatedASCII);
            patchName += (String)std::string(1, patchNameCharASCIIValue);
        }
    }
    return patchName;
}

const std::vector<uint8> RawPatchData::convertHexStringToDataVector(const String& hexString) {
    std::vector<uint8> programData;
    for (auto i = 0; i != hexString.length(); i += 2) {
        auto hexValueString{ hexString.substring(i, i + 2) };
        programData.push_back((uint8)hexValueString.getHexValue32());
    }
    return programData;
}

const String RawPatchData::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
    auto hexString{ String::toHexString(dataVector.data(), (int)dataVector.size(), 0) };
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
    dataVector[272] = checksum % (uint8)128;
}

void RawPatchData::addPatchNameDataToVector(String& patchName, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != 8; ++i) {
        auto asciiValue{ (uint8)patchName[i] };
        auto truncatedValue{ truncateASCIIvalueToLowest6bits(asciiValue) };
        auto numberOfHeaderBytes{ 4 };
        auto lsbByteLocation{ numberOfHeaderBytes + (2 * i) };
        addValueToDataVectorAtLSBbyteLocation(truncatedValue, &dataVector[lsbByteLocation]);
        checksum += truncatedValue;
    }
}

uint8 RawPatchData::truncateASCIIvalueToLowest6bits(uint8 value) {
    auto truncatedValue{ uint8(value % 64) };
    auto asciiValueForBarSymbol{ 124 };
    if (value == asciiValueForBarSymbol) {
        uint8 matrixValueForBarSymbol{ (uint8)29 };
        truncatedValue = matrixValueForBarSymbol;
    }
    return truncatedValue;
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