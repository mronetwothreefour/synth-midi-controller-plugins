#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanks.h"



class UnexposedParameters;

class ProgramSlotsWidget :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton programSlotButtons[128];
    const ProgramBank bank;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    const int buttton_w;
    const int buttton_h;
    const int buttonHorizontalGap;

public:
    uint8 selectedSlot;

    ProgramSlotsWidget() = delete;

    ProgramSlotsWidget(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void setUpProgramSlotToggleButton(uint8 slot);
    void setTooltipForProgramSlotToggleButton(uint8 slot);
    void setTextForProgramSlotToggleButton(uint8 slot);
    void storeCurrentProgramSettingsInSelectedSlot();
    void loadProgramFromSelectedSlot();
    void pullSelectedProgramFromHardware();
    void pushSelectedProgramToHardware();
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~ProgramSlotsWidget();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};

