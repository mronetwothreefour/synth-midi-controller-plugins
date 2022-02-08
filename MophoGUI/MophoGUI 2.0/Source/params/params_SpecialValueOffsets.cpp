#include "params_SpecialValueOffsets.h"

#include "params_Constants.h"

using namespace constants;



uint8 SpecialValueOffsets::addWhenWritingToData(uint8 param, uint8 paramValue) {
    if (isClockTempoParameter(param))
        return paramValue + mophoParams::clockTempoOffset;
    else if (isKnobAssignParameter(param) && paramValue > 104)
        return paramValue + mophoParams::knobAssignOffset;
    else
        return paramValue;
}

uint8 SpecialValueOffsets::subtractWhenReadingFromData(uint8 param, uint8 paramValue) {
    if (isClockTempoParameter(param))
        return paramValue - mophoParams::clockTempoOffset;
    else if (isKnobAssignParameter(param) && paramValue > 119)
        return paramValue - mophoParams::knobAssignOffset;
    else
        return paramValue;
}

bool SpecialValueOffsets::isClockTempoParameter(uint8 param) {
    return param == mophoParams::clockTempoIndex;
}

bool SpecialValueOffsets::isKnobAssignParameter(uint8 param) {
    return param >= mophoParams::knobAssignFirstIndex && param <= mophoParams::knobAssignLastIndex;
}
