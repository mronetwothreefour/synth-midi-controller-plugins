#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "banks_PluginProgramBanks_Singleton.h"



class ProgramSlotsWidget : public Component
{
    ToggleButton programSlotButtons[128];
    uint8 bank;
    int buttton_w;
    int buttton_h;
    int buttonGap;

public:
    int selectedSlot;

    explicit ProgramSlotsWidget(uint8 bank);
    ~ProgramSlotsWidget();

    void resized() override;
    void setTextForProgramSlotToggleButton(uint8 slot);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};

