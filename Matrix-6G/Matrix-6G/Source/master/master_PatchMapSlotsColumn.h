#pragma once

#include <JuceHeader.h>

#include "master_PatchMapSlot.h"



class UnexposedParameters;

class PatchMapSlotsColumn :
    public Component
{
    PatchMapSlot slot_0;
    PatchMapSlot slot_1;
    PatchMapSlot slot_2;
    PatchMapSlot slot_3;
    PatchMapSlot slot_4;
    PatchMapSlot slot_5;
    PatchMapSlot slot_6;
    PatchMapSlot slot_7;
    PatchMapSlot slot_8;
    PatchMapSlot slot_9;

public:
    PatchMapSlotsColumn() = delete;

    PatchMapSlotsColumn(UnexposedParameters* unexposedParams, uint8 firstProgramNumber);
    void resized() override;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchMapSlotsColumn)
};