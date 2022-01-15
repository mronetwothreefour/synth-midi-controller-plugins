#include "midi_RawDataTools.h"

#include "midi_Constants.h"
#include "../pgmData/pgmData_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;
using namespace ID;



std::vector<uint8> RawSysExDataVector::createPgmDataRequestMessage(uint8 slot)
{
    jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
    auto rawDataVector{ createRawDataVectorWithManufacturerIDheaderByte(MIDI::sizeOfPgmDataDumpRequestVector) };
    rawDataVector[1] = MIDI::opcode_RequestPgmDataDump;
    rawDataVector[2] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::initializePgmDataDumpMessage(uint8 slot) {
    jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
    auto rawDataVector{ createRawDataVectorWithManufacturerIDheaderByte(MIDI::sizeOfPgmDataDumpVector) };
    rawDataVector[1] = MIDI::opcode_PgmDataDump;
    rawDataVector[2] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createRawDataVectorWithManufacturerIDheaderByte(int vectorSize) {
    jassert(vectorSize > 0);
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = MIDI::manufacturerID;
    return rawDataVector;
}




const String RawDataTools::convertPgmDataVectorToHexString(const std::vector<uint8>& dataVector) {
    auto hexString{ String::toHexString(dataVector.data(), (int)dataVector.size(), 0) };
    return hexString;
}

const std::vector<uint8> RawDataTools::convertPgmDataHexStringToDataVector(const String& hexString) {
    std::vector<uint8> dataVector;
    for (auto i = 0; i < pgmData::indexOfFirstNameCharInPgmDataHexString; i += 2) {
        auto hexValueString{ hexString.substring(i, i + 2) };
        dataVector.push_back((uint8)hexValueString.getHexValue32());
    }
    return dataVector;
}

void RawDataTools::addCurrentExposedParamsSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        if (paramID.toString() == "filterKeyTrack")
            insertFilterKeyTrackValueIntoDataVector(exposedParams, dataVector);
        else
            insertExposedParamValueIntoDataVector(paramIndex, exposedParams, dataVector);
    }
}

void RawDataTools::insertFilterKeyTrackValueIntoDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector) {
    auto& info{ InfoForExposedParameters::get() };
    auto filterKeyTrackParam{ info.indexForParamID("filterKeyTrack") };
    auto nybbleIndex{ MIDI::numberOfHeaderBytesInPgmDataDump + info.firstNybbleIndexFor(filterKeyTrackParam) };
    auto param{ exposedParams->getParameter("filterKeyTrack") };
    auto paramValue{ uint8(param->getValue() * info.maxValueFor(filterKeyTrackParam)) };
    if (paramValue == 1)
        dataVector[nybbleIndex] += 8;
    if (paramValue == 2)
        dataVector[nybbleIndex] += 4;
}

void RawDataTools::insertExposedParamValueIntoDataVector(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector) {
    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(paramIndex) };
    auto param{ exposedParams->getParameter(paramID) };
    auto paramValue{ uint8(param->getValue() * info.maxValueFor(paramIndex)) };
    auto nybbleIndex{ MIDI::numberOfHeaderBytesInPgmDataDump + info.firstNybbleIndexFor(paramIndex) };
    auto firstBitIndex{ info.firstBitIndexFor(paramIndex) };
    auto totalNumberOfBits{ info.totalNumberOfBitsNeededFor(paramIndex) };
    for (uint8 bitCounter = 0; bitCounter != totalNumberOfBits; ++bitCounter) {
        auto currentBit{ firstBitIndex + bitCounter };
        if (currentBit == 4 || currentBit == 8)
            ++nybbleIndex;
        currentBit %= 4;
        auto bitIsOn{ paramValue & roundToInt(std::pow(2, bitCounter)) };
        if (bitIsOn)
            dataVector[nybbleIndex] += (uint8)roundToInt(std::pow(2, currentBit));
    }
}

void RawDataTools::applyPgmDataVectorToGUI(const uint8 pgmNumber, std::vector<uint8>& pgmDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    applyPgmNumberToGUI(pgmNumber, unexposedParams);
    auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
    pgmDataOptions->setParamChangeEchosAreBlocked();
    applyRawPgmDataToExposedParameters(pgmDataVector.data(), exposedParams);
    pgmDataOptions->setParamChangeEchosAreNotBlocked();
}

void RawDataTools::applyPgmNumberToGUI(const uint8 pgmNumber, UnexposedParameters* unexposedParams) {
    auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
    pgmDataOptions->setCurrentProgramNumber(pgmNumber);
}

void RawDataTools::applyRawPgmDataToExposedParameters(const uint8* pgmData, AudioProcessorValueTreeState* exposedParams) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
        auto paramID{ info.IDfor(param) };
        uint8 newValue{ (uint8)0 };
        if (info.IDfor(param).toString() == "filterKeyTrack")
            newValue = extractFilterKeyTrackValueFromPgmData(pgmData);
        else
            newValue = extractParamValueFromPgmData(param, pgmData);
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
}

uint8 RawDataTools::extractFilterKeyTrackValueFromPgmData(const uint8* pgmData) {
    auto& info{ InfoForExposedParameters::get() };
    auto filterKeyTrackParam{ info.indexForParamID("filterKeyTrack") };
    auto nybbleIndex{ info.firstNybbleIndexFor(filterKeyTrackParam) };
    auto firstBitIndex{ info.firstBitIndexFor(filterKeyTrackParam) };
    auto filterKeyTrackValue{ (uint8)0 };
    auto firstBitIsOn{ pgmData[nybbleIndex] & roundToInt(std::pow(2, firstBitIndex)) };
    if (firstBitIsOn)
        filterKeyTrackValue = 2;
    auto secondBitIsOn{ pgmData[nybbleIndex] & roundToInt(std::pow(2, firstBitIndex + 1)) };
    if (secondBitIsOn)
        filterKeyTrackValue = 1;
    return filterKeyTrackValue;
}

uint8 RawDataTools::extractParamValueFromPgmData(uint8 param, const uint8* pgmData) {
    auto& info{ InfoForExposedParameters::get() };
    auto nybbleIndex{ info.firstNybbleIndexFor(param) };
    auto firstBitIndex{ info.firstBitIndexFor(param) };
    auto totalNumberOfBits{ info.totalNumberOfBitsNeededFor(param) };
    auto paramValue{ (uint8)0 };
    for (uint8 bitCounter = 0; bitCounter != totalNumberOfBits; ++bitCounter) {
        auto currentBit{ firstBitIndex + bitCounter };
        if (currentBit == 4 || currentBit == 8)
            ++nybbleIndex;
        currentBit %= 4;
        auto bitIsOn{ pgmData[nybbleIndex] & roundToInt(std::pow(2, currentBit)) };
        if (bitIsOn)
            paramValue += (uint8)roundToInt(std::pow(2, bitCounter));
    }
    return paramValue;
}