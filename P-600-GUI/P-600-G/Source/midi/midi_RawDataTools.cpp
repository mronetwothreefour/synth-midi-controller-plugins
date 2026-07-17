#include "midi_RawDataTools.h"

#include "midi_Constants.h"
#include "../voices/voices_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;
using namespace ID;



std::vector<uint8> RawSysExDataVector::createVoiceDataRequestMessage(uint8 slot)
{
    jassert(slot < voices::numberOfSlotsInVoicesBank);
    auto rawDataVector{ createRawDataVectorWithManufacturerIDheaderByte(MIDI::sizeOfVoiceDataRequestVector) };
    rawDataVector[1] = MIDI::opcode_RequestVoiceData;
    rawDataVector[2] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::initializeVoiceDataMessage(uint8 slot) {
    jassert(slot < voices::numberOfSlotsInVoicesBank);
    auto rawDataVector{ createRawDataVectorWithManufacturerIDheaderByte(MIDI::sizeOfVoiceDataMessageVector) };
    rawDataVector[1] = MIDI::opcode_VoiceDataMessage;
    rawDataVector[2] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createVoiceDataMessageHeader(uint8 slot) {
    jassert(slot < voices::numberOfSlotsInVoicesBank);
    auto rawDataVector{ createRawDataVectorWithManufacturerIDheaderByte(MIDI::numberOfHeaderBytesInVoiceDataMessage) };
    rawDataVector[1] = MIDI::opcode_VoiceDataMessage;
    rawDataVector[2] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createRawDataVectorWithManufacturerIDheaderByte(int vectorSize) {
    jassert(vectorSize > 0);
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = MIDI::manufacturerID;
    return rawDataVector;
}




const String RawDataTools::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
    auto hexString{ String::toHexString(dataVector.data(), (int)dataVector.size(), 0) };
    return hexString;
}

const std::vector<uint8> RawDataTools::convertHexStringToDataVector(const String& hexString) {
    std::vector<uint8> dataVector;
    for (auto i = 0; i < voices::indexOfFirstNameCharInVoiceDataHexString; i += 2) {
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

bool RawDataTools::isValidVoiceDataHexString(const String& hexString) {
    auto isNotLongEnough{ hexString.length() < voices::lengthOfVoiceDataHexString };
    if (isNotLongEnough)
        return false;
    for (int indexOfMSByte = 0; indexOfMSByte < voices::lengthOfVoiceDataHexString; indexOfMSByte += 2) {
        if (hexString[indexOfMSByte] != '0')
            return false;
    }
    return true;
}

void RawDataTools::insertFilterKeyTrackValueIntoDataVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector) {
    auto& info{ InfoForExposedParameters::get() };
    auto filterKeyTrackParam{ info.indexForParamID("filterKeyTrack") };
    auto nybbleIndex{ MIDI::numberOfHeaderBytesInVoiceDataMessage + info.firstNybbleIndexFor(filterKeyTrackParam) };
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
    auto nybbleIndex{ MIDI::numberOfHeaderBytesInVoiceDataMessage + info.firstNybbleIndexFor(paramIndex) };
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

void RawDataTools::applyVoiceDataVectorToGUI(const uint8 voiceNumber, std::vector<uint8>& voiceDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    applyVoiceNumberToGUI(voiceNumber, unexposedParams);
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
    applyRawVoiceDataToExposedParameters(voiceDataVector.data(), exposedParams);
    voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

void RawDataTools::applyVoiceNumberToGUI(const uint8 voiceNumber, UnexposedParameters* unexposedParams) {
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    voiceTransmissionOptions->setCurrentVoiceNumber(voiceNumber);
}

void RawDataTools::applyRawVoiceDataToExposedParameters(const uint8* voiceData, AudioProcessorValueTreeState* exposedParams) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
        auto paramID{ info.IDfor(param) };
        uint8 newValue{ (uint8)0 };
        if (info.IDfor(param).toString() == "filterKeyTrack")
            newValue = extractFilterKeyTrackValueFromRawVoiceData(voiceData);
        else
            newValue = extractParamValueFromRawVoiceData(param, voiceData);
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
}

uint8 RawDataTools::extractFilterKeyTrackValueFromRawVoiceData(const uint8* voiceData) {
    auto& info{ InfoForExposedParameters::get() };
    auto filterKeyTrackParam{ info.indexForParamID("filterKeyTrack") };
    auto nybbleIndex{ info.firstNybbleIndexFor(filterKeyTrackParam) };
    auto firstBitIndex{ info.firstBitIndexFor(filterKeyTrackParam) };
    auto filterKeyTrackValue{ (uint8)0 };
    auto firstBitIsOn{ voiceData[nybbleIndex] & roundToInt(std::pow(2, firstBitIndex)) };
    if (firstBitIsOn)
        filterKeyTrackValue = 2;
    auto secondBitIsOn{ voiceData[nybbleIndex] & roundToInt(std::pow(2, firstBitIndex + 1)) };
    if (secondBitIsOn)
        filterKeyTrackValue = 1;
    return filterKeyTrackValue;
}

uint8 RawDataTools::extractParamValueFromRawVoiceData(uint8 param, const uint8* voiceData) {
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
        auto bitIsOn{ voiceData[nybbleIndex] & roundToInt(std::pow(2, currentBit)) };
        if (bitIsOn)
            paramValue += (uint8)roundToInt(std::pow(2, bitCounter));
    }
    return paramValue;
}
