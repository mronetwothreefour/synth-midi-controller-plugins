#pragma once

#include <JuceHeader.h>



struct SpecialValueOffsets
{
    static uint8 addWhenWritingToData(uint8 param, uint8 paramValue) {
        if (isClockTempoParameter(param))
            return paramValue + 30;
        else if (isKnobAssignParameter(param) && paramValue > 104)
            return paramValue + 15;
        else
            return paramValue;
    }

    static uint8 subtractWhenReadingFromData(uint8 param, uint8 paramValue) {
        if (isClockTempoParameter(param))
            return paramValue - 30;
        else if (isKnobAssignParameter(param) && paramValue > 119)
            return paramValue - 15;
        else
            return paramValue;
    }

private:
    static bool isClockTempoParameter(uint8 param) {
        return param == 95;
    }

    static bool isKnobAssignParameter(uint8 param) {
        return param > 104 && param < 109;
    }
};

