#include "params_SpecialValueOffsets.h"



uint8 SpecialValueOffsets::addWhenWritingToData(uint8 param, uint8 paramValue) {
    if (isClockTempoParameter(param))
        return paramValue + 30;
    else if (isKnobAssignParameter(param) && paramValue > 104)
        return paramValue + 15;
    else
        return paramValue;
}

uint8 SpecialValueOffsets::subtractWhenReadingFromData(uint8 param, uint8 paramValue) {
    if (isClockTempoParameter(param))
        return paramValue - 30;
    else if (isKnobAssignParameter(param) && paramValue > 119)
        return paramValue - 15;
    else
        return paramValue;
}

bool SpecialValueOffsets::isClockTempoParameter(uint8 param) {
    return param == 95;
}

bool SpecialValueOffsets::isKnobAssignParameter(uint8 param) {
    return param > 104 && param < 109;
}
