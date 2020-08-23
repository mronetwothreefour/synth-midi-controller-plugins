#include "params_RawProgramData.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "params_SpecialValueOffsets.h"
#include "params_UnexposedParameters_Facade.h"



void RawProgramData::applyToExposedParameters(const uint8* dumpData, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    auto midiOptions{ unexposedParams->midiOptions_get() };
    midiOptions->setParamChangeEchosAreBlocked();
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
    midiOptions->setParamChangeEchosAreNotBlocked();
}

const std::vector<uint8> RawProgramData::extractFromExposedParameters(AudioProcessorValueTreeState* exposedParams) {
    std::vector<uint8> programData;
    for (auto i = 0; i != rawProgramDataSize; ++i) {
        programData.push_back((uint8)0);
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
            programData[msbLocation] += info.msBitMaskFor(paramIndex);
        }
        programData[lsbLocation] = paramValue % 128;
    }
    return programData;
}