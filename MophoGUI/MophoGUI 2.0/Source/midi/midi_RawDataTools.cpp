#include "midi_RawDataTools.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_SpecialValueOffsets.h"
#include "../params/params_UnexposedParameters_Facade.h"



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

void RawDataTools::applyToExposedParameters(const uint8* dumpData, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto midiOptions{ unexposedParams->midiOptions_get() };
    midiOptions->setParamChangeEchoesAreBlocked();
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
        auto paramID{ info.IDfor(param) };
        auto lsByteLocation{ info.lsByteLocationFor(param) };
        auto msBitLocation{ info.msBitPackedByteLocationFor(param) };
        auto msBitMask{ info.msBitMaskFor(param) };
        auto newValue{ *(dumpData + lsByteLocation) };
        if (*(dumpData + msBitLocation) & msBitMask)
            newValue += 128;
        newValue = SpecialValueOffsets::subtractWhenReadingFromData(param, newValue);
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
    midiOptions->setParamChangeEchoesAreNotBlocked();
}

const std::vector<uint8> RawDataTools::extractFromExposedParameters(AudioProcessorValueTreeState* exposedParams) {
    std::vector<uint8> voiceData;
    for (auto i = 0; i != rawVoiceDataSize; ++i) {
        voiceData.push_back((uint8)0);
    }
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        auto param{ exposedParams->getParameter(paramID) };
        auto paramValue{ uint8(param->getValue() * info.maxValueFor(paramIndex)) };
        paramValue = SpecialValueOffsets::addWhenWritingToData(paramIndex, paramValue);
        auto msbLocation{ info.msBitPackedByteLocationFor(paramIndex) };
        auto lsbLocation{ info.lsByteLocationFor(paramIndex) };
        if (paramValue > 127) {
            voiceData[msbLocation] += info.msBitMaskFor(paramIndex);
        }
        voiceData[lsbLocation] = paramValue % 128;
    }
    return voiceData;
}
