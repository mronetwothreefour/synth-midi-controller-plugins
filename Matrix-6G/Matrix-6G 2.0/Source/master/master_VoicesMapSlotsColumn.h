#pragma once

#include <JuceHeader.h>

#include "master_VoicesMapSlot.h"



class UnexposedParameters;

class VoicesMapSlotsColumn :
    public Component
{
    VoicesMapSlot slot_0;
    VoicesMapSlot slot_1;
    VoicesMapSlot slot_2;
    VoicesMapSlot slot_3;
    VoicesMapSlot slot_4;
    VoicesMapSlot slot_5;
    VoicesMapSlot slot_6;
    VoicesMapSlot slot_7;
    VoicesMapSlot slot_8;
    VoicesMapSlot slot_9;

public:
    VoicesMapSlotsColumn() = delete;

    VoicesMapSlotsColumn(UnexposedParameters* unexposedParams, uint8 firstProgramNumber);
    void resized() override;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesMapSlotsColumn)
};