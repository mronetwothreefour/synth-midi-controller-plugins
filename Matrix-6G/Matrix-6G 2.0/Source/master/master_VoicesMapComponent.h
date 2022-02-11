#pragma once

#include <JuceHeader.h>

#include "master_VoicesMapSlotsColumn.h"



class UnexposedParameters;

class VoicesMapComponent :
    public Component
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingVoicesMapComponent;
    TextButton button_ForResettingVoicesMap;
    VoicesMapSlotsColumn slotsColumn_0;
    VoicesMapSlotsColumn slotsColumn_1;
    VoicesMapSlotsColumn slotsColumn_2;
    VoicesMapSlotsColumn slotsColumn_3;
    VoicesMapSlotsColumn slotsColumn_4;
    VoicesMapSlotsColumn slotsColumn_5;
    VoicesMapSlotsColumn slotsColumn_6;
    VoicesMapSlotsColumn slotsColumn_7;
    VoicesMapSlotsColumn slotsColumn_8;
    VoicesMapSlotsColumn slotsColumn_9;

public:
    VoicesMapComponent() = delete;

    explicit VoicesMapComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;

private:
    void hideThisComponent();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesMapComponent)
};