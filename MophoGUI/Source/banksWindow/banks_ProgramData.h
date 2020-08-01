#pragma once

#include <JuceHeader.h>

#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_SpecialValueOffsets.h"
#include "../parameters/params_UnexposedParameters.h"



struct ProgramData {
    static void applyToExposedParameters(const uint8* dumpData, AudioProcessorValueTreeState* exposedParams) {
        auto& midiParams{ MidiParameters_Singleton::get() };
        midiParams.setParamChangeEchosAreBlocked();
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
        midiParams.setParamChangeEchosAreNotBlocked();
    }
};