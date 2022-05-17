#pragma once

#include <JuceHeader.h>



struct SpecialValueOffsets
{
    static uint8 addWhenWritingToData(uint8 param, uint8 paramValue);
    static uint8 subtractWhenReadingFromData(uint8 param, uint8 paramValue);

private:
    static bool isClockTempoParameter(uint8 param);
    static bool isKnobAssignParameter(uint8 param);
};

