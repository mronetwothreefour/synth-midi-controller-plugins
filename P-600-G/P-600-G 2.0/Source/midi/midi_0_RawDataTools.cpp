#include "midi_0_RawDataTools.h"

#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_VoiceTransmissionOptions.h"

using namespace P_600_G_Constants;

const std::vector<uint8> RawDataTools::convertHexStringToDataVector(const String& hexString) {
    std::vector<uint8> voiceData;
    for (auto i = 0; i != hexString.length(); i += 2) {
        auto hexValueString{ hexString.substring(i, i + 2) };
        voiceData.push_back((uint8)hexValueString.getHexValue32());
    }
    return voiceData;
}

const String RawDataTools::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
    auto hexString{ String::toHexString(dataVector.data(), (int)dataVector.size(), 0) };
    return hexString;
}

bool RawDataTools::isValidVoiceDataHexString(const String& hexString)
{
    auto isNotCorrectLength{ hexString.length() != VCS::indexOfFirstNameCharInVoiceDataHexString };
    if (isNotCorrectLength)
        return false;
    auto notAll_MS_bytesAre_0{ false };
    for (int indexOfMSByte = 0; indexOfMSByte < VCS::indexOfFirstNameCharInVoiceDataHexString; indexOfMSByte += 2) {
        if (hexString[indexOfMSByte] != '0') {
            notAll_MS_bytesAre_0 = true;
            break;
        }
    }
    if (notAll_MS_bytesAre_0)
        return false;
    return true;
}

void RawDataTools::applyRawVoiceDataToExposedParameters(
    const uint8* voiceData, ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions)
{
    auto info{ exposedParams->info.get() };
    transmitOptions->setParamChangesShouldBeTransmitted(false);
    for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
        auto paramID{ info->IDfor(paramIndex) };
        auto firstNybbleIndex{ info->firstNybbleIndexFor(paramIndex) };
        auto firstBitIndex{ info->firstBitIndexFor(paramIndex) };
        auto newValue{ (uint8)0 };
        if (paramID == ID::ep_17_FilterKeyTrack) {
            auto firstBitIsOn{ voiceData[firstNybbleIndex] & roundToInt(std::pow(2, firstBitIndex)) };
            if (firstBitIsOn)
                newValue = 2;
            auto secondBitIsOn{ voiceData[firstNybbleIndex] & roundToInt(std::pow(2, firstBitIndex + 1)) };
            if (secondBitIsOn)
                newValue = 1;
        }
        else {
            auto numberOfBits{ info->numberOfBitsFor(paramIndex) };
            for (uint8 bitCounter = 0; bitCounter != numberOfBits; ++bitCounter) {
                auto currentBit{ firstBitIndex + bitCounter };
                if (currentBit == 4 || currentBit == 8)
                    ++firstNybbleIndex;
                currentBit %= 4;
                auto bitIsOn{ voiceData[firstNybbleIndex] & roundToInt(std::pow(2, currentBit)) };
                if (bitIsOn)
                    newValue += (uint8)roundToInt(std::pow(2, bitCounter));
            }
        }
        auto paramPtr{ exposedParams->state->getParameter(paramID) };
        paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newValue));
    }
    transmitOptions->setParamChangesShouldBeTransmitted(true);
}

const std::vector<uint8> RawDataTools::extractRawVoiceDataFromExposedParameters(ExposedParameters* exposedParams) {
    const int rawVoiceDataSize{ 32 };
    std::vector<uint8> voiceData;
    for (auto i = 0; i != rawVoiceDataSize; ++i) {
        voiceData.push_back((uint8)0);
    }
    auto info{ exposedParams->info.get() };
    for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
        auto firstNybbleIndex{ info->firstNybbleIndexFor(paramIndex) };
        auto firstBitIndex{ info->firstBitIndexFor(paramIndex) };
        auto paramID{ info->IDfor(paramIndex) };
        auto paramPtr{ exposedParams->state->getParameter(paramID) };
        auto paramValue{ roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
        if (paramID == ID::ep_17_FilterKeyTrack) {
            if (paramValue == 1)
                voiceData[firstNybbleIndex] += 8;
            if (paramValue == 2)
                voiceData[firstNybbleIndex] += 4;
        }
        else {
            auto numberOfBits{ info->numberOfBitsFor(paramIndex) };
            for (uint8 bitCounter = 0; bitCounter != numberOfBits; ++bitCounter) {
                auto currentBit{ firstBitIndex + bitCounter };
                if (currentBit == 4 || currentBit == 8)
                    ++firstNybbleIndex;
                currentBit %= 4;
                auto bitIsOn{ paramValue & roundToInt(std::pow(2, bitCounter)) };
                if (bitIsOn)
                    voiceData[firstNybbleIndex] += (uint8)roundToInt(std::pow(2, currentBit));
            }
        }
    }
    return voiceData;
}

std::vector<uint8> RawDataTools::createRawDataVectorWithSequentialCircuitsSysExID() {
    std::vector<uint8> rawDataVector;
    rawDataVector.push_back(sequentialCircuits_ID);
    return rawDataVector;
}
