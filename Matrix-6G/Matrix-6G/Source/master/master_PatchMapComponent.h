#pragma once

#include <JuceHeader.h>

#include "master_PatchMapSlotsColumn.h"



class UnexposedParameters;

class PatchMapComponent :
    public Component
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingPatchMapComponent;
    TextButton button_ForResettingPatchMap;
    PatchMapSlotsColumn slotsColumn_0;
    PatchMapSlotsColumn slotsColumn_1;
    PatchMapSlotsColumn slotsColumn_2;
    PatchMapSlotsColumn slotsColumn_3;
    PatchMapSlotsColumn slotsColumn_4;
    PatchMapSlotsColumn slotsColumn_5;
    PatchMapSlotsColumn slotsColumn_6;
    PatchMapSlotsColumn slotsColumn_7;
    PatchMapSlotsColumn slotsColumn_8;
    PatchMapSlotsColumn slotsColumn_9;

public:
    PatchMapComponent() = delete;

    explicit PatchMapComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;

private:
    void hideThisComponent();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchMapComponent)
};