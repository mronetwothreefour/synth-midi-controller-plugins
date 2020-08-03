#pragma once

#include <JuceHeader.h>

#include "../core_PluginProcessor.h"
#include "../helpers/helper_Identifiers.h"
#include "banks_PluginProgramBanks_Singleton.h"
#include "banks_ProgramNameStrings_Singleton.h"



class ProgramSlotsWidget : 
    public Component,
    private Timer
{
    ToggleButton programSlotButtons[128];
    uint8 bank;
    AudioProcessorValueTreeState* exposedParams;
    int buttton_w;
    int buttton_h;
    int buttonHorizontalGap;

    void timerCallback() override;

public:
    uint8 selectedSlot;

    explicit ProgramSlotsWidget(uint8 bank, AudioProcessorValueTreeState* exposedParams);
    ~ProgramSlotsWidget();

    void resized() override;
    void setTextForProgramSlotToggleButton(uint8 slot);
    void loadProgramFromSelectedSlot();
    void storeCurrentProgramSettingsInSelectedSlot();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};

