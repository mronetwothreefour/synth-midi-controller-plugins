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

std::vector<uint8> RawSysExDataVector::createRawDataVectorWithManufacturerIDheaderByte(int vectorSize) {
    jassert(vectorSize > 0);
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = MIDI::manufacturerID;
    return rawDataVector;
}




void RawDataTools::applyPgmDataVectorToGUI(const uint8 pgmNumber, std::vector<uint8>& pgmDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    applyPgmNumberToGUI(pgmNumber, unexposedParams);
    pgmDataVector.erase(pgmDataVector.begin(), pgmDataVector.begin() + 1);
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
        auto newValue{ extractParamValueFromPgmData(param, pgmData) };
        auto paramID{ info.IDfor(param) };
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
}

uint8 RawDataTools::extractParamValueFromPgmData(uint8 param, const uint8* pgmData) {
    auto& info{ InfoForExposedParameters::get() };
    auto nybbleIndex{ info.firstNybbleIndexFor(param) };
    auto firstBitIndex{ info.firstBitIndexFor(param) };
    auto totalNumberOfBits{ info.totalNumberOfBitsNeededFor(param) };
    auto paramValue{ (uint8)0 };
    if (info.IDfor(param).toString() == "filterKeyTrack") {
        auto firstBitIsOn{ pgmData[nybbleIndex] & roundToInt(std::pow(2, firstBitIndex)) };
        if (firstBitIsOn)
            paramValue = 2;
        auto secondBitIsOn{ pgmData[nybbleIndex] & roundToInt(std::pow(2, firstBitIndex + 1)) };
        if (secondBitIsOn)
            paramValue = 1;
    }
    else {
        for (uint8 bitCounter = 0; bitCounter != totalNumberOfBits; ++bitCounter) {
            auto currentBit{ firstBitIndex + bitCounter };
            if (currentBit == 4)
                ++nybbleIndex;
            if (currentBit == 8)
                ++nybbleIndex;
            currentBit %= 4;
            auto bitIsOn{ pgmData[nybbleIndex] & roundToInt(std::pow(2, currentBit)) };
            if (bitIsOn)
                paramValue += (uint8)roundToInt(std::pow(2, bitCounter));
        }
    }
    return paramValue;
}
