#pragma once

#include <JuceHeader.h>

#include "../core_PluginProcessor.h"
#include "../helpers/helper_Identifiers.h"
#include "banks_PluginProgramBanks_Singleton.h"



class ProgramSlotsWidget : public Component
{
    ToggleButton programSlotButtons[128];
    uint8 bank;
    PluginProcessor& processor;
    int buttton_w;
    int buttton_h;
    int buttonGap;

public:
    uint8 selectedSlot;

    explicit ProgramSlotsWidget(uint8 bank, PluginProcessor& processor);
    ~ProgramSlotsWidget();

    void resized() override;
    void setTextForProgramSlotToggleButton(uint8 slot);
    void loadProgramFromSelectedSlot();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};

